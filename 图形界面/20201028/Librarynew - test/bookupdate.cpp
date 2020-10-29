#include "bookupdate.h"
#include "ui_bookupdate.h"

BookUpdate::BookUpdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookUpdate)
{
    ui->setupUi(this);
}

BookUpdate::~BookUpdate()
{
    delete ui;
}
void BookUpdate::on_confirm1_clicked()
{
    //提供以图书ID为参数的“验证图书是否存在”的函数
}
void BookUpdate::on_confirm2_clicked()
{

}
void BookUpdate::on_updatesure_clicked()
{

}
void BookUpdate::on_gotomainpage_clicked()
{
    this->close();
    MainPage* mp = new MainPage();
    mp->show();
}
void BookUpdate::on_returnbookmanager_clicked()
{
    this->close();
    BookManager* bm = new BookManager();
    bm->show();
}
void BookUpdate::on_updateid_clicked()
{
    this->setchoice(1);
    const QString str = "请输入修改的信息：图书ID";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updateisbn_clicked()
{
    this->setchoice(2);
    const QString str = "请输入修改的信息：图书ISBN";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updatebookname_clicked()
{
    this->setchoice(3);
    const QString str = "请输入修改的信息：图书名字";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updatewriter_clicked()
{
    this->setchoice(4);
    const QString str = "请输入修改的信息：图书作者";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updatebooktype_clicked()
{
    this->setchoice(5);
    const QString str = "请输入修改的信息：图书类型";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updateshelf_clicked()
{
    this->setchoice(6);
    const QString str = "请输入修改的信息：图书在架信息";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updatestatus_clicked()
{
    this->setchoice(7);
    const QString str = "请输入修改的信息：图书借阅状态";
    this->ui->inputinfo->setPlaceholderText(str);
}
