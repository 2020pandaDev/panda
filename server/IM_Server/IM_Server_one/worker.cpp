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
    QString username = registerInfo.at(0);
    QString password = registerInfo.at(1);

    MySql *sql =new MySql("user.db","QSQLITE","todb");

    QMap<QString ,QString> userinfo;
    userinfo.insert("user_name",username);
    userinfo.insert("user_password",password);


    if(sql->MySelect(userinfo)){
        userinfo.insert("user_id","0");
        userinfo.insert("user_ip","100.22.11.11");
        userinfo.insert("user_port","4455");
        userinfo.insert("user_online","online");
        userinfo.insert("user_link","notlink");
        userinfo.insert("user_Verification","notlink");
        sql->MyInsert(userinfo);
        qDebug()<<" insert success";
    }
    else {
        qDebug()<<"fail";
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


void Worker::loginIn(QStringList &userInfoList)
{
    qDebug()<<"进入登录";

    QString u_name=userInfoList.at(0);
    QString u_pwd=userInfoList.at(1);
    qDebug()<<u_name<<"  "<<u_pwd;

    MySql *mysql = new MySql("user.db","QSQLITE","t_user");
    mysql->createTable();
    QList<QStringList> userInfo = mysql->selectDataFromBase(userinfo); //获取整张表的数据
   //获取表中user_name字段
    for (int i = 0;i < userInfo.size();i++) {
        qDebug()<<userInfo[i];
        for (int j = 0;j < userInfo[i].size();j++) {
            qDebug()<<userInfo[i][j];
            if(QString::compare(u_name,userInfo[i][j]) == 0)  //判断用户名是否在user_name字段中
            {
                if(mysql->loguser(u_name,u_pwd))//判断密码是否一致
                {
                    QMessageBox msg;
                    msg.setToolTip("登录成功");
                } else {
                    QMessageBox msg;
                    msg.setToolTip("密码错误");
                }

            } else {
                QMessageBox msg;
                msg.setToolTip("用户名不存在");
}
        }
    }

//    QString sql = QString("update t_user set user_ip=%1 where user_name='%2'")
//            .arg("参数1",u_name); //在数据库中更新IP
//    QSqlQuery querySet;
//    querySet.exec(sql);
}


