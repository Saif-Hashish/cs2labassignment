#include "welcomewindow.h"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

QPixmap pix(":/new/prefix1/pic3/download.jpeg");
ui->label_welcome_image-> setPixmap(pix.scaled(400,300));

}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}
