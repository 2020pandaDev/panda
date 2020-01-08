#include "mysql.h"
#include "QThread"

MySql* MySql:: m_pInstance = nullptr;
QMutex MySql::m_Mutex;


MySql::MySql(const QString &pathAndDataBaseName, const QString &driver_Name, const QString &connection_Name, QObject *parent):QObject (parent)
{

        dbDir = pathAndDataBaseName;
        connectionName = connection_Name;
        driverName = driver_Name;
        db = QSqlDatabase::addDatabase(driverName,connectionName);  //创建一个SQLite数据库/
}



MySql::~MySql()
{
    closeDb();

}



void MySql::closeDb()
{
    if (db.isOpen())
    {
        db.close();
    }
}




bool MySql::CreateConnection()
{

//     //本地数据库文件名//
    db.setDatabaseName(dbDir);                                //数据库连接命名//
    if (!db.open())                                            //如果.db文件不存在，自动新建.db文件并打开//
    {
        qDebug() << QString(QObject::tr("无法建立数据库连接"));
        return false;
    }



    return true;
}

bool MySql::createTable()
{
    qDebug()<<"createTable thread:"<<QThread::currentThreadId();
    QSqlQuery query(db);
    bool success =query.exec("create table IF NOT EXISTS t_user(user_id text primary key,"
                    " user_name text, user_password text, user_ip text, "
                    "user_port text, user_online text, user_link text,user_Verification text);");   //新建一张表，访问已有.bd时，执行该语句也不受影响//

    if(success)
    {
        qDebug() << QObject::tr("数据库表创建成功！\n");
        return true;
    }
    else
    {
        qDebug() << QObject::tr("数据库表创建失败！\n");
        return false;
    }

}


bool MySql::MyInsert(const QMap<QString,QString>& InputUserInfo)
{

  qDebug() << "mysql thread:" <<QThread::currentThreadId();
    QSqlQuery query(db);
    query.prepare("insert into t_user(user_id,"
                  " user_name, user_password, user_ip , "
                  "user_port, user_online, user_link,user_Verification)"
        "values(:id,:name,:password,:ip,:port,:online,:link,:Verification)");


    query.bindValue(":id",InputUserInfo["user_id"]);
    query.bindValue(":name",InputUserInfo["user_name"]);
    query.bindValue(":password",InputUserInfo["user_password"]);
    query.bindValue(":ip",InputUserInfo["user_ip"]);
    query.bindValue(":port",InputUserInfo["user_port"]);
    query.bindValue(":online",InputUserInfo["user_online"]);
    query.bindValue(":link",InputUserInfo["user_link"]);
    query.bindValue(":Verification",InputUserInfo["user_Verification"]);


    bool success=query.exec();
   if(!success)
   {
       QSqlError lastError = query.lastError();
       qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
       return false;
   }
   qDebug() << QString(QObject::tr("插入成功"));
    return true;

}



QList<QStringList> MySql::selectDataFromBase(const QMap<QString,QString>& InputUserInfo)
{
    QSqlQuery query(db);
    query.prepare("select * from t_user where user_name = :name");
    query.bindValue(":name",InputUserInfo["user_name"]);
    query.exec();

    QList<QStringList> userInfo;

    while(query.next()){

        QStringList rowData;

        rowData << query.value(0).toString();
        rowData << query.value(1).toString();
        rowData << query.value(2).toString();
        rowData << query.value(3).toString();
        rowData << query.value(4).toString();
        rowData << query.value(5).toString();
        rowData << query.value(6).toString();
        rowData << query.value(7).toString();

        userInfo.append(rowData);
    }
    return userInfo;
}

bool MySql::MySelect(const QMap<QString,QString>& OutputUserInfo)
{


    QSqlQuery query(db);
    query.prepare("select * from t_user where user_name = :name");
    query.bindValue(":name",OutputUserInfo["user_name"]);
    if (!query.exec())
    {
        return false;
    }

    return true;
}




bool MySql::MyDelete(const QMap<QString,QString>& InputUserInfo)
{

    QSqlQuery query(db);
    query.prepare("delete from t_user where id = :id");
    query.bindValue(":id",InputUserInfo["user_id"]);
    if (!query.exec())
    {
        qDebug() << QString(QObject::tr("删除失败"));
        return false;
    }

    qDebug() << QString(QObject::tr("删除成功"));
    return true;
}

bool MySql::MyUpdate(const QMap<QString,QString>& InputUserInfo)
{


    if (!MyDelete(InputUserInfo))
    {
        return false;
    }
    if (!MyInsert(InputUserInfo))
    {
        return false;
    }


    return true;
}


bool MySql::MyUpdateUserInfo(const QMap<QString,QString>& InputUserInfo)
{


    QSqlQuery query(db);
    query.prepare("update t_user set user_id = :id ,"
                  " user_name = :name, user_password = :password, user_ip = :ip, "
                  "user_port = :port, user_online = :online, "
                  "user_link = :link,user_Verification = :Verification where user_name = :findName");


    query.bindValue(":id",InputUserInfo["user_id"]);
    query.bindValue(":name",InputUserInfo["user_name"]);
    query.bindValue(":password",InputUserInfo["user_password"]);
    query.bindValue(":ip",InputUserInfo["user_ip"]);
    query.bindValue(":port",InputUserInfo["user_port"]);
    query.bindValue(":online",InputUserInfo["user_online"]);
    query.bindValue(":link",InputUserInfo["user_link"]);
    query.bindValue(":Verification",InputUserInfo["user_Verification"]);
    query.bindValue(":findName",InputUserInfo["user_name"]);


    bool success=query.exec();
   if(!success)
   {
       QSqlError lastError = query.lastError();
       qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
       return false;
   }
    qDebug() << QString(QObject::tr("更新成功"));
    return true;

}


bool MySql::MyUpdateVerification(const QMap<QString,QString>& InputUserInfo)
{


     QSqlQuery query(db);

    query.prepare("update t_user set user_Verification = :Verification where user_name = :findName");

    query.bindValue(":name",InputUserInfo["user_name"]);
    query.bindValue(":Verification",InputUserInfo["user_verification"]);
    query.bindValue(":Verification",InputUserInfo["user_verification"]);
    query.bindValue(":findName",InputUserInfo["user_name"]);

    bool success=query.exec();
    if(!success)
    {
       QSqlError lastError = query.lastError();
       qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
       return false;
    }
    qDebug() << QString(QObject::tr("更新成功"));
    return true;

}
bool MySql::loguser(QString name, QString passward) //登录判断用户与密码是否一致
{
    qDebug()<<"验证用户";
    QString str=QString("select * from t_user where user_name='%1' and user_password='%2'").arg(name).arg(passward);
    QSqlQuery *query=new QSqlQuery;
    query->exec(str);
    query->last();
    int record=query->at()+1;
    if(record == 0)
        return false;
    return true;
}

MySql *MySql::getInstance()
{
    if (m_pInstance == nullptr)
            {

               QMutexLocker mlocker(&m_Mutex);  //双检索，支持多线程
               if (m_pInstance == nullptr)
               {
                    m_pInstance = new MySql("./us.db","QSQLITE","t_user");

               }

            }
          return m_pInstance;

}


