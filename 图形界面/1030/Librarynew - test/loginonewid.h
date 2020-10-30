#ifndef LOGINONEWID_H
#define LOGINONEWID_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <string>
namespace Ui {
class LoginOneWid;
}

class LoginOneWid : public QWidget
{
    Q_OBJECT

public:
    explicit LoginOneWid(QWidget *parent = 0);
    ~LoginOneWid();
QString GetId();
QString GetPassword();
private slots:
    void on_login_button_clicked();

    void on_return_button_clicked();

private:
    Ui::LoginOneWid *ui;
};

#endif // LOGINONEWID_H
