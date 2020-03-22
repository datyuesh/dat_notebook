#ifndef SQL_CREATE_H
#define SQL_CREATE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStandardPaths>
static bool createSql()
{
    QString db_filePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) +
            "/.config/notebookSql.db";
    qDebug() << "db file path = " << db_filePath;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(db_filePath);

    if(!db.open()) return false;

    QSqlQuery query;
    query.exec(QString(
      "create table fileInfo (fileName QString)"));

    return true;
}

#endif // SQL_CREATE_H
