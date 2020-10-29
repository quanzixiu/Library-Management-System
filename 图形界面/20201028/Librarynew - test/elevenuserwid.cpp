#include "elevenuserwid.h"
#include "ui_elevenuserwid.h"
#include "objtwologin.h"
#include "ouserseek.h" //跳转查找借阅界面
#include "ouserborrowed.h" //跳转已借图书
#include "ouserreturn.h" //跳转归还图书
ElevenUserwid::ElevenUserwid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElevenUserwid)
{
    ui->setupUi(this);
}

ElevenUserwid::~ElevenUserwid()
{
    delete ui;
}

void ElevenUserwid::on_pushButton_4_clicked()
{
    this->hide();
    Objtwologin::p_objtwo->show();
}
//显示查找借阅界面
void ElevenUserwid::on_seek_button_clicked()
{
    this->hide();
    OuserSeek::p_oseek->show();
}
//显示已借图书界面
void ElevenUserwid::on_borrowed_button_clicked()
{
    this->hide();
    OuserBorrowed::p_oubored->show();
    OuserBorrowed::p_oubored->Init();
}
//显示归还图书界面
void ElevenUserwid::on_returnbook_button_clicked()
{
    this->hide();
    OuserReturn::p_oureturn->show();
}
//登录界面
void ElevenUserwid::on_relogin_button_clicked()
{
    this->hide();
    Objtwologin::p_objtwo->show();
}
