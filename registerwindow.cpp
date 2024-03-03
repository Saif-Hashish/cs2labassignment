#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    ui->usernameerrorlabel->setVisible(false);
    ui->retypepassworderrorlabel->setVisible(false);
    ui->ageerrorlabel->setVisible(false);
    ui->registererrorlabel->setVisible(false);
}

void RegisterWindow::infosave()
{
    QString username = ui->Usernameline->text();
    QString password = ui->passwordline->text();
    QString retypepassword = ui->retypepasswordline->text();
    QString month = ui->birthmonthcombobox->currentText();
    int day = ui->birthdayline->text().toInt();
    int year = ui->birthyearline->text().toInt();
    QString gender = "";
    //QString accounttype = "";
    bool usernamecheck = true;
    bool userpasswordcheck = true;
    bool useragecheck = true;
    bool userfillcheck = true;

    if(ui->maleradiobutton->isChecked())
        gender = "Male";
    else if(ui->maleradiobutton->isChecked())
        gender = "Femal";

    //if(ui->userradiobutton->isChecked())
       // accounttype = "user";
    //if(ui->adminradiobutton->isChecked())
       // accounttype = "admin";

    for(int i = 0; i < usersCount; i++)
    {
        if(username == usernames[i])
        {
            ui->usernameerrorlabel->setVisible(true);
            usernamecheck = false;
        }

    }

    if(password != retypepassword)
    {
        ui->retypepassworderrorlabel->setVisible(true);
        userpasswordcheck = false;
    }

    if(2024 - year < 12)
    {
        ui->ageerrorlabel->setVisible(true);
        useragecheck = false;
    }

    if(username == "" || password == "" || retypepassword == "" || month == "" || day == NULL || year == NULL || gender == "" /*|| accounttype == ""*/)
    {
       ui->registererrorlabel->setVisible(true);
    }

    else if (usernamecheck == true && userpasswordcheck == true && useragecheck == true && userfillcheck == true)
    {
        usernames[usersCount] = username;
        passwords[usersCount] = password;
        ages[usersCount] = 2024 - year;
        usersCount++;


    }

}


void RegisterWindow::on_registerbutton_clicked()
{
    ui->usernameerrorlabel->setVisible(false);
    ui->retypepassworderrorlabel->setVisible(false);
    ui->ageerrorlabel->setVisible(false);
    ui->registererrorlabel->setVisible(false);
    infosave();
}


RegisterWindow::~RegisterWindow()
{
    delete ui;
}



