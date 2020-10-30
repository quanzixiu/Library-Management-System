#ifndef BOOKUPDATE_H
#define BOOKUPDATE_H

#include"chooseform.h"
#include "bookdocking.h"
#include "supervisor.h"

namespace Ui {
class BookUpdate;
}

class BookUpdate : public QWidget
{
    Q_OBJECT

public:
    explicit BookUpdate(QWidget *parent = 0);
    ~BookUpdate();
    int getchoice() { return choice; }
    void setchoice(int c) { choice = c; }
private slots:
    void on_updateisbn_clicked();
    void on_updatebookname_clicked();
    void on_updatewriter_clicked();
    void on_updatebooktype_clicked();
    void on_updateshelf_clicked();
    void on_updatestatus_clicked();
    void on_confirm1_clicked();
    void on_gotomainpage_clicked();
    void on_returnbookmanager_clicked();
private:
    Ui::BookUpdate *ui;
    int choice; //1-7分对应侧边栏从上到下按钮
};

#endif // BOOKUPDATE_H
