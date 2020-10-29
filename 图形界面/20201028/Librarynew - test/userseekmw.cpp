#include "userseekmw.h"
#include "ui_userseekmw.h"

#include "o11userwid.h"
#include "objtwologin.h"

#include "obookcard.h"
UserSeekMw::UserSeekMw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserSeekMw)
{
    ui->setupUi(this);
}

UserSeekMw::~UserSeekMw()
{
    delete ui;
}
//首页按钮
void UserSeekMw::on_usershouye_button_clicked()
{
    this->hide();
    O11userwid::p_obj11->show();
}
//退出按钮
void UserSeekMw::on_return_button_clicked()
{
    this->hide();
    Objtwologin::p_objtwo->show();
}
//借书卡按钮
void UserSeekMw::on_bookcard_button_clicked()
{
    this->hide();
    ObookCard::p_objcard->show();
}

void UserSeekMw::on_seekok_button_clicked()
{

        //查找函数待填
    if(true)
    {
        //初始化表格
            QString id="123";
            QString isbn="45";
            QString writer="78";
            QString bookname="810";
            QString type="91";
            int row=this->ui->infobook_tablewid->rowCount();
            this->ui->infobook_tablewid->insertRow(row);
            //this->ui->infobook_tablewid->insertRow(row);
            this->ui->infobook_tablewid->setItem(row,0,new QTableWidgetItem(id));
            this->ui->infobook_tablewid->setItem(row,1,new QTableWidgetItem(isbn));
            this->ui->infobook_tablewid->setItem(row,2,new QTableWidgetItem(writer));
            this->ui->infobook_tablewid->setItem(row,3,new QTableWidgetItem(bookname));
            this->ui->infobook_tablewid->setItem(row,4,new QTableWidgetItem(type));
    }
    else
    {
        QMessageBox::warning(this,"警告","您输入的id不在查找范围，请重新输入");
    }

    /*QString id=this->ui->le_id->text();
    QString isbn=this->ui->le_isbn->text();
    QString writer=this->ui->le_writer->text();
    QString bookname=this->ui->le_bookname->text();
    QString type=this->ui->le_type->text();
    int rowind=this->ui->infotable->rowCount();
    //qDebug()<<rowind;
    this->ui->infotable->insertRow(rowind);
    this->ui->infotable->setItem(rowind,0,new QTableWidgetItem(id));
    this->ui->infotable->setItem(rowind,1,new QTableWidgetItem(isbn));
    this->ui->infotable->setItem(rowind,2,new QTableWidgetItem(writer));
    this->ui->infotable->setItem(rowind,3,new QTableWidgetItem(bookname));
    this->ui->infotable->setItem(rowind,4,new QTableWidgetItem(type));
    this->ui->le_id->clear();
    this->ui->le_isbn->clear();
    this->ui->le_writer->clear();
    this->ui->le_bookname->clear();
    this->ui->le_type->clear();*/
}

void UserSeekMw::on_borrowok_button_clicked()
{
    //学生id和图书id获取
    QString student_id=Objtwologin::p_objtwo->GetId();
    QString book_id=this->ui->id_linedit->text();
    //判断学生是否可借书籍，超过上限函数待填
    if(true)
    {
        QMessageBox::information(this,"提示","借书成功");
        //学生借阅图书保存函数待填
    }
    else
    {
        QMessageBox::warning(this,"警告","您已超出借书上限，暂时无法借书");
    }
}
