#include "ui_onewelcomew.h"
#include "onewelcomew.h"

#include "twochoosewid.h"
OneWelcomeW::OneWelcomeW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OneWelcomeW)
{
    ui->setupUi(this);
    //ui->in_checkbox->setChecked(false);//取消选中
    ui->in_button->setEnabled(false);//
}

OneWelcomeW::~OneWelcomeW()
{
    delete ui;
}

void OneWelcomeW::on_in_button_clicked()
{

    if(ui->in_checkbox->isChecked()==true)
    {
        //ui->in_button->setEnabled(true);
        ui->in_checkbox->setChecked(false);//取消选中
        this->hide();  
       TwoChooseWid *p=new TwoChooseWid();
       p->show();
    }
    else
    {
        //ui->in_button->setEnabled(false);//进入按钮不可选中
        QMessageBox::information(this,"提示","您只有同意协议才能进入系统。");
    }
}

void OneWelcomeW::on_in_checkbox_clicked()
{
    ui->in_button->setEnabled(true);
}
