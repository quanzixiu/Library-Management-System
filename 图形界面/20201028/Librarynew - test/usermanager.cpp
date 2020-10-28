#include "usermanager.h"
#include "ui_usermanager.h"

UserManager::UserManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManager)
{
    ui->setupUi(this);
}

UserManager::~UserManager()
{
    delete ui;
}
void UserManager::on_gotomainpage_clicked()
{
    this->close();
    MainPage* mp = new MainPage();
    mp->show();
}
void UserManager::on_exitlogin1_clicked()
{
    this->close();
    OneWelcomeW* oww=new OneWelcomeW();
    oww->show();
}
void UserManager::on_confirmsure_clicked()
{
    QString id = this->ui->le_id->text();
    QString name = this->ui->le_name->text();
    QString school = this->ui->le_school->text();
    QString major = this->ui->le_major->text();
    QString email = this->ui->le_email->text();
    int rowind = this->ui->infotable->rowCount();
    //qDebug()<<rowind;
    this->ui->infotable->insertRow(rowind);
    this->ui->infotable->setItem(rowind, 0, new QTableWidgetItem(id));
    this->ui->infotable->setItem(rowind, 1, new QTableWidgetItem(name));
    this->ui->infotable->setItem(rowind, 2, new QTableWidgetItem(school));
    this->ui->infotable->setItem(rowind, 3, new QTableWidgetItem(major));
    this->ui->infotable->setItem(rowind, 4, new QTableWidgetItem(email));
    this->ui->le_id->clear();
    this->ui->le_name->clear();
    this->ui->le_school->clear();
    this->ui->le_major->clear();
    this->ui->le_email->clear();
}
void UserManager::on_addusers_clicked()
{
    this->close();
    UserManager* um = new UserManager();
    um->show();
}
void UserManager::on_updateusers_clicked()
{
    this->close();
    UserUpdate* uu = new UserUpdate();
    uu->show();
}
void UserManager::on_deleteusers_clicked()
{
    this->close();
    UserDelete* ud = new UserDelete();
    ud->show();
}
void UserManager::on_addsure_clicked()
{
    //调用添加用户函数
}
