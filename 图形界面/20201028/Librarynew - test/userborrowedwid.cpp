#include "userborrowedwid.h"
#include "ui_userborrowedwid.h"

#include "o11userwid.h"
#include "objtwologin.h"
UserBorrowedWid::UserBorrowedWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserBorrowedWid)
{
    ui->setupUi(this);
}

UserBorrowedWid::~UserBorrowedWid()
{
    delete ui;
}
//初始化界面
void UserBorrowedWid::Init()
{
QString student11_id=Objtwologin::p_objtwo->GetId();
QString student11_password=Objtwologin::p_objtwo->GetPassword();
//根据学生id查找所借书籍函数待填，共需所有书籍的返回信息
QString id="12";
QString isbn="45";
QString writer="78";
QString bookname="810";
QString type="91";
int row=this->ui->borrowed_table->rowCount();
this->ui->borrowed_table->insertRow(row);
this->ui->borrowed_table->insertRow(row);
this->ui->borrowed_table->setItem(row,0,new QTableWidgetItem(id));
this->ui->borrowed_table->setItem(row,1,new QTableWidgetItem(isbn));
this->ui->borrowed_table->setItem(row,2,new QTableWidgetItem(writer));
this->ui->borrowed_table->setItem(row,3,new QTableWidgetItem(bookname));
this->ui->borrowed_table->setItem(row,4,new QTableWidgetItem(type));
}

//首页按钮
void UserBorrowedWid::on_shouye_button_clicked()
{
    this->hide();
    O11userwid::p_obj11->show();
}
//退出登录按钮
void UserBorrowedWid::on_return_button_clicked()
{
    this->hide();
    Objtwologin::p_objtwo->show();
}
