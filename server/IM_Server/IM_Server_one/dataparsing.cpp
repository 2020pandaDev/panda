#include "dataparsing.h"

Dataparsing::Dataparsing(QObject *parent) : QObject(parent)
{

}

QJsonDocument Dataparsing::createJsonDo(QMap<QString, QVariant> str)//创建json
{
   QJsonDocument jsonDoc = QJsonDocument::fromVariant(QVariant(str));
   return jsonDoc;
}

QJsonDocument Dataparsing::tranQBytearrttoJonsDo(const QByteArray byte)
{

   QJsonParseError jsonpe;
   QJsonDocument jsonDocument = QJsonDocument::fromJson(byte,&jsonpe);

   if(jsonpe.error == QJsonParseError::NoError){
       qDebug()<<"QJsonParseError::NoError";
       if (!(jsonDocument.isNull() || jsonDocument.isEmpty())) {
           return jsonDocument;
       }
   }
   return jsonDocument;
}

QVariantMap Dataparsing::parseJons(const QJsonDocument jsonDoc)//解析接受的json
{
    QJsonObject jsonObject = jsonDoc.object();
    return jsonObject.toVariantMap();
}

QString Dataparsing::tranJonstoStr(const QJsonDocument jsonDoc)//json转string
{
    return QString(jsonDoc.toJson());
}

QByteArray Dataparsing::paserMapData(QMap<QString,QVariant>&str)
{
    QJsonDocument jsonDocSend = createJsonDo(str);
    QString strSend = tranJonstoStr(jsonDocSend);
    QByteArray by_array = strSend.toLatin1().data();

    if(jsonDocSend.isEmpty() && by_array.isEmpty())
        //return;
    qDebug()<<"by_array :";
    return by_array;
    //emit sendBytInfo(by_array);
}

QVariantMap Dataparsing::paserByteData(QByteArray returnData)
{
    QJsonDocument jsonDoc = tranQBytearrttoJonsDo(returnData);
    QVariantMap Map_info = parseJons(jsonDoc);

    if(jsonDoc.isEmpty() && Map_info.isEmpty())
         //return ;
    qDebug()<<"Map_info :";
    return Map_info;
    //emit sendMapInfo(Map_info);
}
