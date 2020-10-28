#include "userreturnwid.h"
#include "ui_userreturnwid.h"

#include "ouserseek.h"
#include "objtwologin.h"
UserReturnWid::UserReturnWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserReturnWid)
{
    ui->setupUi(this);
}

UserReturnWid::~UserReturnWid()
{
    delete ui;
}
//查找借阅图书
void UserReturnWid::on_seekbor_button_clicked()
{
    this->hide();
    OuserSeek::p_oseek->show();
}
//退出登录按钮
void UserReturnWid::on_return_button_clicked()
{
    this->hide();
    Objtwologin::p_objtwo->show();
}

void UserReturnWid::on_returnok_button_clicked()
{
    //查找书籍函数待填
    //书籍信息返回函数待填
    QString id="123";
    QString isbn="45";
    QString writer="78";
    QString bookname="810";
    QString type="91";
    int row=this->ui->returninfo_table->rowCount();
    this->ui->returninfo_table->insertRow(row);
    this->ui->returninfo_table->insertRow(row);
    this->ui->returninfo_table->setItem(row,0,new QTableWidgetItem(id));
    this->ui->returninfo_table->setItem(row,1,new QTableWidgetItem(isbn));
    this->ui->returninfo_table->setItem(row,2,new QTableWidgetItem(writer));
    this->ui->returninfo_table->setItem(row,3,new QTableWidgetItem(bookname));
    this->ui->returninfo_table->setItem(row,4,new QTableWidgetItem(type));
}

void UserReturnWid::on_returnbook_button_clicked()
{
    //归还图书函数待填
    //userstatus函数待填
    QMessageBox::information(this,"提示","归还成功");
    QMessageBox::information(this,"提示","您归还图书已超期，请联系管理员");
}
