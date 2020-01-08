#include "personaldialog.h"
#include "ui_personaldialog.h"
#include<QColorDialog>
#include <QDBusInterface>

PersonalDialog::PersonalDialog(QWidget *parent,QTcpSocket *_tcp,QString _oppositeName,QString _selfName) :
    QDialog(parent),tcp(_tcp),oppositeName(_oppositeName),selfName(_selfName),
    ui(new Ui::PersonalDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("私人聊天..."));
    ui->textEdit->setReadOnly(true);

}

PersonalDialog::~PersonalDialog()
{
    delete ui;
}

void PersonalDialog::on_pushButton_send_clicked()
{
    QString data1=ui->textEdit_2->toPlainText() ;
    ui->textEdit_2->clear();
    ui->textEdit->append(selfName);
    ui->textEdit->append(data1);
    QString data2="d#"+selfName+"#"+oppositeName+"#"+data1;
    tcp->write(data2.toLocal8Bit());
}

void PersonalDialog::getMessage(QString name, QString message)
{
    setNameText(name);
    ui->textEdit->append(name);
    ui->textEdit->append(message);
}

void PersonalDialog::setNameText(QString name)
{
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
