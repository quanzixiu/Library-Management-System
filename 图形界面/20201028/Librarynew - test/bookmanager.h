#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include"chooseform.h"

namespace Ui {
class BookManager;
}

class BookManager : public QWidget
{
    Q_OBJECT

public:
    explicit BookManager(QWidget *parent = 0);
    ~BookManager();
private slots:
    void on_gotomainpage_clicked();
    void on_exitlogin_clicked();
    void on_confirmsure_clicked();
    void on_addsure_clicked();
    void on_addbooks_clicked();
    void on_updatebooks_clicked();
    void on_deletebooks_clicked();
private:
    Ui::BookManager *ui;
};

#endif // BOOKMANAGER_H
