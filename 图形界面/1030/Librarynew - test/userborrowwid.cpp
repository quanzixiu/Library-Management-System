#include "userborrowwid.h"
#include "ui_userborrowwid.h"
#include "loginonewid.h"
UserBorrowWid::UserBorrowWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserBorrowWid)
{
    ui->setupUi(this);
}

UserBorrowWid::~UserBorrowWid()
{
    delete ui;
}
//退出登录按钮
void UserBorrowWid::on_pushButton_2_clicked()
{
    this->hide();
    LoginOneWid *p_loginuser=new LoginOneWid();
    p_loginuser->show();
}
