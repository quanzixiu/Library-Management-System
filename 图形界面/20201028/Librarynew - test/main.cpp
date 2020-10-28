#include <QApplication>
#include "objone.h"//欢迎
#include "objtwologin.h"//登录
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
 Objtwologin::Init();
 O11userwid::Init();
 OuserSeek::Init();
 OuserBorrowed::Init();
 OuserReturn::Init();
 ObookCard::Init();
 Objone::p_objone->show();
    return a.exec();
}
