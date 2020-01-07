#include "dataparsing.h"

Dataparsing::Dataparsing(QObject *parent) : QObject(parent)
{

}

QJsonDocument Dataparsing::createJsonDo(QMap<QString, QVariant> str)//创建json
{
   QJsonDocument jsonDoc = QJsonDocument::fromVariant(QVariant(str));
   return jsonDoc;
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

void Dataparsing::getPreServerData(QByteArray returnData)
{
        if(returnData.isEmpty()){
            return ;
        }
        QJsonDocument jsonDoc = tranQBytearrttoJonsDo(returnData);//接受数据转为json
        QVariantMap preInfo = parseJons(jsonDoc);
        qDebug()<<"preInfo :"<<preInfo;
        emit sendPreInfo(preInfo);
}

QJsonDocument Dataparsing::tranQBytearrttoJonsDo(const QByteArray byte)
{

   QJsonParseError jsonpe;
   QJsonDocument jsonDocument = QJsonDocument::fromJson(byte,&jsonpe);
//   QJsonDocument jsonDocument = QJsonDocument::fromJson(byte.toUtf8(),&jsonpe);

   if(jsonpe.error == QJsonParseError::NoError){
       qDebug()<<"QJsonParseError::NoError";
       if (!(jsonDocument.isNull() || jsonDocument.isEmpty())) {
           return jsonDocument;
       }
   }
   return jsonDocument;
}

//void Dataparsing::sendAndRece( QString key,  QString netState)
//{
//    QMap<QString,QVariant>str = getSendStr(key,netState);//存储key,id，netstate,mac
//    qDebug()<<"getSendStr:  "<<str;
//    QJsonDocument jsonDocSend = createJsonDo(str);//数据转为json
//    QString strSend = tranJonstoStr(jsonDocSend);//json 数据转string
//    qDebug()<<" json strSends :"<<strSend;
//}

void Dataparsing::sendAndRece(QMap<QString,QVariant>&str)
{
    QJsonDocument jsonDocSend = createJsonDo(str);//数据转为json
    QString strSend = tranJonstoStr(jsonDocSend);//json数据转string
    qDebug()<<"sendAndRece"<<strSend;
}

void Dataparsing::getServerData(QByteArray returnData)
{
         QJsonDocument jsonDoc = tranQBytearrttoJonsDo(returnData);//接受数据转为json
         if(jsonDoc.isEmpty())
             return;
         QVariantMap info = parseJons(jsonDoc);
         qDebug()<<"info :";
         emit sendInfo(info);
}
