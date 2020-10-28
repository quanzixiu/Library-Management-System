#include "userdelete.h"
#include "ui_userdelete.h"

UserDelete::UserDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserDelete)
{
    ui->setupUi(this);
}

UserDelete::~UserDelete()
{
    delete ui;
}
void UserDelete::on_gotomainpage_clicked()
{
    this->close();
    MainPage* mp = new MainPage();
    mp->show();
}
void UserDelete::on_exitlogin_clicked()
{
    this->close();
    OneWelcomeW* oww=new OneWelcomeW();
    oww->show();
}
void UserDelete::on_confirmsure_clicked()
{

}
void UserDelete::on_addusers_clicked()
{
    this->close();
    UserManager* um = new UserManager();
    um->show();
}
void UserDelete::on_updateusers_clicked()
{
    this->close();
    UserUpdate* uu = new UserUpdate();
    uu->show();
}
void UserDelete::on_deleteusers_clicked()
{
    this->close();
    UserDelete* ud = new UserDelete();
    ud->show();
}
void UserDelete::on_deletesure_clicked()
{
    //调用删除用户函数
}
