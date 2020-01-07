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
    QSqlQuery query(db);

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

bool MySql::MyInsert(const QMap<QString,QString>& InputUserInfo)
{


    QSqlQuery query(db);
    query.prepare("insert into student(user_id,"
                  " user_name, user_password, user_ip , "
                  "user_port, user_online, user_link,user_Verification)"
        "values(:id,:name,:password,:ip,:port,:online,:link,:Verification)");


    query.bindValue(":id",InputUserInfo["id"]);
    query.bindValue(":name",InputUserInfo["name"]);
    query.bindValue(":password",InputUserInfo["password"]);
    query.bindValue(":ip",InputUserInfo["ip"]);
    query.bindValue(":port",InputUserInfo["port"]);
    query.bindValue(":online",InputUserInfo["online"]);
    query.bindValue(":link",InputUserInfo["link"]);
    query.bindValue(":Verification",InputUserInfo["Verification"]);


    bool success=query.exec();
   if(!success)
   {
       QSqlError lastError = query.lastError();
       qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
       return false;
   }
    return true;

}

bool MyInsertDataBase(const QMap<QString,QString>& userInfo)
{
    QString user_id = userInfo.value("id");
    QString user_name = userInfo.value("name");
    QString user_password = userInfo.value("password");
    QString user_ip = userInfo.value("ip");
    QString user_port = userInfo.value("port");
    QString user_online = userInfo.value("online");
    QString user_link = userInfo.value("link");
    QString user_Verification = userInfo.value("Verification");

    QString sql = QString("insert into student(user_id,"
                          " user_name, user_password, user_ip , "
                          "user_port, user_online, user_link,user_Verification)"
                "values('%1','%2','%3','%4','%5','%6','%7','%8')").arg(user_id).arg(user_name).arg(user_password).arg(user_ip).arg(user_port).arg(user_online).arg(user_link).arg(user_Verification);
    QSqlQuery query;
    bool ok = query.exec(sql);
    if(!ok)
    {
        return false;
    }

    return true;

}

QList<QStringList> MySql::selectDataFromBase(const QMap<QString,QString>& InputUserInfo)
{
    QSqlQuery query(db);
    query.prepare("select * from t_user where user_name = :name");
    query.bindValue(":name",InputUserInfo["name"]);
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
    query.bindValue(":name",OutputUserInfo["name"]);
    if (!query.exec())
    {
        return false;
    }

//    QSqlRecord rec = query.record();
//    qDebug() << QObject::tr("t_user表字段数：" ) << rec.count();

//    if( rec.count())
//    {
//        return false;
//    }

    return true;
}




bool MySql::MyDelete(const QMap<QString,QString>& InputUserInfo)
{

    QSqlQuery query(db);
    query.prepare("delete from student where id = :id");
    query.bindValue(":id",InputUserInfo["id"]);
    if (!query.exec())
    {
        return false;
    }


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







