#include "userdelete.h"
#include "ui_userdelete.h"
//int idnum;
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
    QString id=this->ui->le_id->text();
    int idnum=id.toInt();
    qDebug()<<idnum;
    userdocking ud;
    bool flag=ud.userdelete(idnum);
    qDebug()<<flag;
    if (flag){
        supervisor s;
        string str=s.DisplayUserBookid(idnum);
        QString disstr=QString::fromStdString(str);
        this->ui->borrowinfotable->setPlainText("eyw\nowief");
        QMessageBox::information(this,"提示","删除用户成功");
        bool sure=s.deleteuser(idnum);
        qDebug()<<sure;
        if(1){

            this->ui->le_id->clear();
            //this->ui->borrowinfotable->clear();
        }

    }
    else{
        QMessageBox::information(this,"提示","删除用户失败");
        this->ui->le_id->clear();
    }
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
