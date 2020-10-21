#include "mainpage.h"
#include "ui_mainpage.h"
#include "chooseform.h"
mainpage::mainpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainpage)
{
    ui->setupUi(this);
}

mainpage::~mainpage()
{
    delete ui;
}
void mainpage::on_usermanagement_clicked()
{
    this->hide();
    usermanager *um=new usermanager();
    um->show();
}
void mainpage::on_bookmanagement_clicked()
{
    this->hide();
    bookmanager *bm=new bookmanager();
    bm->show();
}

void mainpage::on_exitlogin_clicked()
{
    this->close(); //退出
}
