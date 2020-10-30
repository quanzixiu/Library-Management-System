#include "loginonewid.h"
#include "ui_loginonewid.h"

#include "o11userwid.h"
#include "otwochoose.h"
LoginOneWid::LoginOneWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginOneWid)
{
    ui->setupUi(this);
}

LoginOneWid::~LoginOneWid()
{
    delete ui;
}
//得到用户账号
QString LoginOneWid::GetId()
{
    return ui->id_linedit->text();
}
//得到用户密码
QString LoginOneWid::GetPassword()
{
    return ui->password_linedit->text();
}

//验证用户登录
void LoginOneWid::on_login_button_clicked()
{
    if(ui->id_linedit->text().size()>8)
   {
        QMessageBox::warning(this,"警告","您输入的账号或密码有误");
    }
    else
    {
        //用户登录验证函数待填
        this->hide();
        O11userwid::p_obj11->show();

    }
}
//退出按钮
void LoginOneWid::on_return_button_clicked()
{
    this->hide();
    Otwochoose::p_otwochoose->show();
}
