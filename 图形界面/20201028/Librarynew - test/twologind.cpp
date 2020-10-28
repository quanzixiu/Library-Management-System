#include "twologind.h"
#include "ui_twologind.h"
#include "objone.h"
#include "o11userwid.h"
TwoLoginD::TwoLoginD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoLoginD)
{
    ui->setupUi(this);
    ui->id_linedit->setFocus();
    ui->login_button->setDefault(true);
    ui->id_linedit->clear();
    ui->password_linedit->clear();

}
//返回用户输入的ID
QString TwoLoginD::GetId()
{
    return ui->id_linedit->text();
}
//返回用户输入的password
QString TwoLoginD::GetPassword()
{
    return ui->password_linedit->text();
}

TwoLoginD::~TwoLoginD()
{
    delete ui;
}

void TwoLoginD::on_login_button_clicked()
{
    if(ui->id_linedit->text().isEmpty()||ui->password_linedit->text().isEmpty())
    {
        QMessageBox::information(this,"提示","您还没有输入账号或密码");
        ui->id_linedit->setFocus();//鼠标定位到当前位置？
    }
     if(ui->checkBox->isChecked()==true)
     {
         //test_begin
         QDialog::accept();
         ui->id_linedit->clear();
         ui->password_linedit->clear();
         MainPage *p_manshouye=new MainPage();
         p_manshouye->show();
         //test_end
      //需要管理员身份验证函数
       /* if(login(ui->id_linedit->text(),ui->password_linedit->text()))
        {
            QDialog::accept();
        }
        else
        {
            QMessageBox::warning(this,"账号或密码错误","请重新输入");
            ui->manID->clear();
            ui->manpassword->clear();
            ui->manID->setFocus();
        }
      }
    else
     {
         //需要用户身份验证函数
         if(login(ui->id_linedit->text(),ui->password_linedit->text()))
         {
             QDialog::accept();
         }
         else
         {
             QMessageBox::warning(this,"账号或密码错误","请重新输入");
             ui->manID->clear();
             ui->manpassword->clear();
             ui->manID->setFocus();
         }*/
     }
     //test_begin
     if(ui->checkBox->isChecked()==false)
     {
        QDialog::accept();
        O11userwid::p_obj11->show();
        ui->id_linedit->clear();
        ui->password_linedit->clear();
     }
     //test-end
}
//
void TwoLoginD::on_return_button_clicked()
{
    QDialog::reject();
    Objone::p_objone->show();
}
