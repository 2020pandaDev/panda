#ifndef DATAPARSING_H
#define DATAPARSING_H

#include <QObject>
#include <QDebug>
#include <QJsonDocument>
#include <QVariantMap>
#include <QJsonObject>

class Dataparsing : public QObject
{
    Q_OBJECT
public:
    explicit Dataparsing(QObject *parent = nullptr);
    QJsonDocument createJsonDo(QMap<QString, QVariant>);//创建json

    QJsonDocument tranQBytearrttoJonsDo(const QByteArray byte);
    QVariantMap parseJons(const QJsonDocument jsonDoc);//解析Json
    QString tranJonstoStr(const QJsonDocument jsonDoc);//json转string
    void sendAndRece(QString key, QString netState);//发送接受
    void sendAndRece(QMap<QString,QVariant>&str);

    QMap<QString, QVariant> getSendStr(const QString key,const QString netState);//获取发送数据
    QMap<QString, QVariant> getSendStr();

signals:
    void sendBytInfo(QByteArray BytInfo);
    void sendMapInfo(QVariantMap Mapinfo);

public slots:
    void getServerData(QByteArray returnData);//emit  info
    void getPreServerData(QMap<QString,QVariant>&str);//emit  prinfo
};

#endif // DATAPARSING_H

