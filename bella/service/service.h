#ifndef SERVICE_H
#define SERVICE_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>

#include "helpwindow.h"


#define HELP_SERVICE_NAME  "com.deepin.help.service"
#define HElP_SERVICE_PATH  "/com/deepin/help/service"
#define HELP_SERVICE_IFC   "com.deepin.help.service"


class service : public QMainWindow
{
    Q_OBJECT

public:
    service(QWidget *parent = 0);
    ~service();

public slots:
   Q_SCRIPTABLE void Show();
   Q_SCRIPTABLE void getValid();

Q_SIGNALS:
    void showWindow();
    void getValidSignal();
private:
    QLabel *m_label;
    QVBoxLayout *v;

private:
    helpWindow *h;
};

#endif // SERVICE_H
