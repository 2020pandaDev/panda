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


//待存放的数据结构//
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
    bool MyInsert(const QMap<QString,QString>& InputUserInfo);        //插入//
    bool MyInsertDataBase(const QMap<QString,QString>& userInfo);


    QList<QStringList> selectDataFromBase(const QMap<QString,QString>& InputUserInfo);
    bool MySelect(const QMap<QString,QString>& OutputUserInfo);      //查找//


    bool MyDelete(const QMap<QString,QString>& InputUserInfo);       //删除//
    bool MyUpdate(const QMap<QString,QString>& InputUserInfo);       //更新//

};


#endif // MYSQL_H
