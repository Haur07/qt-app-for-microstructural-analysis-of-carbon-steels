#ifndef APICONNECTION_H
#define APICONNECTION_H

#include <QObject>
#include <QImage>
#include <QPixmap>
#include <QtNetwork/QNetworkReply>
#include <QUrl>

class APIConnection : public QObject
{
    Q_OBJECT

public:
    explicit APIConnection(QObject *parent = nullptr);

    void setEndpoint(const QUrl &url) { endpoint_ = url; }
    QUrl endpoint() const { return endpoint_; }
    void setTimeoutMs(int t) { timeout_ms_ = t; }
    void predict(const QPixmap &pix);

signals:
    void predictionFinished(const QImage &mask, double ferrite, double pearlite);
    void networkError(const QString &message);

private slots:
    void onFinished();
    void onError(QNetworkReply::NetworkError code);

private:
    static QByteArray pixmapToPng(const QPixmap &pix);
    static double headerToDouble(QNetworkReply *reply, const QByteArray &key);

private:
    QNetworkAccessManager *nam_;
    QNetworkReply *pending_reply_ = nullptr;
    QUrl endpoint_;
    int timeout_ms_ = 60000;
};
#endif // APICONNECTION_H
