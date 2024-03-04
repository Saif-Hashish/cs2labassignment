#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "welcomewindow.h"
#include "Users.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{

    ui->setupUi(this);
    ui->label_error->setVisible(false);
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


void LoginWindow::on_push_login_clicked()
{
    for(int i=0;i<100;i++){
        if ((ui->line_username->text()) == usernames[i] && (ui->line_password->text()) == passwords[i]){

            hide();
            WelcomeWindow* W = new WelcomeWindow(usernames[i],ages[i],this);
            W->show();
        }

        else {
            ui->label_error->setVisible(true);
        }
    }

}
