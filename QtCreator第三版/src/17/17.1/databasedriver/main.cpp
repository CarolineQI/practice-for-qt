#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include "connection.h"
#include <QVariant>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlField>

int main(int argc ,char * argv[])
{
    QApplication a(argc,argv);
    //查看所有数据库驱动
//    qDebug()<<"Available drivers:";
//    QStringList drivers = QSqlDatabase::drivers();
//    foreach(QString driver,drivers )
//    {
//        qDebug()<<driver;
//    }

    if(! createConnection()){
        return 1;
    }
        //查询数据库记录
    QSqlDatabase db1=QSqlDatabase::database("connection1");
    QSqlQuery query1(db1);
    qDebug()<<"connection1";
    query1.exec("select * from  student");
    while (query1.next()) {
        qDebug()<<query1.value(0).toInt()<<query1.value(1).toString();
    }
    QSqlDatabase db2=QSqlDatabase::database("connection2");
    QSqlQuery query2(db2);
    qDebug()<<"connection2";
    query2.exec("select * from teacher");
    while (query2.next()) {
        qDebug()<<query2.value(0).toInt()<<query2.value(1).toString()<<query2.value(2).toString();
    }


    int numRows;

        //获取总行数
    if(db2.driver()->hasFeature(QSqlDriver::QuerySize)){
        qDebug()<<"has feacture: query size";
        numRows=query2.size();
    }else{
        qDebug()<<"no feacture: query size";
        query2.last();
        numRows=query2.at()+1;
    }

    qDebug()<<"row number:"<<numRows;

    query2.seek(1);

    qDebug()<<"cunrrent ";

    return a.exec();
}
