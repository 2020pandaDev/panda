#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QMainWindow>
#include <QTcpSocket>
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
    explicit UserInterface(QWidget *parent = 0,QTcpSocket *pTcpSocket=0,QString _name="");
    ~UserInterface();

private slots:
    void readMessages();
    void on_pushButton_clicked();

    void on_refreshBtn_clicked();
    void on_listWidget_doubleClicked(const QModelIndex &index);

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_toolButton_3_clicked(bool checked);

    void on_toolButton_2_clicked(bool checked);

    void on_toolButton_clicked(bool checked);

    void on_toolButton_4_clicked();

private:
    Ui::UserInterface *ui;
    QTcpSocket *tcpSocket;
    QString name;
    QStringList onlineUser;
    QColor color;
    QTimer *freshentime;
    //PersonalDialog *PD;
    QMap<QString,PersonalDialog*> pdList;
};

#endif // USERINTERFACE_H
