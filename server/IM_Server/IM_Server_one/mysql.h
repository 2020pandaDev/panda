#ifndef MYSQL_H
#define MYSQL_H

#include <QWidget>
#include <QSqlDatabase>
#include <QtCore/QMutex>
#include <QDir>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QList>
#include <QMap>
#include <QStringList>
#include <QVariantMap>
#include <QMessageBox>
#include <QTextCodec>

//待存放的数据结构
class MySql : public QObject
{
    Q_OBJECT
public:
    ~ MySql();

private:
    explicit MySql(const QString &pathAndDataBaseName,const QString& driver_Name,const QString& connection_Name,QObject *parent = nullptr);
    static MySql* m_pInstance;
    static QMutex m_Mutex;//实例互斥锁

    //    bool isDirExist(const QString& Dir);            //路径是否存在

    QString dbDir;                //.db文件路径
    QString connectionName;       //连接名称
    QString driverName;
    QSqlDatabase db;


public:



    bool CreateConnection();      //创建数据库连接
    void closeDb();               //关闭数据库
    bool createTable();            //建表的方法
    bool MyInsert(const QMap<QString,QString>& InputUserInfo);        //插入
//    bool MyInsertDataBase(const QMap<QString,QString>& userInfo);
    QStringList getAllOnLineUsers();
    QStringList getAllUserOnLineStatus();
    QVariantMap userStatus();       //获取用户的在线，链接，验证码的状态
    QStringList userList();         //获取用户列表
    QString userMessage(const QString userName,int UserFieldNumber);//获取用户信息
    QVariantMap selectDataFromBase();
    QVariantMap selectNameDataFromBase();
//    QVariantMap selectDataFromBase(int type, QString userName);
    bool MySelect(const QMap<QString,QString>& OutputUserInfo);      //查找
    QList<QStringList> selectDataFromBase(const QMap<QString,QString>& InputUserInfo);//获取全部表内的全部信息

    bool MyDelete(const QMap<QString,QString>& InputUserInfo);       //删除
    bool MyUpdate(const QMap<QString,QString>& InputUserInfo);       //删除用户后插入用户新值
    bool MyUpdateUserStatus(const QString& UserName,const QString& OnLineStatus);//更新用户的在线状态
    bool MyUpdateUserStatus(int Choose,const QString& UserName,const QString& NewStatus);//选择更新的用户的在线状态／用户是否链接／用户的验证码
    bool MyUpdateUserInfo(const QMap<QString,QString>& InputUserInfo);//更新用户除用户ｉｄ和用户名之外的所有值
    bool MyUpdateVerification(const QMap<QString,QString>& InputUserInfo);//更新用户的验证码

    static MySql* getInstance(void);//获取mysql类的实例
   



};

#endif // MYSQL_H
