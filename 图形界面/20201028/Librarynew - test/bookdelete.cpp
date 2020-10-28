#include "bookdelete.h"
#include "ui_bookdelete.h"

BookDelete::BookDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookDelete)
{
    ui->setupUi(this);
}

BookDelete::~BookDelete()
{
    delete ui;
}
void BookDelete::on_addbooks_clicked()
{
    this->close();
    BookManager *bm=new BookManager();
    bm->show();
}
void BookDelete::on_updatebooks_clicked()
{
    this->close();
    BookUpdate *bu=new BookUpdate();
    bu->show();
}
void BookDelete::on_deletebooks_clicked()
{
    this->close();
    BookDelete *bd=new BookDelete();
    bd->show();
}
void BookDelete::on_gotomainpage_clicked()
{
    this->close();
    MainPage *mp=new MainPage();
    mp->show();
}
void BookDelete::on_exitlogin_clicked()
{
    this->close();
    OneWelcomeW* oww=new OneWelcomeW();
    oww->show();
}
void BookDelete::on_deletesure_clicked()
{
    //调用删除书籍函数
}
void BookDelete::on_confirmsure_clicked()
{

}
