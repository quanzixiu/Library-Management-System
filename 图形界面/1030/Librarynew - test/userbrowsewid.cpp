#include "userbrowsewid.h"
#include "ui_userbrowsewid.h"

#include "userborrowwid.h"//借阅书籍
#include "elevenuserwid.h"//用户首页
UserBrowseWid::UserBrowseWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserBrowseWid)
{
    ui->setupUi(this);
}

UserBrowseWid::~UserBrowseWid()
{
    delete ui;
}
//返回首页按钮
void UserBrowseWid::on_reushouye_button_clicked()
{
    this->hide();
    ElevenUserwid *p_eleven=new ElevenUserwid();
    p_eleven->show();
}

//借阅按钮
void UserBrowseWid::on_seekbor_button_clicked()
{
    this->hide();
    UserBorrowWid *p_borrow=new UserBorrowWid();
    p_borrow->show();
}
