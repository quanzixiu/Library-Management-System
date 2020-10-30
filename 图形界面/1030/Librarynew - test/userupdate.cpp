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

void UserUpdate::on_updatepassword_clicked()
{
	this->setchoice(1);
	const QString infomation = "输入要修改的信息：";
    QString addstr = "修改密码";
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
    QString id=this->ui->inputid->text(); //获取ID
    if(id!=NULL){
        int idnum=id.toInt();
        userdocking ud;
        bool flag=ud.userexist(idnum);
        if(!flag){
            QMessageBox::information(this,"提示","用户不存在");
            this->ui->inputid->clear();
        }
        else{
            QMessageBox::information(this,"提示","用户存在，请修改");
        }

        this->setexist(flag);
        //qDebug()<<flag;

    }

}
void UserUpdate::on_confirm2_clicked()
{
    QString id=this->ui->inputid->text(); //获取ID
    int rowind=this->ui->infotable->rowCount();
    QString inf=this->ui->inputinfo->text();
    bool flag=this->getexist();
    if(inf!=NULL&&flag){ //输入信息不为空且用户存在
        supervisor s;
        int idnum=id.toInt();
        string value=s.DisplayUser(idnum);
        if(value!=""){ //不为空
            bool success=false; //是否成功
            string name = value.substr(0, 8);
            string college = value.substr(8, 4);
            string major = value.substr(12, 4);
            string password = value.substr(16, 16);
            string email = value.substr(32, 24);

            int cho=this->getchoice();
            switch (cho) {
            case 1:
                password=inf.toStdString();
                success=s.modifyuserPassword(idnum,password);
                break;
            case 2:
                name=inf.toStdString();
                success=s.modifybookName(idnum,name);
                break;
            case 3:
                college=inf.toStdString();
                success=s.modifyuserCollege(idnum,college);
                break;
            case 4:
                major=inf.toStdString();
                success=s.modifyuserMajor(idnum,major);
                break;
            case 5:
                email=inf.toStdString();
                success=s.modifyuserEmail(idnum,email);
                break;
            default:
                break;
            }
            //qDebug()<<success;
            if(success){
                //value=s->DisplayUser(idnum);
                //name = value.substr(0, 8);
                //college = value.substr(8, 4);
                //major = value.substr(12, 4);
                //password = value.substr(16, 16);
                //email = value.substr(32, 24);
                QString namestr=QString::fromStdString(name);
                QString collegestr=QString::fromStdString(college);
                QString majorstr=QString::fromStdString(major);
                QString passwordstr=QString::fromStdString(password);
                QString emailstr=QString::fromStdString(email);
                this->ui->infotable->insertRow(rowind);
                this->ui->infotable->setItem(rowind, 0, new QTableWidgetItem(id));
                this->ui->infotable->setItem(rowind, 1, new QTableWidgetItem(namestr));
                this->ui->infotable->setItem(rowind, 2, new QTableWidgetItem(passwordstr));
                this->ui->infotable->setItem(rowind, 3, new QTableWidgetItem(collegestr));
                this->ui->infotable->setItem(rowind, 4, new QTableWidgetItem(majorstr));
                this->ui->infotable->setItem(rowind, 5, new QTableWidgetItem(emailstr));
            }
        }

    }
    this->ui->inputid->clear();
    this->ui->inputinfo->clear();
}

