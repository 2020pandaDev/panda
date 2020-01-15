#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QMainWindow>
#include "clientsocket.h"
#include "personaldialog.h"
#include <QMap>
#include<QColor>
#include <QTimer>

namespace Ui {
class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = 0);
    ~UserInterface();
    /**
     * @brief MainWindow::SetSocket
     * @param tcpSocket
     * @param name
     */
    void SetSocket(ClientSocket *tcpSocket, const QString &m_name);

    void sendGetFriends();

private slots:
    void readMessages();
    void on_pushButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_toolButton_3_clicked(bool checked);

    void on_toolButton_2_clicked(bool checked);

    void on_toolButton_clicked(bool checked);

    void on_toolButton_4_clicked();
    
    void SltFriendChatWindowClose(QString re_name);

  ////////////////////////////
    // 用户接受处理
    //void SltReadMessages(const QJsonObject &json);

    // 状态，上线下线状态
    void SltTcpStatus(const quint8 &state);
    // 解析Socket的消息
    void SltTcpReply(const quint8 &type, const QJsonObject &dataVal);

private:
    void ParseFriendListReply(const QJsonObject &dataVal);
    // 消息处理
    void ParseFriendMessageReply(const QJsonObject &dataVal);

protected:
    void closeEvent (QCloseEvent * e);


private:
    Ui::UserInterface *ui;
  //  QTcpSocket *tcpSocket;
    QString name;
    QStringList onlineUser;
    QColor color;
    QTimer *freshentime;
    //PersonalDialog *PD;
    PersonalDialog *tempDialog = nullptr;
    QMap<QString,PersonalDialog*> pdList;
private:
    // socket通信类
    ClientSocket    *m_tcpSocket;

    // 主动退出操作时不进行断线匹配
    bool            m_bQuit;
};

#endif // USERINTERFACE_H
