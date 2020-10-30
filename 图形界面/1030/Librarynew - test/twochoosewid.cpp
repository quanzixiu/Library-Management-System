#include "twochoosewid.h"
#include "ui_twochoosewid.h"

#include "twologind.h"
#include "userreturnwid.h"
#include "loginonewid.h"
TwoChooseWid::TwoChooseWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TwoChooseWid)
{
    ui->setupUi(this);
}

TwoChooseWid::~TwoChooseWid()
{
    delete ui;
}

void TwoChooseWid::on_manager_button_clicked()
{
    this->hide();
    TwoLoginD *p_manlogin=new TwoLoginD();
    p_manlogin->show();
}

void TwoChooseWid::on_user_button_clicked()
{
    this->hide();
    LoginOneWid *p_userlogin=new LoginOneWid();
    p_userlogin->show();
}

void TwoChooseWid::on_returnsystem_button_clicked()
{
    this->hide();
    UserReturnWid *p_rebook=new UserReturnWid();
    p_rebook->show();
}

void TwoChooseWid::on_return_button_clicked()
{
    this->hide();
}
