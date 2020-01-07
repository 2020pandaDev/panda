/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox;
    QToolButton *boldToolButton;
    QToolButton *italicToolButton;
    QToolButton *underToolButton;
    QToolButton *colorToolButton;
    QToolButton *sendToolButton;
    QToolButton *saveToolButton;
    QToolButton *clearToolButton;
    QTextEdit *messageTextEdit;
    QPushButton *closePushButton;
    QPushButton *sendPushButton;

    void setupUi(QDialog *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(543, 435);
        label = new QLabel(Chat);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 441, 31));
        textBrowser = new QTextBrowser(Chat);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(40, 60, 481, 161));
        fontComboBox = new QFontComboBox(Chat);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        fontComboBox->setGeometry(QRect(40, 230, 216, 30));
        fontComboBox->setMaxVisibleItems(8);
        comboBox = new QComboBox(Chat);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(261, 230, 40, 30));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLength);
        boldToolButton = new QToolButton(Chat);
        boldToolButton->setObjectName(QStringLiteral("boldToolButton"));
        boldToolButton->setGeometry(QRect(310, 230, 30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolButton->setIcon(icon);
        boldToolButton->setIconSize(QSize(20, 20));
        boldToolButton->setCheckable(true);
        italicToolButton = new QToolButton(Chat);
        italicToolButton->setObjectName(QStringLiteral("italicToolButton"));
        italicToolButton->setGeometry(QRect(340, 230, 30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolButton->setIcon(icon1);
        italicToolButton->setIconSize(QSize(20, 20));
        italicToolButton->setCheckable(true);
        underToolButton = new QToolButton(Chat);
        underToolButton->setObjectName(QStringLiteral("underToolButton"));
        underToolButton->setGeometry(QRect(370, 230, 30, 30));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underToolButton->setIcon(icon2);
        underToolButton->setIconSize(QSize(20, 20));
        underToolButton->setCheckable(true);
        colorToolButton = new QToolButton(Chat);
        colorToolButton->setObjectName(QStringLiteral("colorToolButton"));
        colorToolButton->setGeometry(QRect(400, 230, 30, 30));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolButton->setIcon(icon3);
        colorToolButton->setIconSize(QSize(20, 20));
        sendToolButton = new QToolButton(Chat);
        sendToolButton->setObjectName(QStringLiteral("sendToolButton"));
        sendToolButton->setGeometry(QRect(430, 230, 30, 30));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolButton->setIcon(icon4);
        sendToolButton->setIconSize(QSize(20, 20));
        saveToolButton = new QToolButton(Chat);
        saveToolButton->setObjectName(QStringLiteral("saveToolButton"));
        saveToolButton->setGeometry(QRect(460, 230, 30, 30));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolButton->setIcon(icon5);
        saveToolButton->setIconSize(QSize(20, 20));
        clearToolButton = new QToolButton(Chat);
        clearToolButton->setObjectName(QStringLiteral("clearToolButton"));
        clearToolButton->setGeometry(QRect(490, 230, 30, 30));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolButton->setIcon(icon6);
        clearToolButton->setIconSize(QSize(20, 20));
        messageTextEdit = new QTextEdit(Chat);
        messageTextEdit->setObjectName(QStringLiteral("messageTextEdit"));
        messageTextEdit->setGeometry(QRect(40, 270, 481, 121));
        closePushButton = new QPushButton(Chat);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setGeometry(QRect(310, 400, 91, 25));
        closePushButton->setIconSize(QSize(25, 31));
        sendPushButton = new QPushButton(Chat);
        sendPushButton->setObjectName(QStringLiteral("sendPushButton"));
        sendPushButton->setGeometry(QRect(420, 400, 91, 25));

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QDialog *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Dialog", nullptr));
        label->setText(QApplication::translate("Chat", "TextLabel", nullptr));
        comboBox->setItemText(0, QApplication::translate("Chat", "9", nullptr));
        comboBox->setItemText(1, QApplication::translate("Chat", "10", nullptr));
        comboBox->setItemText(2, QApplication::translate("Chat", "11", nullptr));
        comboBox->setItemText(3, QApplication::translate("Chat", "12", nullptr));
        comboBox->setItemText(4, QApplication::translate("Chat", "13", nullptr));
        comboBox->setItemText(5, QApplication::translate("Chat", "14", nullptr));
        comboBox->setItemText(6, QApplication::translate("Chat", "15", nullptr));
        comboBox->setItemText(7, QApplication::translate("Chat", "16", nullptr));
        comboBox->setItemText(8, QApplication::translate("Chat", "17", nullptr));

        comboBox->setCurrentText(QApplication::translate("Chat", "12", nullptr));
        boldToolButton->setText(QApplication::translate("Chat", "\345\212\240\347\262\227", nullptr));
        italicToolButton->setText(QApplication::translate("Chat", "\346\226\234\344\275\223", nullptr));
        underToolButton->setText(QApplication::translate("Chat", "\344\270\213\345\210\222\347\272\277", nullptr));
        colorToolButton->setText(QApplication::translate("Chat", "\346\233\264\346\224\271\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
        sendToolButton->setText(QApplication::translate("Chat", "\344\274\240\350\276\223\346\226\207\344\273\266", nullptr));
        saveToolButton->setText(QApplication::translate("Chat", "\344\277\235\345\255\230\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
        clearToolButton->setText(QApplication::translate("Chat", "\346\270\205\351\231\244\350\201\212\345\244\251\350\256\260\345\275\225", nullptr));
        closePushButton->setText(QApplication::translate("Chat", "\345\205\263\351\227\255", nullptr));
        sendPushButton->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
