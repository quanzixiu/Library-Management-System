#include "usercradwid.h"
#include "ui_usercradwid.h"

#include "ouserseek.h"
UserCradWid::UserCradWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserCradWid)
{
    ui->setupUi(this);
}

UserCradWid::~UserCradWid()
{
    delete ui;
}
//返回查找借阅图书按钮
void UserCradWid::on_cardseek_button_clicked()
{
    this->hide();
    OuserSeek::p_oseek->show();
}

void UserCradWid::on_cardok_button_clicked()
{
    //判断该图书id是否存在函数
    QMessageBox::information(this,"提示","您输入的图书id有错误，请重新输入");
    //根据图书id查找借阅该书的学生id函数
    QString id="123";
    QString isbn="45";
    QString writer="78";
    QString bookname="810";
    QString type="91";
    int row=this->ui->card_table->rowCount();
    this->ui->card_table->insertRow(row);
    this->ui->card_table->insertRow(row);
    this->ui->card_table->setItem(row,0,new QTableWidgetItem(id));
    this->ui->card_table->insertRow(row);
    this->ui->card_table->setItem(row,0,new QTableWidgetItem(isbn));
    this->ui->card_table->insertRow(row);
    this->ui->card_table->setItem(row,0,new QTableWidgetItem(writer));
    this->ui->card_table->insertRow(row);
    this->ui->card_table->setItem(row,0,new QTableWidgetItem(bookname));
    this->ui->card_table->insertRow(row);
    this->ui->card_table->setItem(row,0,new QTableWidgetItem(type));
}
