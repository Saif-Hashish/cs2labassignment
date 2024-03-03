#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_push_register_clicked()
{
    hide();
    RegisterWindow *registerwindow = new RegisterWindow(this);
    registerwindow->show();
}

