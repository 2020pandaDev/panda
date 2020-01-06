#include "mysql.h"

MySql::MySql(const QString& pathAndDataBaseName,const QString& driver_Name,const QString& connection_Name)

{



    dbDir = pathAndDataBaseName;
    connectionName = connection_Name;
    driverName = driver_Name;
    db = QSqlDatabase::addDatabase(driverName,connectionName);  //创建一个SQLite数据库连接//



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
        qDebug() << "无法建立数据库连接";
        return false;
    }



    return true;
}

bool MySql::createTable()
{
    QSqlQuery query(QSqlDatabase::database(connectionName));
    bool success =query.exec("create table t_user(user_id text primary key,"
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


bool MySql::MyInsert(UserInfo& InputUserInfo)
{


    QSqlQuery query(QSqlDatabase::database(connectionName));
    query.prepare("insert into student(user_id,"
                  " user_name, user_password, user_ip , "
                  "user_port, user_online, user_link,user_Verification)"
        "values(:id,:name,:password,:ip,:port,:online,:link,:Verification)");


    query.bindValue(":id",InputUserInfo.user_id);
    query.bindValue(":name",InputUserInfo.user_name);
    query.bindValue(":password",InputUserInfo.user_password);
    query.bindValue(":ip",InputUserInfo.user_ip);
    query.bindValue(":port",InputUserInfo.user_port);
    query.bindValue(":online",InputUserInfo.user_online);
    query.bindValue(":link",InputUserInfo.user_link);
    query.bindValue(":Verification",InputUserInfo.user_Verification);


    bool success=query.exec();
   if(!success)
   {
       QSqlError lastError = query.lastError();
       qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
       return false;
   }
    return true;

}

QList<QStringList> MySql::selectDataFromBase()
{
    QSqlQuery query("select * from t_user where user_name = :name");

}

bool MySql::MySelect(UserInfo& OutputUserInfo)
{


    QSqlQuery query(db);
    query.prepare("select * from t_user where user_name = :name");
    query.bindValue(":name",OutputUserInfo.user_name);
    if (!query.exec())
    {
        return false;
    }

    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("t_user表字段数：" ) << rec.count();

    while(query.next())
    {

        qDebug() << query.value(1).toString() << " ";
        qDebug() << query.value(1).toString() << " ";
        qDebug() << "\n";
    }



//	query.next();
//	OutputUserInfo.user_id = query.value(0).toString();
//	OutputUserInfo.user_name = query.value(1).toString();
//	OutputUserInfo.user_password = query.value(2).toString();//未完，带完善



    return true;
}




bool MySql::MyDelete(UserInfo& InputUserInfo)
{

    QSqlQuery query(db);
    query.prepare("delete from t_user where id = :id");
    query.bindValue(":id",InputUserInfo.user_id);
    if (!query.exec())
    {
        return false;
    }


    return true;
}

bool MySql::MyUpdate(UserInfo& InputUserInfo)
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

