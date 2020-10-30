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
        QString password=this->ui->le_password->text();
        QString school = this->ui->le_school->text();
        QString major = this->ui->le_major->text();
        QString email = this->ui->le_email->text();
        if(id!=NULL&&name!=NULL&&school!=NULL&&major!=NULL&&email!=NULL){ //均不为空
            int rowind = this->ui->infotable->rowCount();
            int idstr=id.toInt();
            string namestr=name.toStdString();
            string passwordstr=password.toStdString();
            string schoolstr=school.toStdString();
            string majorstr=major.toStdString();
            string emailstr=email.toStdString();
            if(idstr>=0&&namestr!=""&&passwordstr!=""&&schoolstr!=""&&majorstr!=""&&emailstr!=""){
                bool flag=false;
                supervisor sup;
                flag=sup.createuser(idstr,namestr,passwordstr,schoolstr,majorstr,emailstr);
                qDebug()<<flag;
                if(flag){
                    //qDebug()<<rowind;
                    this->ui->infotable->insertRow(rowind);
                    this->ui->infotable->setItem(rowind, 0, new QTableWidgetItem(id));
                    this->ui->infotable->setItem(rowind, 1, new QTableWidgetItem(name));
                    this->ui->infotable->setItem(rowind, 2, new QTableWidgetItem(password));
                    this->ui->infotable->setItem(rowind, 3, new QTableWidgetItem(school));
                    this->ui->infotable->setItem(rowind, 4, new QTableWidgetItem(major));
                    this->ui->infotable->setItem(rowind, 5, new QTableWidgetItem(email));
                    this->ui->le_id->clear();
                    this->ui->le_name->clear();
                    this->ui->le_password->clear();
                    this->ui->le_school->clear();
                    this->ui->le_major->clear();
                    this->ui->le_email->clear();
                }
                else {
                    QMessageBox::information(this,"提示","用户存在");
                }
            }
        }
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
