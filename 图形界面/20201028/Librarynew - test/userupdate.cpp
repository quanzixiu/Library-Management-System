#include "userupdate.h"
#include "ui_userupdate.h"

UserUpdate::UserUpdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserUpdate)
{
    ui->setupUi(this);
}

UserUpdate::~UserUpdate()
{
    delete ui;
}
void UserUpdate::on_gotomainpage_clicked()
{
	this->close();
	MainPage* mp = new MainPage();
	mp->show();
}
void UserUpdate::on_returnusermanager_clicked()
{
	this->close();
	UserManager* um = new UserManager();
	um->show();
}

void UserUpdate::on_updateid_clicked()
{
	this->setchoice(1);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改ID";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void UserUpdate::on_updatename_clicked()
{
	this->setchoice(2);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改姓名";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void UserUpdate::on_updateschool_clicked()
{
	this->setchoice(3);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改学校";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void UserUpdate::on_updatemajor_clicked()
{
	this->setchoice(4);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改专业";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void UserUpdate::on_updateemail_clicked()
{
	this->setchoice(5);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改邮箱";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void UserUpdate::on_confirm1_clicked()
{
	//提供以用户ID为参数的“验证用户是否存在”的函数
}
void UserUpdate::on_confirm2_clicked()
{

}
void UserUpdate::on_updatesure_clicked()
{

}
