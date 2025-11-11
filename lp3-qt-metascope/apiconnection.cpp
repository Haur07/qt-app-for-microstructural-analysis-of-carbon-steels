#include <cmath>
#include "apiconnection.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QHttpMultiPart>
#include <QBuffer>
#include <QTimer>

APIConnection::APIConnection(QObject *parent)
    : QObject(parent)
    , nam_(new QNetworkAccessManager(this)) {}

QByteArray APIConnection::pixmapToPng(const QPixmap &pix)
{
    QByteArray byte_array;
    QBuffer buffer(&byte_array);
    buffer.open(QIODevice::WriteOnly);
    pix.save(&buffer, "PNG");
    return byte_array;
}

double APIConnection::headerToDouble(QNetworkReply *reply, const QByteArray &key)
{
    QByteArray value = reply->rawHeader(key);
    if (value.isEmpty()) { value = reply->rawHeader(key.toLower()); }
    if (value.isEmpty()) { value = reply->rawHeader(key.toUpper()); }
    bool ok = false;
    double v = value.trimmed().toDouble(&ok);
    return ok ? v : qQNaN();
}

void APIConnection::predict(const QPixmap &pix)
{
    if (!endpoint_.isValid() || endpoint_.isEmpty())
    {
        emit networkError("Invalid endpoint. Call setEndpoint(QUrl).");
        return;
    }
    if (pix.isNull())
    {
        emit networkError("No image loaded for sending.");
        return;
    }
    if (pending_reply_)
    {
        emit networkError("There's ongoing request.");
        return;
    }

    auto *multi = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart filePart;
    filePart.setHeader(QNetworkRequest::ContentDispositionHeader,
                       QVariant("form-data; name=\"file\"; filename=\"image.png\""));
    filePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));

    QByteArray png = pixmapToPng(pix);
    auto *fileBuf = new QBuffer;
    fileBuf->setData(png);
    fileBuf->open(QIODevice::ReadOnly);
    filePart.setBodyDevice(fileBuf);
    fileBuf->setParent(multi);

    multi->append(filePart);

    QNetworkRequest request(endpoint_);
    request.setHeader(QNetworkRequest::UserAgentHeader, "QtClient/1.0");

    pending_reply_ = nam_->post(request, multi);
    multi->setParent(pending_reply_);

    connect(pending_reply_, &QNetworkReply::finished, this, &APIConnection::onFinished);
    connect(pending_reply_, &QNetworkReply::errorOccurred, this, &APIConnection::onError);

    QTimer::singleShot(timeout_ms_, this, [this]()
    {
        if (pending_reply_ && !pending_reply_->isFinished())
        {
            pending_reply_->abort();
            emit networkError("Timeout limit reached.");
        }
    });
}

void APIConnection::onFinished()
{
    if (!pending_reply_) { return; }

    QNetworkReply *reply = pending_reply_;
    pending_reply_ = nullptr;

    if (reply->error() != QNetworkReply::NoError)
    {
        reply->deleteLater();
        return;
    }

    const QByteArray body = reply->readAll();
    QImage mask;
    mask.loadFromData(body, "PNG");
    if (mask.isNull())
    {
        emit networkError("Invalid or empty mask received.");
        return;
    }

    double ferrite = headerToDouble(reply, "ferrite");
    double pearlite = headerToDouble(reply, "pearlite");
    if (std::isnan(ferrite) || std::isnan(pearlite))
    {
        emit networkError("Invalid or empty 'ferrite' or 'pearlite' headers.");
        reply->deleteLater();
        return;
    }

    reply->deleteLater();
    emit predictionFinished(mask, ferrite, pearlite);
}

void APIConnection::onError(QNetworkReply::NetworkError)
{
    if (!pending_reply_) { return; }
    QNetworkReply *reply = pending_reply_;
    const QString msg = reply->errorString();
    pending_reply_ = nullptr;
    reply->deleteLater();
    emit networkError(QString("Network error: %1").arg(msg));
}
