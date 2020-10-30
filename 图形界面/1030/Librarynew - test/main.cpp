#include <QApplication>
#include "objone.h"//欢迎
#include "otwochoose.h"//用户及管理员选择菜单
#include "objtwologin.h"//管理员登录
#include "objuserlogin.h"//用户登录
#include "o11userwid.h"//用户首页
#include "ouserseek.h"//查找借阅图书
#include "ouserborrowed.h"//已借图书
#include "ouserreturn.h"//归还图书
#include "obookcard.h"//借书卡

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* OneWelcomeW w;
    w.show();*/
 Objone::Init();
 Otwochoose::Init();
 Objtwologin::Init();
 O11userwid::Init();
 OuserSeek::Init();
 OuserBorrowed::Init();
 OuserReturn::Init();
 ObookCard::Init();
 ObjuserLogin::Init();
 Objone::p_objone->show();
    return a.exec();
}
