#include "userinterface.h"
#include "ui_userinterface.h"
#include<QColorDialog>
#include "unit.h"
#include "myapp.h"
#include "global.h"

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    this->setWindowTitle("Chat Room");
    ui->textEdit->setReadOnly(true);
   // connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessages()));

}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::SetSocket(ClientSocket *tcpSocket, const QString &m_name)
{
    qDebug()<<"2222222222";
    if (nullptr != tcpSocket) {
        m_tcpSocket = tcpSocket;
        qDebug()<<"UserInterface socket"<<m_tcpSocket;
        connect(m_tcpSocket, SIGNAL(signalMessage(quint8,QJsonObject)), this, SLOT(SltTcpReply(quint8,QJsonObject)));

        connect(m_tcpSocket, SIGNAL(signalStatus(quint8)), this, SLOT(SltTcpStatus(quint8)));

        QJsonObject json;
        json.insert("Type", FriendsList);
        m_tcpSocket->SltSendMessage(FriendsList, json);
    }
    name = m_name;

}

void UserInterface::readMessages()
{
//    QByteArray temp=tcpSocket->readAll();
//    QString data=QString::fromLocal8Bit(temp);
//    QStringList list=data.split("#");
//    if(list[0]=="c")
//    {
//        QString str1=list[1]+":";
//        ui->textEdit->append("<font color=red>"+str1+"</font>");
//        ui->textEdit->append(list[2]);
//    }
//    else if(list[0]=="d")
//    {
//        ui->listWidget->clear();
//        onlineUser.clear();
//        for(int i=1;i<list.size();i++)
//        {
//            if(list[i]==name)
//                continue;
//            ui->listWidget->addItem(list[i]);
//            onlineUser.append(list[i]);
//        }
//    }
//    else if(list[0]=="e")
//    {
//        //判断发送消息用户名是否在pdList里面，如果不在，新建一个PersonalDialog对象
//        if(!pdList.contains(list[1]))
//        {
//            qDebug()<<list[1]<<name;
//            PersonalDialog *temp=new PersonalDialog(this,tcpSocket,list[1],name);
//            pdList.insert(list[1],temp);
//            temp->show();
//        }
//        pdList[list[1]]->getMessage(list[1],list[3]);
//    }
//    else
//        return;
}


void UserInterface::on_pushButton_clicked() //发字
{
//    QString str=ui->textEdit_2->toPlainText();
//    ui->textEdit->append("<font color=blue> 自己: </font>");
//    ui->textEdit->append(str);
//    QString message="c#"+name+"#"+str;
//    QByteArray ctxt = message.toLocal8Bit();
//    tcpSocket->write(ctxt);
//    ui->textEdit_2->clear();
}

void UserInterface::sendGetFriends()
{
    // QString message="e#getUserList";
     //tcpSocket->write(message.toLocal8Bit());
     // 构建json数据
     QJsonObject json;
     json.insert("Type", FriendsList);
 //    json.insert("sendUsrName", selfName);
 //    json.insert("recvUsrName", oppositeName);
 //    json.insert("msgType", Text);//wenzixiaoxi
 //    json.insert("Msg", text);
     m_tcpSocket->SltSendMessage(FriendsList, json);
}

void UserInterface::on_listWidget_doubleClicked(const QModelIndex &index)
{
    QString str=onlineUser.at(index.row());  //获得用户名
    qDebug()<<"my friends name"<<str<<"my name is"<<name;
    PersonalDialog *temp=new PersonalDialog(this,m_tcpSocket,str,name);
    pdList.insert(str,temp);
   // if(pdList[str]->exec())
    //    return;

    pdList[str]->show();
    pdList[str]->setNameText(str);
}

//字体
void UserInterface::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEdit_2->setCurrentFont(f);
    ui->textEdit_2->setFocus();
}

//文字大小
void UserInterface::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->textEdit_2->setFontPointSize(arg1.toDouble());
    ui->textEdit_2->setFocus();
}


//字体加粗
void UserInterface::on_toolButton_3_clicked(bool checked)
{
    if(checked)
        ui->textEdit_2->setFontWeight(QFont::Bold);

    else
        ui->textEdit_2->setFontWeight(QFont::Normal);
    ui->textEdit_2->setFocus();
}

