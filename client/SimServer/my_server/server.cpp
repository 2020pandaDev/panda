#include "server.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDateTime>
#include <QJsonParseError>
#include <QJsonObject>
#include "unit.h"


server::server(QWidget *parent) : DMainWindow(parent)
{
    m_widget = new DWidget;
    m_textbrower = new DTextBrowser(m_widget);

    //初始化
    m_tcpserver = new  QTcpServer();
    m_tcpsocket = nullptr;

    //调用listen函数监听同时绑定IP和端口号
    if(m_tcpserver->listen(QHostAddress::Null,8000)){
        connect(m_tcpserver,&QTcpServer::newConnection,this,&server::slot_newconnect);  //将服务器的新连接信号连接到接收新连接的槽
    }else {
        QMessageBox::critical(this,"错误","IP绑定错误，请关闭其它服务端或更改绑定端口号");
    }

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_textbrower);

    m_widget->setLayout(mainLayout);
    setCentralWidget(m_widget);
}

void server::slot_newconnect()
{   //查询是否有新连接
    if(m_tcpserver->hasPendingConnections()){
        m_tcpsocket = m_tcpserver->nextPendingConnection();  //  //获取与真实客户端相连的客户端套接字0
        m_textbrower->append("客户端登录");  //若有新连接，则提示

    this->connect(m_tcpsocket,&QTcpSocket::readyRead,this,&server::slot_recvmessage); //连接客户端的套接字的有新消息信号到接收消息的槽
    this->connect(m_tcpsocket,&QTcpSocket::disconnected,this,&server::slot_disconnect); //连接客户端的套接字取消连接信号到取消连接槽
    }
}

void server::slot_recvmessage()
{
    if(m_tcpsocket != nullptr) //与客户端连接的socket，不是nullptr，则说明有客户端存在
    {
        // 读取socket数据
        QByteArray reply = m_tcpsocket->readAll();
        QJsonParseError jsonError;
        // 转化为 JSON 文档
        QJsonDocument doucment = QJsonDocument::fromJson(reply, &jsonError);
        // 解析未发生错误
        if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {
            // JSON 文档为对象
            if (doucment.isObject()) {
                // 转化为对象
                QJsonObject jsonObj = doucment.object();

                int nType = jsonObj.value("type").toInt();
                qDebug()<<"nType"<<nType;
                QJsonValue dataVal = jsonObj.value("data");
                qDebug()<<"dataVal"<<dataVal;

                switch (nType) {
                case Register:
                         ParseReister(dataVal);
                     break;
                case Login:
                         ParseLogin(dataVal);
                     break;
                default:
                    break;
                }
            }
        }
        QHostAddress clientaddr = m_tcpsocket->peerAddress(); //获得IP
        int port = m_tcpsocket->peerPort();   //获得端口号

        QDateTime datetime = QDateTime::currentDateTime();

        QString sendMessage = tr("recv from :") + clientaddr.toString() + tr(" : ") \
                                + QString::number(port) + tr("   ") + datetime.toString("yyyy-M-dd hh:mm:ss") + tr("\n");
        sendMessage += reply;

        m_textbrower->append(sendMessage);   //将接收到的内容加入到listwidget
    }

}
void server::slot_disconnect()
{
    if(m_tcpsocket != nullptr)
    {
        m_textbrower->append("client logout!");
        m_tcpsocket->close(); //关闭客户端
        m_tcpsocket->deleteLater();
    }

}

void server::slot_sendmessage()
{
    if(m_tcpsocket != nullptr) //与客户端连接的socket，不是nullptr，则说明有客户端存在
    {
            QString sendMessage = "deng lu cheng gong"; //从单行文本框获得要发送消息
            m_tcpsocket->write(sendMessage.toLatin1());
    }
}

void server::SltSendMessage(const quint8 &type, const QJsonValue &jsonVal)
{
    if (!m_tcpsocket->isOpen()) return;

    // 构建 Json 对象
    QJsonObject jsonObj;
    jsonObj.insert("type", type);
    jsonObj.insert("data", jsonVal);

    // 构建 Json 文档
    QJsonDocument document;
    document.setObject(jsonObj);
    m_tcpsocket->write(document.toJson(QJsonDocument::Compact));
}

void server::ParseReister(const QJsonValue &dataVal)
{
    // data 的 value 是对象
    if (dataVal.isObject()) {
        QJsonObject dataObj = dataVal.toObject();
        QString strName = dataObj.value("name").toString();
        QString strPwd = dataObj.value("passwd").toString();

        // 返回客户端
        QJsonObject json;
        json.insert("name", strName);
        json.insert("passwd", strPwd);

        // 发送查询结果至客户端
        SltSendMessage(Register, json);;
    }
}

void server::ParseLogin(const QJsonValue &dataVal)
{
    // data 的 value 是对象
    if (dataVal.isObject()) {
        QJsonObject dataObj = dataVal.toObject();
        QString strName = dataObj.value("name").toString();
        QString strPwd = dataObj.value("passwd").toString();

        // 返回客户端
        QJsonObject jsonObj;
        jsonObj.insert("name", strName);
        jsonObj.insert("passwd", strPwd);
        // 发送查询结果至客户端
        SltSendMessage(Login, jsonObj);;
    }
}

