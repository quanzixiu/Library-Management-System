#include "userdelete.h"
#include "ui_userdelete.h"

userdelete::userdelete(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::userdelete)
{
	ui->setupUi(this);
}

userdelete::~userdelete()
{
	delete ui;
}
void userdelete::on_gotomainpage_clicked()
{
	this->close();
	mainpage* mp = new mainpage();
	mp->show();
}
void userdelete::on_exitlogin_clicked()
{
	this->close();
}
void userdelete::on_confirmsure_clicked()
{

}
void userdelete::on_addusers_clicked()
{
	this->close();
	usermanager* um = new usermanager();
	um->show();
}
void userdelete::on_updateusers_clicked()
{
	this->close();
	updateuser* uu = new updateuser();
	uu->show();
}
void userdelete::on_deleteusers_clicked()
{
	this->close();
	userdelete* ud = new userdelete();
	ud->show();
}
void userdelete::on_deletesure_clicked()
{
	//调用删除用户函数
}
