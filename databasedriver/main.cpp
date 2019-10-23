#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include "connection.h"
#include <QVariant>

int main(int argc, char * argv[])
{
    QApplication a(argc,argv);
    if(!createConnection())
        return 1;
    QSqlQuery query;
    query.exec("select * from person");
    while(query.next())
    {
        qDebug()<< query.value(0).toInt()<< query.value(1).toString()<< query.value(2).toString();

    }
    qDebug()<<"Available drivers:";
    QStringList drivers =QSqlDatabase::drivers();
    foreach (QString driver, drivers) {
        qDebug()<<driver;
        }
        return a.exec();

}
