#include "bookupdate.h"
#include "ui_bookupdate.h"

BookUpdate::BookUpdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookUpdate)
{
    ui->setupUi(this);
}

BookUpdate::~BookUpdate()
{
    delete ui;
}
void BookUpdate::on_confirm1_clicked()
{
    //提供以图书ID为参数的“验证图书是否存在”的函数
    int id=this->ui->inputid->text().toInt();
    supervisor s;
    string dsp=s.DisplayBook(id);
    if(dsp=="不存在该图书"){
        QString dspstr=QString::fromStdString(dsp);
        QMessageBox::information(this,"提示",dspstr);
    }
    else{
        QString infstr=this->ui->inputinfo->text();
        QString dspstr=QString::fromStdString(dsp);
        QMessageBox::information(this,"提示",dspstr);
        bookdocking docking;
        //展示图书信息
        string value = docking.booksearch(id);
        bool success=false;
        //把得到的包含所有信息的字符串分发给各个字段
        string ISBN = value.substr(0, 6);
        string name = value.substr(6, 8);
        string author = value.substr(14, 4);
        string type = value.substr(18, 4);
        string borrowtime = value.substr(22, 8);
        string returntime = value.substr(30, 8);
        string history = value.substr(38, 40);
        string onsheelf = value.substr(78, 1);
        string isovertime = value.substr(79, 1);

        int cho=this->getchoice();
        switch (cho) {
        case 1:
            ISBN=infstr.toStdString();
            success=s.modifybookISBN(id,ISBN);
            break;
        case 2:
            name=infstr.toStdString();
            success=s.modifybookName(id,name);
            break;
        case 3:
            author=infstr.toStdString();
            success=s.modifybookAuthor(id,author);
            break;
        case 4:
            type=infstr.toStdString();
            success=s.modifybookType(id,type);
            break;
        case 5:
            onsheelf=infstr.toStdString();
            success=s.modifybookOnsheelf(id,onsheelf);
            break;
        case 6:
            isovertime=infstr.toStdString();
            success=s.modifybookIsovertime(id,isovertime);
            break;
        default:
            break;
        }
        if(success){
            QString ISBNstr=QString::fromStdString(ISBN);
            QString namestr=QString::fromStdString(name);
            QString authorstr=QString::fromStdString(author);
            QString typestr=QString::fromStdString(type);
            QString borrowtimestr=QString::fromStdString(borrowtime);
            QString returntimestr=QString::fromStdString(returntime);
            QString historystr=QString::fromStdString(history);
            QString onsheelfstr=QString::fromStdString(onsheelf);
            QString isovertimestr=QString::fromStdString(isovertime);
            int rowind = this->ui->infotable->rowCount();
            //qDebug()<<rowind;
            this->ui->infotable->insertRow(rowind);
            this->ui->infotable->setItem(rowind, 0, new QTableWidgetItem(ISBNstr));
            this->ui->infotable->setItem(rowind, 1, new QTableWidgetItem(namestr));
            this->ui->infotable->setItem(rowind, 2, new QTableWidgetItem(authorstr));
            this->ui->infotable->setItem(rowind, 3, new QTableWidgetItem(typestr));
            this->ui->infotable->setItem(rowind, 4, new QTableWidgetItem(onsheelfstr));
            this->ui->infotable->setItem(rowind, 5, new QTableWidgetItem(isovertimestr));
        }
    }
}
void BookUpdate::on_gotomainpage_clicked()
{
    this->close();
    MainPage* mp = new MainPage();
    mp->show();
}
void BookUpdate::on_returnbookmanager_clicked()
{
    this->close();
    BookManager* bm = new BookManager();
    bm->show();
}

void BookUpdate::on_updateisbn_clicked()
{
    this->setchoice(1);
    const QString str = "请输入修改的信息：图书ISBN";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updatebookname_clicked()
{
    this->setchoice(2);
    const QString str = "请输入修改的信息：图书名字";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updatewriter_clicked()
{
    this->setchoice(3);
    const QString str = "请输入修改的信息：图书作者";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updatebooktype_clicked()
{
    this->setchoice(4);
    const QString str = "请输入修改的信息：图书类型";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updateshelf_clicked()
{
    this->setchoice(5);
    const QString str = "请输入修改的信息：图书在架信息";
    this->ui->inputinfo->setPlaceholderText(str);
}

void BookUpdate::on_updatestatus_clicked()
{
    this->setchoice(6);
    const QString str = "请输入修改的信息：图书借阅状态";
    this->ui->inputinfo->setPlaceholderText(str);
}