//字体倾斜
void UserInterface::on_toolButton_2_clicked(bool checked)
{
    ui->textEdit_2->setFontItalic(checked);
    ui->textEdit_2->setFocus();

}

//字体加下划线
void UserInterface::on_toolButton_clicked(bool checked)
{
    ui->textEdit_2->setFontUnderline(checked);
    ui->textEdit_2->setFocus();
}

//字体颜色
void UserInterface::on_toolButton_4_clicked()
{
    color = QColorDialog::getColor(color,this);
    if(color.isValid())
    {
        ui->textEdit_2->setTextColor(color);
        ui->textEdit_2->setFocus();
    }
}

/**
 * @brief MainWindow::SltTcpStatus
 * tcp状态监听
 * @param state
 */
void UserInterface::SltTcpStatus(const quint8 &state)
{
    switch (state) {
    case DisConnectedHost: {
        if (m_bQuit) return;
        QPixmap pixmap  = QPixmap(":/resource/background/app.png");
        pixmap = myHelper::ChangeGrayPixmap(pixmap.toImage());
       // systemTrayIcon->setIcon(QIcon(pixmap));
        pixmap = QPixmap(MyApp::m_strHeadFile);
       // ui->widgetHead->SetHeadPixmap(myHelper::ChangeGrayPixmap(pixmap.toImage()));
        if (!this->isVisible()) this->show();
        QMessageBox::information(this, "Panda客户端", "与服务器断开连接");
    }
        break;
    case ConnectedHost:
    {
        QJsonObject json;
        json.insert("name", MyApp::m_strUserName);
        json.insert("passwd", MyApp::m_strPassword);

        m_tcpSocket->SltSendMessage(Login, json);
    }
        break;
    case LoginSuccess:
    {
      //  systemTrayIcon->setIcon(QIcon(":/resource/background/app.png"));
       // ui->widgetHead->SetHeadPixmap(QPixmap(MyApp::m_strHeadFile));
        if (!this->isVisible()) this->show();
        QMessageBox::information(this, "Panda客户端", "重连成功！");
    }
        break;
    default:
        break;
    }
}

/**
 * @brief MainWindow::SltTcpReply
 * @param type
 * @param msg
 */
void UserInterface::SltTcpReply(const quint8 &type, const QJsonObject &dataVal)
{
    qDebug()<<"1111111"<<type;
    switch (type) {
    qDebug()<<"55555type"<<type;
//    case UserOnLine:
//    {
//        UpdateFriendStatus(OnLine, dataVal);
//    }
//        break;
//    case UserOffLine:
//    {
//        UpdateFriendStatus(OffLine, dataVal);
//    }
//        break;
//    case UpdateHeadPic:
//    {
//        // 你的好友更新了头像
//        ParseUpFriendHead(dataVal);
//    }
//        break;
//    case AddFriend:
//    {
//        ParseAddFriendReply(dataVal);
//    }
//        break;
//    case AddGroup:
//    {
//        ParseAddGroupReply(dataVal);
//    }
//        break;

//    case AddFriendRequist:
//    {
//        ParseAddFriendRequest(dataVal);
//    }
//        break;
//    case AddGroupRequist:
//    {
//        ParseAddGroupRequest(dataVal);
//    }
//        break;

//    case CreateGroup:
//    {
//        ParseCreateGroupReply(dataVal);
//    }
//        break;
//    case GetMyFriends:
//    {
//        ParseGetFriendsReply(dataVal);
//    }
//        break;
//    case GetMyGroups:
//    {
//        ParseGetGroupFriendsReply(dataVal);
//    }
//        break;
//    case RefreshFriends:
//    {
//        ParseRefreshFriendsReply(dataVal);
//    }
//        break;
//    case RefreshGroups:
//    {
//        ParseRefreshGroupFriendsReply(dataVal);
//    }
//        break;
    case FriendsList:
    {
        ParseFriendListReply(dataVal);
    }
        break;
    case SendMsg:
    {
        ParseFriendMessageReply(dataVal);
    }
        break;
//    case SendGroupMsg:
//    {
//        ParseGroupMessageReply(dataVal);
//    }
//        break;
//    case SendFile:
//    {
//        ParseFriendMessageReply(dataVal);
//    }
//        break;
//    case SendPicture:
//    {
//        ParseFriendMessageReply(dataVal);
//    }
//        break;
    default:
        break;
//    }
    }
}

