#include "bookupdate.h"
#include "ui_bookupdate.h"

bookupdate::bookupdate(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::bookupdate)
{
	ui->setupUi(this);
}

bookupdate::~bookupdate()
{
	delete ui;
}
void bookupdate::on_confirm1_clicked()
{
	//提供以图书ID为参数的“验证图书是否存在”的函数
}
void bookupdate::on_confirm2_clicked()
{

}
void bookupdate::on_updatesure_clicked()
{

}
void bookupdate::on_gotomainpage_clicked()
{
	this->close();
	mainpage* mp = new mainpage();
	mp->show();
}
void bookupdate::on_returnbookmanager_clicked()
{
	this->close();
	bookmanager* bm = new bookmanager();
	bm->show();
}
void bookupdate::on_updateid_clicked()
{
	this->setchoice(1);
	const QString str = "请输入修改的信息：图书ID";
	this->ui->inputinfo->setPlaceholderText(str);
}

void bookupdate::on_updateisbn_clicked()
{
	this->setchoice(2);
	const QString str = "请输入修改的信息：图书ISBN";
	this->ui->inputinfo->setPlaceholderText(str);
}

void bookupdate::on_updatebookname_clicked()
{
	this->setchoice(3);
	const QString str = "请输入修改的信息：图书名字";
	this->ui->inputinfo->setPlaceholderText(str);
}

void bookupdate::on_updatewriter_clicked()
{
	this->setchoice(4);
	const QString str = "请输入修改的信息：图书作者";
	this->ui->inputinfo->setPlaceholderText(str);
}

void bookupdate::on_updatebooktype_clicked()
{
	this->setchoice(5);
	const QString str = "请输入修改的信息：图书类型";
	this->ui->inputinfo->setPlaceholderText(str);
}

void bookupdate::on_updateshelf_clicked()
{
	this->setchoice(6);
	const QString str = "请输入修改的信息：图书在架信息";
	this->ui->inputinfo->setPlaceholderText(str);
}

void bookupdate::on_updatestatus_clicked()
{
	this->setchoice(7);
	const QString str = "请输入修改的信息：图书借阅状态";
	this->ui->inputinfo->setPlaceholderText(str);
}
