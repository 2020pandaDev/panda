#include "worker.h"
#include <mysql.h>
#include <QMap>
#include <QMessageBox>
#include "serverthread.h"
#include <QTime>
#include <QMetaObject>
QMap<QString, QTcpSocket *> Worker::m_userSocket;
Worker::Worker(QObject *parent) : QObject(parent)
{
    m_dataParse = new Dataparsing ();

}

void Worker::doWork(QByteArray& message)
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
        qDebug()<<" registe:";

        QString    registeusrName = recValue["usrName"].toString();
        QString    registepassword = recValue["password"].toString();

        QStringList registeinfo;

        registeinfo.append(registeusrName);
        registeinfo.append(registepassword);
        m_returnDataToClient =registe(registeinfo);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        m_tcpSocket->write(m_sendData);
    break;
    }
    case 3://登录
    {
        qDebug()<<" loginIn:";

        QString loginInusrName = recValue["usrName"].toString();
        QString loginInpassword = recValue["password"].toString();
        QStringList loginIninfo;
        loginIninfo.append(loginInusrName);
        loginIninfo.append(loginInpassword);

        m_userSocket.insert(loginInusrName,m_tcpSocket);//绑定用户和socket

        m_returnDataToClient =loginIn(loginIninfo);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        m_tcpSocket->write(m_sendData);
    break;
    }

    case 4://私聊
    {
        qDebug()<<" privateChat :";
        m_returnDataToClient =privateChat(recValue);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        m_tcpSocket->write(m_sendData);
        break;
    }

    case 5:{//传入验证码
        qDebug()<<"doingCAPTCHA";
        QString    usrName = recValue["usrName"].toString();
        QString    captcha = recValue["captcha"].toString();
        QStringList helpIninfo;

        helpIninfo.append(usrName);
        helpIninfo.append(captcha);
        m_returnDataToClient = doingCAPTCHA(helpIninfo);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        m_tcpSocket->write(m_sendData);
        break;
    }

    case 6:{//验证码比较
        qDebug()<<"helpingOther";
        QString    usrName = recValue["usrName"].toString();
        QString    helper = recValue["helper"].toString();
        QString    captcha = recValue["captcha"].toString();
        QStringList helpIninfo;

        helpIninfo.append(usrName);
        helpIninfo.append(helper);
        helpIninfo.append(captcha);
        m_returnDataToClient = helpingOther(helpIninfo);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        m_tcpSocket->write(m_sendData);
        break;
    }

    case 7:{//退出登录
        qDebug()<<"Signout :";
        QString    SignoutusrName = recValue["usrName"].toString();
        QStringList usrOutInfo;

        usrOutInfo.append(SignoutusrName);
        m_returnDataToClient = Signout(usrOutInfo);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        m_tcpSocket->write(m_sendData);
        if (m_userSocket.contains(SignoutusrName)) {
            m_userSocket.remove(SignoutusrName);
        } else {
            qDebug() << "this Socket no exist :";
        }

        break;
    }

    case 8:{//更新

        m_returnDataToClient = updateUserList();
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        m_tcpSocket->write(m_sendData);
        break;
    }

    case 9:{//群聊

        QString  SignoutusrName = recValue["usrName"].toString();
        m_returnDataToClient = groupChat(recValue);
        m_sendData = m_dataParse->paserMapData(m_returnDataToClient);
        m_tcpSocket->write(m_sendData);
        break;
    }


    default:
         break;
    }
}

QVariantMap Worker::Signout(QStringList &SignoutInfo)//退出
{
    qDebug()<<"Signout thread:"<<QThread::currentThreadId();
    QVariantMap outResponse;

    if (!MySql::getInstance()->CreateConnection()) {
        qDebug() << "数据库连接失败!";
        outResponse.insert("dbstatus", "Connecting database failed!");
        return outResponse;
    }

    QString u_name = SignoutInfo.at(0);
    QString online_status = "false";

    QMap<QString ,QString> userinfo;
    userinfo.insert("user_name", u_name);
    userinfo.insert("online_status", online_status);

    if (MySql::getInstance()->MySelect(userinfo)) {
        qDebug() << "用户退出!";

        MySql::getInstance()->MyUpdateUserStatus(u_name, online_status);
       
    } else {
        qDebug() << "此用户未注册!";
    }

    outResponse.insert("Type", 7);
    outResponse.insert("online_status", online_status);
    return outResponse;
}

