#include "userinterface.h"
#include "ui_userinterface.h"
#include<QColorDialog>

UserInterface::UserInterface(QWidget *parent, QTcpSocket *pTcpSocket, QString _name) :
    QMainWindow(parent), tcpSocket(pTcpSocket), name(_name),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    this->setWindowTitle("Chat Room");
    ui->textEdit->setReadOnly(true);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessages()));

}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::readMessages()
{
    QByteArray temp=tcpSocket->readAll();
    QString data=QString::fromLocal8Bit(temp);
    QStringList list=data.split("#");
    if(list[0]=="c")
    {
        QString str1=list[1]+":";
        ui->textEdit->append("<font color=red>"+str1+"</font>");
        ui->textEdit->append(list[2]);
    }
    else if(list[0]=="d")
    {
        ui->listWidget->clear();
        onlineUser.clear();
        for(int i=1;i<list.size();i++)
        {
            if(list[i]==name)
                continue;
            ui->listWidget->addItem(list[i]);
            onlineUser.append(list[i]);
        }
    }
    else if(list[0]=="e")
    {
        //判断发送消息用户名是否在pdList里面，如果不在，新建一个PersonalDialog对象
        if(!pdList.contains(list[1]))
        {
            qDebug()<<list[1]<<name;
            PersonalDialog *temp=new PersonalDialog(this,tcpSocket,list[1],name);
            pdList.insert(list[1],temp);
            temp->show();
        }
        pdList[list[1]]->getMessage(list[1],list[3]);
    }
    else
        return;
}


void UserInterface::on_pushButton_clicked() //发字
{
    QString str=ui->textEdit_2->toPlainText();
    ui->textEdit->append("<font color=blue> 自己: </font>");
    ui->textEdit->append(str);
    QString message="c#"+name+"#"+str;
    QByteArray ctxt = message.toLocal8Bit();
    tcpSocket->write(ctxt);
    ui->textEdit_2->clear();
}

//刷新槽函数
void UserInterface::on_refreshBtn_clicked()
{
    QString message="e#getUserList";
    tcpSocket->write(message.toLocal8Bit());
}

void UserInterface::on_listWidget_doubleClicked(const QModelIndex &index)
{
    QString str=onlineUser.at(index.row());  //获得用户名
    PersonalDialog *temp=new PersonalDialog(this,tcpSocket,str,name);
    pdList.insert(str,temp);
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
