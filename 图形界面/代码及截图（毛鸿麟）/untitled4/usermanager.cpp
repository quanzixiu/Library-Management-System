#include "usermanager.h"
#include "ui_usermanager.h"
#include "chooseform.h"
usermanager::usermanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usermanager)
{
    ui->setupUi(this);
}

usermanager::~usermanager()
{
    delete ui;
}
void usermanager::on_gotomainpage_clicked()
{
    this->hide();
    mainpage *mp=new mainpage();
    mp->show();
}
void usermanager::on_exitlogin1_clicked()
{
    this->close();
}
void usermanager::on_confirmsure_clicked()
{
    QString id=this->ui->le_id->text();
    QString name=this->ui->le_name->text();
    QString school=this->ui->le_school->text();
    QString major=this->ui->le_major->text();
    QString email=this->ui->le_email->text();
    int rowind=this->ui->infotable->rowCount();
    //qDebug()<<rowind;
    this->ui->infotable->insertRow(rowind);
    this->ui->infotable->setItem(rowind,0,new QTableWidgetItem(id));
    this->ui->infotable->setItem(rowind,1,new QTableWidgetItem(name));
    this->ui->infotable->setItem(rowind,2,new QTableWidgetItem(school));
    this->ui->infotable->setItem(rowind,3,new QTableWidgetItem(major));
    this->ui->infotable->setItem(rowind,4,new QTableWidgetItem(email));
    this->ui->le_id->clear();
    this->ui->le_name->clear();
    this->ui->le_school->clear();
    this->ui->le_major->clear();
    this->ui->le_email->clear();
}
void usermanager::on_addusers_clicked()
{

}
void usermanager::on_updateusers_clicked()
{

}
void usermanager::on_deleteusers_clicked()
{

}
void usermanager::on_addsure_clicked()
{
    //调用添加用户函数
}
