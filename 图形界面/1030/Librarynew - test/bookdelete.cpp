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
void BookDelete::on_confirmsure_clicked()
{
    //调用删除书籍函数
    //提供以图书ID为参数的“验证图书是否存在”的函数
    int id=this->ui->le_id->text().toInt();
    supervisor s;
    string dsp=s.DisplayBook(id);
    if(dsp=="不存在该图书"){
        //QString dspstr=QString::fromStdString(dsp);
        QMessageBox::information(this,"提示","不存在该图书");
    }
    else{
        supervisor s;
        bool flag=s.deletebook(id);
        if(flag){
            QString dspstr=QString::fromStdString(dsp);
            this->ui->borrowinfotable->setPlainText("eyw\nowief");
            QMessageBox::information(this,"提示","删除图书成功");
        }
        this->ui->le_id->clear();
    }
}
