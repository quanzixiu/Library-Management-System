#include "mainpage.h"
#include "usermanager.h"
#include "bookmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainpage w;
    w.show();

    return a.exec();
}
