#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"

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

void RegisterWindow::thecheckboxifs(bool &usergenrescheck)
{
    QString chosengenres[6];

    if(ui->actioncheckbox->isChecked())
    {
        chosengenres[0] = ui->actioncheckbox->text();
        usergenrescheck = true;
    }

    if(ui->comdedycheckbox->isChecked())
    {
        chosengenres[1] = ui->comdedycheckbox->text();
        usergenrescheck = true;
    }

    if(ui->dramacheckbox->isChecked())
    {
        chosengenres[2] = ui->dramacheckbox->text();
        usergenrescheck = true;
    }

    if(ui->romancecheckbox->isChecked())
    {
        chosengenres[3] = ui->romancecheckbox->text();
        usergenrescheck = true;
    }

    if(ui->horrorcheckbox->isChecked())
    {
        chosengenres[4] = ui->horrorcheckbox->text();
        usergenrescheck = true;
    }

    if(ui->othercheckbox->isChecked())
    {
        chosengenres[5] = ui->othercheckbox->text();
        usergenrescheck = true;
    }
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
    QString accounttype = "";
    bool usernamecheck = true;
    bool userpasswordcheck = true;
    bool useragecheck = true;
    bool usergenrescheck = false;
    bool userfillcheck = true;

    if(ui->maleradiobutton->isChecked())
        gender = "Male";
    else if(ui->maleradiobutton->isChecked())
        gender = "Femal";

    if(ui->userradiobutton->isChecked())
        accounttype = "user";
    if(ui->adminradiobutton->isChecked())
        accounttype = "admin";

    for(int i = 0; i < usersCount; i++)
    {
        if(username == usernames[i])
        {
            ui->usernameerrorlabel->setVisible(true);
            usernamecheck = false;
        }

    }

    thecheckboxifs(usergenrescheck);

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

    if(username == "" || password == "" || retypepassword == "" || month == "" || day == NULL || year == NULL || gender == "" || accounttype == "" || usergenrescheck == false)
    {
       ui->registererrorlabel->setVisible(true);
    }

    else if (usernamecheck == true && userpasswordcheck == true && useragecheck == true && userfillcheck == true && usergenrescheck == true)
    {
        usernames[usersCount] = username;
        passwords[usersCount] = password;
        ages[usersCount] = 2024 - year;

        usersCount++;

        hide();
        WelcomeWindow* W = new WelcomeWindow(usernames[usersCount-1],ages[usersCount-1],this);
        W->show();

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