QVariantMap Worker::groupChat(QVariantMap& recValue)
{
    qDebug()<<"privateChat thread:"<<QThread::currentThreadId();
    qDebug()<< "privateChat fun ";
    QVariantMap sendData;
    QVariantMap returnData;

    QString sendUsrName = recValue["sendUsrName"].toString();
    QString Msg = recValue["Msg"].toString();
    int msgType = recValue["msgType"].toInt();
    QByteArray message= Msg.toLatin1().data();

    QList<QTcpSocket*> socketList = m_userSocket.values();
    if(socketList.isEmpty()){

    sendData.insert("Type",9);
    sendData.insert("sendUsrName",sendUsrName);
    sendData.insert("Msg",Msg);
    sendData.insert("msgType",0);
    m_sendData= m_dataParse->paserMapData(sendData);
    for (int i = 0;i<socketList.length();i++) {
        QMetaObject::invokeMethod(socketList.at(i),std::bind( static_cast< qint64(QTcpSocket::*)(const QByteArray &) >( &QTcpSocket::write ), socketList.at(i),m_sendData));
        //跨线程tcp通信
    }

    returnData.insert("Type",45);
    returnData.insert("result",true);
    } else {
     qDebug()<<"fail:";
     returnData.insert("Type",45);
     returnData.insert("result",false);
    }
    return  returnData;
}

void Worker::recSocketDescriptor(qintptr socketDescriptor)
{
    m_tcpSocket = new QTcpSocket();

   //run()函数中创建的栈对象保证了可靠的销毁。注意这个变量的依附性，当前线程变量仅在调用它的线程中有效。
    if (!m_tcpSocket->setSocketDescriptor(socketDescriptor)) { // 相当于tcpSocket的初始化，参数是为了保证不会为同一个客户端创建多个QTcpSocket对象
        //emit error(m_tcpSocket.error());
        return;
    }

        connect(m_tcpSocket, &QTcpSocket::readyRead, [ = ]() {
            m_recData = m_tcpSocket->readAll();
            qDebug() << "m_recData :" << m_recData;
            qDebug() << "run thread:" << QThread::currentThreadId();
            doWork(m_recData);
        });


}

QVariantMap Worker::registe(QStringList &registerInfo)
{
    qDebug()<<"registe thread:"<<QThread::currentThreadId();
    QString username=registerInfo.at(0);
    QString password=registerInfo.at(1);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    int num = qrand()%(1000000);
    QString strId=QString::number(num);

    QMap<QString ,QString> userinfo;
    userinfo.insert("user_name",username);
    userinfo.insert("user_password",password);
    userinfo.insert("user_id",strId);
    userinfo.insert("user_ip","100.22.11.11");
    userinfo.insert("user_port","4455");
    userinfo.insert("user_online","false");
    userinfo.insert("user_link","false");
    userinfo.insert("user_verification","000000");

    QVariantMap responMessage;
    MySql::getInstance()->CreateConnection();
    MySql::getInstance()->createTable();

   if( !MySql::getInstance()->userList().contains(username)){
            MySql::getInstance()->MyInsert(userinfo);
            qDebug()<< "注册成功";
            responMessage.insert("Type",2);
            responMessage.insert("responMsg",0);
            return responMessage ;
        }

        else {
            qDebug()<< "注册失败";
            responMessage.insert("Type",2);
            responMessage.insert("responMsg",1);
            return responMessage ;
        }

}
QVariantMap  Worker:: updateUserList()
{
    qDebug()<<"updateUserList thread:"<<QThread::currentThreadId();
    qDebug()<< "updateUserList fun ";
    QStringList userList = MySql::getInstance()->userList();
    QVariantMap userLists;
    userLists.insert("Type",8);
    userLists.insert("userList",userList);
    return userLists;

}

