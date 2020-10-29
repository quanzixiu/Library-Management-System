#include "bookmanager.h"
#include "ui_bookmanager.h"

bookmanager::bookmanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookmanager)
{
    ui->setupUi(this);
}

bookmanager::~bookmanager()
{
    delete ui;
}
void bookmanager::on_gotomainpage_clicked()
{
    this->close();
    mainpage *mp=new mainpage();
    mp->show();
}
void bookmanager::on_exitlogin_clicked()
{
    this->close();
}
void bookmanager::on_addbooks_clicked()
{
    this->close();
    bookmanager *bm=new bookmanager();
    bm->show();
}
void bookmanager::on_updatebooks_clicked()
{
    this->close();
    bookupdate *bu=new bookupdate();
    bu->show();
}
void bookmanager::on_deletebooks_clicked()
{
    this->close();
    bookdelete *bd=new bookdelete();
    bd->show();
}
void bookmanager::on_confirmsure_clicked()
{
    QString id=this->ui->le_id->text();
    QString isbn=this->ui->le_isbn->text();
    QString writer=this->ui->le_writer->text();
    QString bookname=this->ui->le_bookname->text();
    QString type=this->ui->le_type->text();
    int rowind=this->ui->infotable->rowCount();
    //qDebug()<<rowind;
    this->ui->infotable->insertRow(rowind);
    this->ui->infotable->setItem(rowind,0,new QTableWidgetItem(id));
    this->ui->infotable->setItem(rowind,1,new QTableWidgetItem(isbn));
    this->ui->infotable->setItem(rowind,2,new QTableWidgetItem(writer));
    this->ui->infotable->setItem(rowind,3,new QTableWidgetItem(bookname));
    this->ui->infotable->setItem(rowind,4,new QTableWidgetItem(type));
    this->ui->le_id->clear();
    this->ui->le_isbn->clear();
    this->ui->le_writer->clear();
    this->ui->le_bookname->clear();
    this->ui->le_type->clear();
}
void bookmanager::on_addsure_clicked()
{
    //调用添加书籍函数
}
