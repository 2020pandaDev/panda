#include "worker.h"
#include <mysql.h>
#include <QMap>
#include <QMessageBox>
#include "serverthread.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    m_dataParse = new Dataparsing ();
}

void Worker::dowork(QByteArray& message)
{
    qDebug()<<" dpwork";
    qDebug()<<"work thread:"<<QThread::currentThreadId();
    QByteArray recMessage =message;
    QVariantMap recValue  = m_dataParse->paserByteData(recMessage);

    int  messType = recValue["Type"].toInt();
    switch (messType) {
    case 1:


    break;
    case 2://注册
    {
        QString    registeusrName = recValue["usrName"].toString();
        QString    registepassword = recValue["password"].toString();

        QStringList registeinfo;
        registeinfo.append(registeusrName);
        registeinfo.append(registepassword);
        m_returnDataToClient =registe(registeinfo);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        sendReturnData(m_sendData);
    break;
    }
    case 3://登录
    {

        QString loginInusrName = recValue["usrName"].toString();
        QString loginInpassword = recValue["password"].toString();
        QStringList loginIninfo;
        loginIninfo.append(loginInusrName);
        loginIninfo.append(loginInpassword);

        emit insertSocket(loginInusrName);
        m_returnDataToClient =loginIn(loginIninfo);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        sendReturnData(m_sendData);
    break;
    }

    case 4://私聊
    {
        privateChat(recValue);
        break;
    }



    case 5:{
        QString    usrName = recValue["usrName"].toString();
        QString    captcha = recValue["captcha"].toString();
        QStringList helpIninfo;

        helpIninfo.append(usrName);
        helpIninfo.append(captcha);
        m_returnDataToClient =doingCAPTCHA(helpIninfo);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        sendReturnData(m_sendData);
          break;
    }



    default:
         break;
    }
}

void Worker::registe(QStringList &registerInfo)
{
    QString username=registerInfo.at(0);
    QString password=registerInfo.at(1);

    QMap<QString ,QString> userinfo;
    userinfo.insert("user_name","bella");
    userinfo.insert("user_password",password);

    QVariantMap responMessage;

    if(MySql::getInstance()->MySelect(userinfo)){
        userinfo.insert("user_id","1");
        userinfo.insert("user_ip","100.22.11.11");
        userinfo.insert("user_port","4455");
        userinfo.insert("user_online","online");
        userinfo.insert("user_link","notlink");
        userinfo.insert("user_Verification","notlink");
        MySql::getInstance()->MyInsert(userinfo);
        qDebug()<< "registe sucess";

        responMessage.insert("type","1");
        responMessage.insert("message","register success");
        return responMessage;
    }

    else {
        responMessage.insert("type","1");
        responMessage.insert("message","register fail");
        return responMessage ;

    }
}

void Worker::privateChat(QVariantMap& chatMessage)
{
    qDebug()<< "privateChat fun ";
    QVariantMap returnData;

    QString sendUsrName = chatMessage["sendUsrName"].toString();
    QString recvUsrName = chatMessage["recvUsrName"].toString();
    QString Msg = chatMessage["Msg"].toString();
    int msgType = chatMessage["msgType"].toInt();
    QByteArray message= Msg.toLatin1().data();
    QTcpSocket* socket = ServerThread::userSocket["recvUsrName"];
    returnData.insert("Type",4);
    returnData.insert("sendUsrName",sendUsrName);
    returnData.insert("recvUsrName",recvUsrName);
    returnData.insert("Msg",Msg);
    returnData.insert("msgType",0);
    m_sendData= m_dataParse->paserMapData(returnData);
    socket->write(m_sendData);

}

void Worker::createTable()
{

    qDebug()<< "mysql :"<< MySql::getInstance();
    MySql::getInstance()->CreateConnection();

}


void Worker::doingCAPTCHA(QStringList &CAPTCHAInfo)
{
    QString username=CAPTCHAInfo.at(0);
    QString captcha=CAPTCHAInfo.at(1);

    if (MySql::getInstance()->CreateConnection())
    {
        qDebug() << "数据库连接失败!";

    }

    QMap<QString ,QString> userinfo;
    userinfo.insert("user_name",username);
    userinfo.insert("user_verification",captcha);

    if(MySql::getInstance()->MySelect(userinfo)){
        qDebug() << "有用户请求帮助!";
        userVerification.insert("user_name",username);
        userVerification.insert("user_verification",captcha);

        MySql::getInstance()->MyUpdateVerification(userVerification);

    }
    else {
        qDebug() << "用户请求失败!";

    }


}

void Worker::sendReturnData(QByteArray & returnData)
{
    emit sendInfo(returnData);
}

void Worker::loginIn(QStringList &userInfoList)
{
    QString u_name=userInfoList.at(0);
    QString u_pwd=userInfoList.at(1);
    MySql::getInstance()->createTable();
    QList<QStringList> userInfo = MySql::getInstance()->selectDataFromBase(userinfo); //获取整张表的数据
   //获取表中user_name字段
    for (int i = 0;i < userInfo.size();i++) {
        qDebug()<<userInfo[i];
        for (int j = 0;j < userInfo[i].size();j++) {
            qDebug()<<userInfo[i][j];
            if(QString::compare(u_name,userInfo[i][j]) == 0)  //判断用户名是否在user_name字段中
            {
                if(MySql::getInstance()->loguser(u_name,u_pwd))//判断密码是否一致
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
}
