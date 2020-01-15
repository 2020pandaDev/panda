#include "personaldialog.h"
#include "ui_personaldialog.h"

#include "global.h"
//#include "unit.h"
//#include "myapp.h"

#include<QColorDialog>
#include <QDBusInterface>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QToolTip>

PersonalDialog::PersonalDialog(QWidget *parent,ClientSocket *_tcp,QString _oppositeName,QString _selfName) :
    QDialog(parent),tcp(_tcp),oppositeName(_oppositeName),selfName(_selfName),
    ui(new Ui::PersonalDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("私人聊天..."));
    ui->textEdit->setReadOnly(true);
    ui->textEdit_2->installEventFilter(this);
   // ui->textEdit_2->setFocus();
}

PersonalDialog::~PersonalDialog()
{
    delete ui;
}

/**
 * @brief ChatWindow::changeEvent
 * 翻译切换
 * @param e
 */
void PersonalDialog::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PersonalDialog::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Return:
    {
        if (Qt::ControlModifier == event->modifiers()) {
            on_pushButton_send_clicked();
        }
    }
        break;
    default:
        break;
    }

    QWidget::keyPressEvent(event);
}

bool PersonalDialog::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->textEdit_2) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
                on_pushButton_send_clicked();
                return true;
            }
        }
    }
    return false;
}


void PersonalDialog::on_pushButton_send_clicked()
{
    QString text = ui->textEdit_2->toPlainText() ;

   // QString data2="d#"+selfName+"#"+oppositeName+"#"+data1;
   // tcp->write(data2.toLocal8Bit());
    // 把最后一个回车换行符删掉
    while (text.endsWith("\n")) {
        text.remove(text.length() - 2, 2);
    }

    // 判断消息是否为空
    qDebug()<<"text"<<text;
    if (text.isEmpty()) {
        QDialog *widgetMsg = new QDialog;
        QPoint point = widgetMsg->mapToGlobal(ui->pushButton_send->pos());

        QToolTip::showText(point, tr("不能发送空白信息！"));
        return;
    }

    // 清除输入框
    ui->textEdit_2->clear();
    ui->textEdit->append(selfName);
    ui->textEdit->append(text);
    // 构建json数据
    QJsonObject json;
    json.insert("Type", SendMsg);
    json.insert("sendUsrName", selfName);
    json.insert("recvUsrName", oppositeName);
    json.insert("msgType", Text);//wenzixiaoxi
    json.insert("Msg", text);
    tcp->SltSendMessage(SendMsg, json);

}

void PersonalDialog::getMessage(QString name, QString message)
{
    setNameText(name);
    ui->textEdit->append(name);
    ui->textEdit->append(message);
}

void PersonalDialog::setNameText(QString name)
{
    qDebug()<<"Person friend"<<name;
    ui->lineEdit_name->setText(name);
}

//字体
void PersonalDialog::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEdit_2->setCurrentFont(f);
    ui->textEdit_2->setFocus();
}


//大小
void PersonalDialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->textEdit_2->setFontPointSize(arg1.toDouble());
    ui->textEdit_2->setFocus();
}


void PersonalDialog::on_toolButton_clicked(bool checked)
{
    if(checked)
        ui->textEdit_2->setFontWeight(QFont::Bold);

    else
        ui->textEdit_2->setFontWeight(QFont::Normal);
    ui->textEdit_2->setFocus();

}

void PersonalDialog::on_toolButton_2_clicked(bool checked)
{
    ui->textEdit_2->setFontUnderline(checked);
    ui->textEdit_2->setFocus();
}

void PersonalDialog::on_toolButton_3_clicked(bool checked)
{
    ui->textEdit_2->setFontUnderline(checked);
    ui->textEdit_2->setFocus();
}

void PersonalDialog::on_toolButton_4_clicked()
{
    color = QColorDialog::getColor(color,this);
    if(color.isValid())
    {
        ui->textEdit_2->setTextColor(color);
        ui->textEdit_2->setFocus();
    }
}

void PersonalDialog::on_toolButton_5_clicked()
{
    QDBusInterface ifce("com.deepin.linkhelp", "/com/deepin/linkhelp", "com.deepin.linkhelp");
    ifce.call("show");
}


