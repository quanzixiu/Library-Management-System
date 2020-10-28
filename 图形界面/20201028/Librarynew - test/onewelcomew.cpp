#include "ui_onewelcomew.h"
#include "onewelcomew.h"

#include "objtwologin.h"
OneWelcomeW::OneWelcomeW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OneWelcomeW)
{
    ui->setupUi(this);

}

OneWelcomeW::~OneWelcomeW()
{
    delete ui;
}

void OneWelcomeW::on_in_button_clicked()
{
    if(ui->in_checkbox->isChecked()==true)
    {
        ui->in_button->setEnabled(true);
        ui->in_checkbox->setChecked(false);//测试
        this->hide();  
        Objtwologin::p_objtwo->show();
    }
    else
    {
        ui->in_button->setEnabled(false);
        QMessageBox::information(this,"提示","您只有同意协议才能进入系统。");
    }
}
