#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QDialog>

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomeWindow( QString username, int age, QWidget *parent = nullptr);
    explicit WelcomeWindow( QWidget *parent = nullptr);
    ~WelcomeWindow();

private slots:
    void on_push_logout_clicked();

private:
    Ui::WelcomeWindow *ui;
};

#endif // WELCOMEWINDOW_H
