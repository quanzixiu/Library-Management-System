#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
}

MainPage::~MainPage()
{
    delete ui;
}
void MainPage::on_usermanagement_clicked()
{
    this->close();
    UserManager* um = new UserManager();
    um->show();
}
void MainPage::on_bookmanagement_clicked()
{
    this->close();
    BookManager* bm = new BookManager();
    bm->show();
}

void MainPage::on_exitlogin_clicked()
{
    this->close(); //退出
    OneWelcomeW* oww=new OneWelcomeW();
    oww->show();
}
