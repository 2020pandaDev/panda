#ifndef PERSONALDIALOG_H
#define PERSONALDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QNetworkInterface>

namespace Ui {
class PersonalDialog;
}

class PersonalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalDialog(QWidget *parent = 0, QTcpSocket *_tcp=0, QString _oppositeName=0, QString _selfName=0);
     ~PersonalDialog();

     QString oppositeName;
     void setNameText(QString name);
     void getMessage(QString name,QString message);

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
    QTcpSocket *tcp;
    QUdpSocket *udp;

    QString selfName;
    QColor color;
};

#endif // PERSONALDIALOG_H
