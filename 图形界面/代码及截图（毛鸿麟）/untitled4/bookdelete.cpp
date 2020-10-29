#include "bookdelete.h"
#include "ui_bookdelete.h"

bookdelete::bookdelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookdelete)
{
    ui->setupUi(this);
}

bookdelete::~bookdelete()
{
    delete ui;
}
void bookdelete::on_addbooks_clicked()
{
    this->close();
    bookmanager *bm=new bookmanager();
    bm->show();
}
void bookdelete::on_updatebooks_clicked()
{
    this->close();
    bookupdate *bu=new bookupdate();
    bu->show();
}
void bookdelete::on_deletebooks_clicked()
{
    this->close();
    bookdelete *bd=new bookdelete();
    bd->show();
}
void bookdelete::on_gotomainpage_clicked()
{
    this->close();
    mainpage *mp=new mainpage();
    mp->show();
}
void bookdelete::on_exitlogin_clicked()
{
    this->close();
}
void bookdelete::on_deletesure_clicked()
{
    //调用删除书籍函数
}
void bookdelete::on_confirmsure_clicked()
{

}
