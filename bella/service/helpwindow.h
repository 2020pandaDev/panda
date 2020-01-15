#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>



class helpWindow:public QWidget
{
    Q_OBJECT
public:
    helpWindow(QWidget *parent = nullptr);

public slots:
    QString generateValid();
    QString getStrId();
Q_SIGNALS:
    //void showWindow();
private:
    QLabel *m_label;
    QVBoxLayout *v;
    QPushButton *m_btn;
    QString  strId;
};

#endif // HELPWINDOW_H
