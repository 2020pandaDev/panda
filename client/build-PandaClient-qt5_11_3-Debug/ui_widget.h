/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextBrowser *messageBrower;
    QFontComboBox *fontComBox;
    QComboBox *sizeComboBox;
    QToolButton *boldToolBtn;
    QToolButton *italicToolBtn;
    QToolButton *underlineToolBtn;
    QToolButton *colorToolBtn;
    QToolButton *sendToolBtn;
    QToolButton *saveToolBtn;
    QToolButton *clearToolBtn;
    QTextEdit *messageTextEdit;
    QTableWidget *userTableWidget;
    QPushButton *sendPushButton;
    QPushButton *exitPushButton;
    QLabel *userNumLabel;
    QToolButton *toolButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(781, 440);
        messageBrower = new QTextBrowser(Widget);
        messageBrower->setObjectName(QStringLiteral("messageBrower"));
        messageBrower->setGeometry(QRect(320, 10, 451, 211));
        fontComBox = new QFontComboBox(Widget);
        fontComBox->setObjectName(QStringLiteral("fontComBox"));
        fontComBox->setGeometry(QRect(320, 230, 121, 30));
        sizeComboBox = new QComboBox(Widget);
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->setObjectName(QStringLiteral("sizeComboBox"));
        sizeComboBox->setGeometry(QRect(450, 230, 72, 30));
        boldToolBtn = new QToolButton(Widget);
        boldToolBtn->setObjectName(QStringLiteral("boldToolBtn"));
        boldToolBtn->setGeometry(QRect(560, 230, 30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolBtn->setIcon(icon);
        boldToolBtn->setIconSize(QSize(20, 20));
        boldToolBtn->setCheckable(true);
        boldToolBtn->setAutoRaise(true);
        italicToolBtn = new QToolButton(Widget);
        italicToolBtn->setObjectName(QStringLiteral("italicToolBtn"));
        italicToolBtn->setGeometry(QRect(590, 230, 30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolBtn->setIcon(icon1);
        italicToolBtn->setIconSize(QSize(20, 20));
        italicToolBtn->setCheckable(true);
        italicToolBtn->setAutoRaise(true);
        underlineToolBtn = new QToolButton(Widget);
        underlineToolBtn->setObjectName(QStringLiteral("underlineToolBtn"));
        underlineToolBtn->setGeometry(QRect(620, 230, 30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolBtn->setIcon(icon2);
        underlineToolBtn->setIconSize(QSize(20, 20));
        underlineToolBtn->setCheckable(true);
        underlineToolBtn->setAutoRaise(true);
        colorToolBtn = new QToolButton(Widget);
        colorToolBtn->setObjectName(QStringLiteral("colorToolBtn"));
        colorToolBtn->setGeometry(QRect(650, 230, 30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn->setIcon(icon3);
        colorToolBtn->setIconSize(QSize(20, 20));
        colorToolBtn->setAutoRaise(true);
        sendToolBtn = new QToolButton(Widget);
        sendToolBtn->setObjectName(QStringLiteral("sendToolBtn"));
        sendToolBtn->setGeometry(QRect(680, 230, 30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolBtn->setIcon(icon4);
        sendToolBtn->setIconSize(QSize(20, 20));
        sendToolBtn->setAutoRaise(true);
        saveToolBtn = new QToolButton(Widget);
        saveToolBtn->setObjectName(QStringLiteral("saveToolBtn"));
        saveToolBtn->setGeometry(QRect(710, 230, 30, 30));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolBtn->setIcon(icon5);
        saveToolBtn->setIconSize(QSize(20, 20));
        saveToolBtn->setAutoRaise(true);
        clearToolBtn = new QToolButton(Widget);
        clearToolBtn->setObjectName(QStringLiteral("clearToolBtn"));
        clearToolBtn->setGeometry(QRect(740, 230, 30, 30));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolBtn->setIcon(icon6);
        clearToolBtn->setIconSize(QSize(20, 20));
        clearToolBtn->setAutoRaise(true);
        messageTextEdit = new QTextEdit(Widget);
        messageTextEdit->setObjectName(QStringLiteral("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(320, 270, 451, 101));
        userTableWidget = new QTableWidget(Widget);
        if (userTableWidget->columnCount() < 3)
            userTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userTableWidget->setObjectName(QStringLiteral("userTableWidget"));
        userTableWidget->setGeometry(QRect(10, 10, 301, 361));
        userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        userTableWidget->setShowGrid(false);
        sendPushButton = new QPushButton(Widget);
        sendPushButton->setObjectName(QStringLiteral("sendPushButton"));
        sendPushButton->setGeometry(QRect(500, 390, 80, 26));
        exitPushButton = new QPushButton(Widget);
        exitPushButton->setObjectName(QStringLiteral("exitPushButton"));
        exitPushButton->setGeometry(QRect(120, 390, 80, 26));
        userNumLabel = new QLabel(Widget);
        userNumLabel->setObjectName(QStringLiteral("userNumLabel"));
        userNumLabel->setGeometry(QRect(300, 390, 101, 26));
        toolButton = new QToolButton(Widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(530, 230, 31, 31));
        toolButton->setStyleSheet(QStringLiteral("border-image: url(:/table.png);"));
        toolButton->setCheckable(true);
        toolButton->setAutoRaise(true);

        retranslateUi(Widget);

        sizeComboBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        fontComBox->setCurrentText(QApplication::translate("Widget", "\345\256\213\344\275\223", nullptr));
        sizeComboBox->setItemText(0, QApplication::translate("Widget", "9", nullptr));
        sizeComboBox->setItemText(1, QApplication::translate("Widget", "10", nullptr));
        sizeComboBox->setItemText(2, QApplication::translate("Widget", "11", nullptr));
        sizeComboBox->setItemText(3, QApplication::translate("Widget", "12", nullptr));
        sizeComboBox->setItemText(4, QApplication::translate("Widget", "13", nullptr));
        sizeComboBox->setItemText(5, QApplication::translate("Widget", "14", nullptr));
        sizeComboBox->setItemText(6, QApplication::translate("Widget", "15", nullptr));
        sizeComboBox->setItemText(7, QApplication::translate("Widget", "16", nullptr));
        sizeComboBox->setItemText(8, QApplication::translate("Widget", "17", nullptr));

#ifndef QT_NO_TOOLTIP
        boldToolBtn->setToolTip(QApplication::translate("Widget", "\345\212\240\347\262\227", nullptr));
#endif // QT_NO_TOOLTIP
        boldToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        italicToolBtn->setToolTip(QApplication::translate("Widget", "\345\200\276\346\226\234", nullptr));
#endif // QT_NO_TOOLTIP
        italicToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        underlineToolBtn->setToolTip(QApplication::translate("Widget", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_NO_TOOLTIP
        underlineToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        colorToolBtn->setToolTip(QApplication::translate("Widget", "\346\233\264\346\224\271\351\242\234\350\211\262\345\255\227\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
        colorToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        sendToolBtn->setToolTip(QApplication::translate("Widget", "\344\274\240\350\276\223\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
        sendToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        saveToolBtn->setToolTip(QApplication::translate("Widget", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        saveToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        clearToolBtn->setToolTip(QApplication::translate("Widget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
#endif // QT_NO_TOOLTIP
        clearToolBtn->setText(QApplication::translate("Widget", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "\344\270\273\346\234\272\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = userTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200", nullptr));
        sendPushButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        exitPushButton->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        userNumLabel->setText(QApplication::translate("Widget", "\345\234\250\347\272\277\347\224\250\346\210\267:", nullptr));
#ifndef QT_NO_TOOLTIP
        toolButton->setToolTip(QApplication::translate("Widget", "\350\277\234\347\250\213\345\212\251\346\211\213", nullptr));
#endif // QT_NO_TOOLTIP
        toolButton->setText(QApplication::translate("Widget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
