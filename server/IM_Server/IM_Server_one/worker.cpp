#include "worker.h"
#include <mysql.h>
#include <QMap>
#include <QMessageBox>
#include "serverthread.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::dowork()
{
    qDebug()<<" dpwork";
    qDebug()<<"work thread:"<<QThread::currentThreadId();
}

void Worker::registe(QStringList &registerInfo)
{
    QString username=registerInfo.at(0);
    QString password=registerInfo.at(1);

    MySql sql("user.db","QSQLITE","todb");
    if (!sql.CreateConnection())
    {
        qDebug() << "数据库连接失败!";

    }

    QMap<QString ,QString> userinfo;
    userinfo.insert("user_name",username);
    userinfo.insert("user_password",password);

    if(sql.MySelect(userinfo)){
        userinfo.insert("user_id","0");
        userinfo.insert("user_ip","100.22.11.11");
        userinfo.insert("user_port","4455");
        userinfo.insert("user_online","online");
        userinfo.insert("user_link","notlink");
        userinfo.insert("user_Verification","notlink");
        sql.MyInsert(userinfo);

        QMessageBox msg;
        msg.setToolTip("注册成功");
    }
    else {
        QMessageBox msg;
        msg.setToolTip("已注册");

    }
}

void Worker::privateChat(QVariantMap& chatMessage)
{
    QString userName= chatMessage["userName"].toString();
    QByteArray message= chatMessage["Msg"].toString().toLatin1().data();
    QTcpSocket* socket = ServerThread::userSocket["recvUsrName"];
    socket->write(message);

}

void Worker::doingCAPTCHA(QStringList &CAPTCHAInfo)
{
    QString username=CAPTCHAInfo.at(0);
    QString captcha=CAPTCHAInfo.at(1);

    qDebug() << "一个!";
    MySql sql("user.db","QSQLITE","todb");
    if (!sql.CreateConnection())
    {
        qDebug() << "数据库连接失败!";

    }

    QMap<QString ,QString> userinfo;
    userinfo.insert("user_name",username);
    userinfo.insert("user_verification",captcha);

    if(sql.MySelect(userinfo)){
        qDebug() << "有用户请求帮助!";
        userVerification.insert("user_name",username);
        userVerification.insert("user_verification",captcha);

        sql.MyUpdateVerification(userVerification);
        QMessageBox msg;
        msg.setToolTip("有用户请求帮助");
    }
    else {
        qDebug() << "用户请求失败!";
        QMessageBox msg;
        msg.setToolTip("用户请求失败");

    }
}

