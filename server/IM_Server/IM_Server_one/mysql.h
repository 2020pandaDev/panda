#ifndef MYSQL_H
#define MYSQL_H


#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QtCore/QMutex>
#include <QDir>
#include <QDebug>
#include <QList>
#include <QStringList>
#include <QMessageBox>
#include <QTextCodec>



//待存放的数据结构//
struct UserInfo
{

    QString user_id;
    QString user_name;
    QString user_password;
    QString user_ip;
    QString user_port;
    QString user_online;
    QString user_link;
    QString user_Verification;

//  初始化结构体
    UserInfo(QString id = 0, QString name = 0, QString password = 0,QString ip = 0,QString port = 0,QString online = 0,QString linka = 0,QString Verification = 0)
    {
        user_id = id;
        user_name = name;
        user_password = password;
        user_ip = ip;
        user_port = port;
        user_online = online;
        user_link = linka;
        user_Verification = Verification;

    }
};



class MySql
{
public:
    MySql(const QString& pathAndDataBaseName,const QString& driver_Name,const QString& connection_Name);
    ~MySql();

private:

//    bool isDirExist(const QString& Dir);            //路径是否存在//

    QString dbDir;                //.db文件路径//
    QString connectionName;       //连接名称//
    QString driverName;
    QSqlDatabase db;


public:



    bool CreateConnection();      //创建数据库连接//

    void closeDb();               //关闭数据库//
    bool createTable();
    bool MyInsert(UserInfo& InputUserInfo);        //插入//
    QList<QStringList> selectDataFromBase();
    bool MySelect(UserInfo& OutputUserInfo);      //查找//
    bool MyDelete(UserInfo& InputUserInfo);       //删除//
    bool MyUpdate(UserInfo& InputUserInfo);       //更新//



};


#endif // MYSQL_H
