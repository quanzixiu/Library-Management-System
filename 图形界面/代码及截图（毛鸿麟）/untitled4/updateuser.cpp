#include "updateuser.h"
#include "ui_updateuser.h"

updateuser::updateuser(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::updateuser)
{
	ui->setupUi(this);
}

updateuser::~updateuser()
{
	delete ui;
}

void updateuser::on_gotomainpage_clicked()
{
	this->close();
	mainpage* mp = new mainpage();
	mp->show();
}
void updateuser::on_returnusermanager_clicked()
{
	this->close();
	usermanager* um = new usermanager();
	um->show();
}

void updateuser::on_updateid_clicked()
{
	this->setchoice(1);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改ID";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void updateuser::on_updatename_clicked()
{
	this->setchoice(2);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改姓名";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void updateuser::on_updateschool_clicked()
{
	this->setchoice(3);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改学校";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void updateuser::on_updatemajor_clicked()
{
	this->setchoice(4);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改专业";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void updateuser::on_updateemail_clicked()
{
	this->setchoice(5);
	const QString infomation = "输入要修改的信息：";
	QString addstr = "修改邮箱";
	QString str = infomation + addstr;
	this->ui->inputinfo->setPlaceholderText(str);
}
void updateuser::on_confirm1_clicked()
{
	//提供以用户ID为参数的“验证用户是否存在”的函数
}
void updateuser::on_confirm2_clicked()
{

}
void updateuser::on_updatesure_clicked()
{

}
