#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <QtSql/QSqlDatabase>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Messaging-app");



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_proceed_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //number represent page index;
}


void MainWindow::on_signup_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_login_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

