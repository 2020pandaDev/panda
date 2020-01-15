#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DLabel>
#include "mysql.h"
#include "server.h"
#include <QVBoxLayout>
#include <DSpinner>
#include <DGuiApplicationHelper>
DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);

    DGuiApplicationHelper::instance()->setPaletteType(DGuiApplicationHelper::LightType);

    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    //a.setTheme("light");
    a.setOrganizationName("deepin");
    a.setApplicationName("Panda Server");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/images/logo.svg"));
    a.setProductName("panda Application");
    a.setApplicationDescription("This is a panda server application.");


    Server ser;
    DMainWindow w;
    w.setMinimumSize(500, 500);
    QWidget* awid = new QWidget(&w);

    QVBoxLayout*  m_centralLayout =new QVBoxLayout ();
    QLabel* m_pictureLabel = new QLabel ();
    QLabel* m_wordLabel = new QLabel ();
    QFont* m_font = new QFont ();
    m_font->setPointSize(20);
    DPalette* m_pe = new DPalette();
    m_pe->setColor(DPalette::WindowText, Qt::red);
    DSpinner* m_spinner = new DSpinner ();

    m_centralLayout->setContentsMargins(0, 10, 0, 100);


    m_wordLabel->setWordWrap(true);
    m_wordLabel->setFont(*m_font);
    m_wordLabel->setPalette(*m_pe);
    m_wordLabel->setText("服务器已启动");
    m_wordLabel->setAlignment(Qt::AlignHCenter);
    m_wordLabel->setMinimumSize(320,50);
    m_centralLayout->addWidget(m_wordLabel, 0, Qt::AlignCenter);
    m_centralLayout->addSpacing(0);

    m_spinner->setMinimumSize(200, 200);
    m_centralLayout->addWidget(m_spinner, 0, Qt::AlignCenter);
    m_spinner->start();
    awid->setLayout(m_centralLayout);

    w.setCentralWidget(awid);
    w.show();



    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