void UserInterface::ParseFriendListReply(const QJsonObject &dataVal)
{
    qDebug()<<"ParseFriendListReply";
    QStringList list ;
   // QVariant strMsg = dataVal.value("userList").toVariant();
   // QString str = QString(QJsonDocument(dataVal).toJson());

    //遍历json对象
//       QJsonObject::Iterator it;
//       QString keyString="";
//       QString valueString="";
//       for(it = dataVal.begin();it != dataVal.end();it++)
//       {
//           QString value=it.value().toString();
//           keyString=it.key()+","+keyString;
//           valueString="'"+value+"',"+valueString;
//       }
   //    qDebug()<<keyString=keyString.left(keyString.length()-1);
  //     qDebug()<<valueString=valueString.left(valueString.length()-1);
//    QJsonObject::const_iterator it = dataVal.constBegin();
//    QJsonObject::const_iterator end = dataVal.constEnd();
//    //
//    while (end != it)
//    {
//       qDebug()<<"+++key"<<it.key();
//       qDebug()<<"+++value"<<it.value();
//       it++;
//    }

    QJsonValue jsonValue = dataVal.value("userList");
    QJsonArray array = jsonValue.toArray();
    int nSize = array.size();
    for (int i = 0; i < nSize; ++i) {
        qDebug()<<"QJsonArray"<<array.at(i).toString();
        if(array.at(i).toString().isEmpty())
        {
            continue;
        }
        list.append(array.at(i).toString());
    }



    ui->listWidget->clear();
    onlineUser.clear();
    for(int i=0;i<list.size();i++)
    {
        if(list[i]==name)
            continue;
        ui->listWidget->addItem(list[i]);
        onlineUser.append(list[i]);
    }
}

    /**
     * @brief MainWindow::ParseMessageReply
     * @param dataVal
     */
void UserInterface::ParseFriendMessageReply(const QJsonObject &dataVal)
{
    // 如果收到消息时有聊天窗口存在，直接添加到聊天记录，并弹出窗口
//    foreach (PersonalDialog *window, m_chatFriendWindows) {
//        if (window->GetUserId() == id) {
//            window->AddMessage(json);
//            window->show();
//            return;
//        }
//    }

//    // 没有检索到聊天窗口，直接弹出新窗口
//    QList<QQCell *> groups = ui->frindListWidget->getCells();
//    foreach (QQCell *cell, groups.at(0)->childs) {
//        if (cell->id == id) {
//            ChatWindow *chatWindow = new ChatWindow();
//            connect(chatWindow, SIGNAL(signalSendMessage(quint8,QJsonValue)), m_tcpSocket, SLOT(SltSendMessage(quint8,QJsonValue)));
//            connect(chatWindow, SIGNAL(signalClose()), this, SLOT(SltFriendChatWindowClose()));

//            chatWindow->SetCell(cell);
//            chatWindow->AddMessage(json);
//            chatWindow->show();
//            // 添加到当前聊天框
//            m_chatFriendWindows.append(chatWindow);
//            return;
//        }
//    }

    //判断发送消息用户名是否在pdList里面，如果不在，新建一个PersonalDialog对象
    QString strFromName = dataVal.value("sendUsrName").toString();
    QString strMsg = dataVal.value("Msg").toString();
    if(!pdList.contains(strFromName))
    {
        qDebug()<<strFromName<<name;
        PersonalDialog *temp=new PersonalDialog(this,m_tcpSocket,strFromName,name);
        pdList.insert(strFromName,temp);
        temp->show();
    }
//    if(pdList.value(strFromName)->close())
//    {
//            PersonalDialog *temp=new PersonalDialog(this,m_tcpSocket,strFromName,name);
//            pdList.insert(strFromName,temp);
//            temp->show();
//    }
    pdList[strFromName]->getMessage(strFromName,strMsg);
}

void UserInterface::closeEvent (QCloseEvent * e)
{
    QJsonObject json;
    json.insert("Type", Logout);
    json.insert("usrName", name);

    m_tcpSocket->SltSendMessage(Logout, json);
}

