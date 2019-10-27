#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE","connection1");
//    db1.setHostName("localhost");
    db1.setDatabaseName("my1.db");       //这里输入你的数据库名
//    db1.setUserName("root");
//    db1.setPassword("521312");   //这里输入你的密码
    if (!db1.open()) {
        QMessageBox::critical(0, QObject::tr("无法打开数据库"), "无法创建数据库连接！ ", QMessageBox::Cancel);
        return false;
    }
    //下面来创建表
    // 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
    QSqlQuery query1(db1);
    // 使数据库支持中文
    query1.exec("SET NAMES 'Latin1'");
    // 创建 student 表
//    query1.exec("create table student (id int primary key, name varchar(20))");
//    query1.exec("insert into student values(0, '刘星')");
//    query1.exec("insert into student values(1, '张三点')");
//    query1.exec("insert into student values(2, '李东方')");

    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE","connection2");
//    db1.setHostName("localhost");
    db2.setDatabaseName("my2.db");       //这里输入你的数据库名
//    db1.setUserName("root");
//    db1.setPassword("521312");   //这里输入你的密码
    if (!db2.open()) {
        QMessageBox::critical(0, QObject::tr("无法打开数据库"), "无法创建数据库连接！ ", QMessageBox::Cancel);
        return false;
    }
    //下面来创建表
    // 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
    QSqlQuery query2(db2);
    // 使数据库支持中文
    query2.exec("SET NAMES 'Latin1'");
    // 创建 teacher 表
//    query2.exec("create table teacher (id int primary key,course varchar(20), name varchar(20))");
//    query2.exec("insert into teacher values(0, '数学', '刘老师')");
//    query2.exec("insert into teacher values(1, '英语', '张老师')");
//    query2.exec("insert into teacher values(2, '语文', '李老师')");
    return true;
}
#endif // CONNECTION_H
