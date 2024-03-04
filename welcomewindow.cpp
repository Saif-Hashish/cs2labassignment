#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow( QString username, int age, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

     QString ages = QString::number(age);

     ui->label_hello->setText("Hello " + username + " " + ages);

    QPixmap pix(":/new/prefix1/pic3/cinema-rex.jpg");
    int w = ui->label_welcome_image->width();
    int h = ui->label_welcome_image->height();
    ui->label_welcome_image-> setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));




}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_push_logout_clicked()
{
hide();
LoginWindow *s =new LoginWindow(this);
s->show();
}
