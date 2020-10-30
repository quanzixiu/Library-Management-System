#include "bookmanager.h"
#include "ui_bookmanager.h"

BookManager::BookManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookManager)
{
    ui->setupUi(this);
}

BookManager::~BookManager()
{
    delete ui;
}
void BookManager::on_gotomainpage_clicked()
{
    this->close();
    MainPage *mp=new MainPage();
    mp->show();
}
void BookManager::on_exitlogin_clicked()
{
    this->close();
    OneWelcomeW* oww=new OneWelcomeW();
    oww->show();
}
void BookManager::on_addbooks_clicked()
{
    this->close();
    BookManager *bm=new BookManager();
    bm->show();
}
void BookManager::on_updatebooks_clicked()
{
    this->close();
    BookUpdate *bu=new BookUpdate();
    bu->show();
}
void BookManager::on_deletebooks_clicked()
{
    this->close();
    BookDelete *bd=new BookDelete();
    bd->show();
}
void BookManager::on_confirmsure_clicked()
{
    //调用添加书籍函数
    QString id=this->ui->le_id->text();
    QString isbn=this->ui->le_isbn->text();
    QString writer=this->ui->le_writer->text();
    QString bookname=this->ui->le_bookname->text();
    QString type=this->ui->le_type->text();
    if(id!=NULL&&isbn!=NULL&&writer!=NULL&&bookname!=NULL&&type!=NULL){
        int idstr=id.toInt();
        string isbnstr=isbn.toStdString();
        string writerstr=writer.toStdString();
        string booknamestr=bookname.toStdString();
        string typestr=type.toStdString();
        if(idstr>=0&&isbnstr!=""&&writerstr!=""&&booknamestr!=""&&typestr!=""){
            bool flag=false;
            supervisor sup;
            flag=sup.createbook(idstr,isbnstr,booknamestr,writerstr,typestr);
            if(flag){
                int rowind=this->ui->infotable->rowCount();
                //qDebug()<<rowind;

                /*for(int i=0;i<n;i++)
                 * this*/

                this->ui->infotable->insertRow(rowind);
                this->ui->infotable->setItem(rowind,0,new QTableWidgetItem(id));
                this->ui->infotable->setItem(rowind,1,new QTableWidgetItem(isbn));
                this->ui->infotable->setItem(rowind,2,new QTableWidgetItem(bookname));
                this->ui->infotable->setItem(rowind,3,new QTableWidgetItem(writer));
                this->ui->infotable->setItem(rowind,4,new QTableWidgetItem(type));
                this->ui->le_id->clear();
                this->ui->le_isbn->clear();
                this->ui->le_writer->clear();
                this->ui->le_bookname->clear();
                this->ui->le_type->clear();
            }
            else {
                QMessageBox::information(this,"提示","图书ID存在");
            }
        }

    }

}