QVariantMap Worker::privateChat(QVariantMap& chatMessage)
{
    qDebug()<<"privateChat thread:"<<QThread::currentThreadId();
    qDebug()<< "privateChat fun ";
    QVariantMap sendData;
    QVariantMap returnData;

    QString sendUsrName = chatMessage["sendUsrName"].toString();
    QString recvUsrName = chatMessage["recvUsrName"].toString();
    QString Msg = chatMessage["Msg"].toString();
    int msgType = chatMessage["msgType"].toInt();
    QByteArray message= Msg.toLatin1().data();


    QTcpSocket* socket = m_userSocket[recvUsrName];


    if(socket){
    sendData.insert("Type",4);
    sendData.insert("sendUsrName",sendUsrName);
    sendData.insert("recvUsrName",recvUsrName);
    sendData.insert("Msg",Msg);
    sendData.insert("msgType",0);
    m_sendData= m_dataParse->paserMapData(sendData);

    QMetaObject::invokeMethod(socket,std::bind( static_cast< qint64(QTcpSocket::*)(const QByteArray &) >( &QTcpSocket::write ), socket,m_sendData));
//跨线程tcp通信


    returnData.insert("Type",44);
    returnData.insert("result",true);
    } else {
     qDebug()<<"fail:";
     returnData.insert("Type",44);
     returnData.insert("result","user no login");
    }
    return  returnData;


}




QVariantMap Worker::doingCAPTCHA(QStringList &CAPTCHAInfo)
{
    qDebug()<<"doingCAPTCHA thread:"<<QThread::currentThreadId();
    QVariantMap re;
    QString username=CAPTCHAInfo.at(0);
    QString captcha=CAPTCHAInfo.at(1);

    if (!MySql::getInstance()->CreateConnection()) {
        qDebug() << "数据库连接失败!";
        re.insert("dbstatus", "Connecting database failed!");
        return re;
    }

    QMap<QString ,QString> userinfo;
    userinfo.insert("user_name",username);
    userinfo.insert("user_verification",captcha);

    if (MySql::getInstance()->MySelect(userinfo)) {
        qDebug() << "有用户请求帮助!";
        userVerification.insert("user_name",username);
        userVerification.insert("user_verification",captcha);

        MySql::getInstance()->MyUpdateVerification(userVerification);

    } else {
        qDebug() << "用户请求失败!";

    }

    re.insert("Type", 5);
    re.insert("usrName", username);
    re.insert("captcha", captcha);

    return re;
}

QVariantMap Worker::helpingOther(QStringList &HelpingInfo)
{
    qDebug()<<"helpingOther thread:"<<QThread::currentThreadId();
    QVariantMap re;
    QString username=HelpingInfo.at(0); //求助者
    QString helper=HelpingInfo.at(1); //帮助者
    QString captcha=HelpingInfo.at(2); //验证码
    bool isSim = false; //连接是否成功

    if (!MySql::getInstance()->CreateConnection()) {
        qDebug() << "数据库连接失败!";

        re.insert("dbstatus", "Connecting database failed!");
        return re;
    }

    QString capt = MySql::getInstance()->userMessage(username, 7);

    if (captcha == capt) {
        isSim = true;
        qDebug() << "此刻可以进行帮助!";
    } else {
        isSim = false;
        qDebug() << "验证码不一致!";
    }

    re.insert("Type", 6);
    re.insert("user_name", username);
    re.insert("helper", helper);
    re.insert("isSim", isSim);

    return re;
}



QVariantMap Worker::loginIn(QStringList &userInfoList)
{
    qDebug() << "loginIn thread:" << QThread::currentThreadId();
    QVariantMap loginResponse;
    QString u_name = userInfoList.at(0);
    QString u_pwd = userInfoList.at(1);
    qDebug() << u_name << " " << u_pwd;

    if (!MySql::getInstance()->CreateConnection()) {
        qDebug() << "数据库连接失败!";
        loginResponse.insert("dbstatus", "Connecting database failed!");
        return loginResponse;
    }

    QMap<QString, QString> usinfo;
    usinfo.insert("user_name", u_name);
    QStringList userNameList = MySql::getInstance()->userList();
    if (userNameList.contains(u_name)) {
        QVariantMap userInfoList = MySql::getInstance()->selectDataFromBase();
        QStringList usNameList = userInfoList[u_name].toStringList(); //该用户所有信息
            if(usNameList.contains(u_pwd)) {
                loginResponse.insert("loginMsg", 0);

                QString online_status = "true";
                MySql::getInstance()->MyUpdateUserStatus(u_name, online_status);
                loginResponse.insert("onlineStatus", true);
                QVariantMap userMessage = MySql::getInstance()->userStatus();
                loginResponse.insert("result", userMessage);
                qDebug() << "loginMsg" << " 成功" ;
            } else {
                loginResponse.insert("loginMsg", 2);
            }
    } else {
        loginResponse.insert("loginMsg", 1);
         qDebug() << "loginMsg" << " 失败" ;
    }
    loginResponse.insert("Type", 3);
    return loginResponse;
}

