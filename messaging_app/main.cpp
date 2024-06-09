#include "mainwindow.h"

#include <QApplication>

//#include "databasemanager.h"

#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QString>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setConnectOptions("QSQLITE_OPEN_READWRITE");
    db.setDatabaseName("UsersDB.db");
    if (!db.open()) {
        std::cout << "Error connecting to database: " << db.lastError().text().toStdString() << std::endl;
        //return 1;
    }
    // Create a query object
    QSqlQuery query(db);
    // Example: Create a table
    // Replace "your_table_name" with the actual table
    //if (!query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, email TEXT, acc_id TEXT, password TEXT)")) {
        //std::cerr << "Error creating table: " << query.lastError().text().toStdString() << std::endl;
        //return 1;
    //}
    // Example: Insert data into the table
    // Replace "your_values" with the actual values you want to insert
    if (!query.exec("INSERT INTO users (username, email) VALUES ('John', 'john@email.com')")) {
        std::cerr << "Error inserting data: " << query.lastError().text().toStdString() << std::endl;
        //return 1;
    }
    // Example: Retrieve data from the table
    if (!query.exec("SELECT * FROM users")) {
        std::cerr << "Error retrieving data: " << query.lastError().text().toStdString() << std::endl;
        //return 1;
    }
    // Print the retrieved data
    while (query.next()) {
        QString id = query.value(0).toString();
        QString username = query.value(1).toString();
        QString email = query.value(2).toString();
        qDebug() << "ID: " + id + "Name: " + username + "Email: " + email;
        //std::cout << "ID: " << id << ", Name: " << username.toStdString() << ", Email: " << email << std::endl;
    }
    // Close the database connection
    db.close();


    return a.exec();
}
