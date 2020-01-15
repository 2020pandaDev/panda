#ifndef PERSONALDIALOG_H
#define PERSONALDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QEvent>
#include <QKeyEvent>
#include "clientsocket.h"


namespace Ui {
class PersonalDialog;
}

class PersonalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalDialog(QWidget *parent = 0, ClientSocket *_tcp=0, QString _oppositeName=0, QString _selfName=0);
     ~PersonalDialog();

     QString oppositeName;
     void setNameText(QString name);
     void getMessage(QString name,QString message);

     // 接受服务器转发过来的信息
     void AddMessage(const QJsonValue &json);
signals:
//    void signalClose();
    void signalClose(QString r_name);
    // 发送给服务器的消息
    void signalSendMessage(const quint8 &type, const QJsonValue &json);
protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject *watched, QEvent *event);
    void closeEvent(QCloseEvent *event);
 private slots:
     void on_pushButton_send_clicked();


     void on_fontComboBox_currentFontChanged(const QFont &f);

     void on_toolButton_clicked(bool checked);

     void on_comboBox_currentIndexChanged(const QString &arg1);

     void on_toolButton_2_clicked(bool checked);

     void on_toolButton_3_clicked(bool checked);

     void on_toolButton_4_clicked();

     void on_toolButton_5_clicked();

private:
    Ui::PersonalDialog *ui;
    ClientSocket *tcp;
    QUdpSocket *udp;

    quint8          m_nChatType;        // 聊天类型，群组聊天或私人聊天


    QString selfName;
    QColor color;
};

#endif // PERSONALDIALOG_H
