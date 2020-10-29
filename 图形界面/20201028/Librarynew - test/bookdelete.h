#ifndef BOOKDELETE_H
#define BOOKDELETE_H

#include"chooseform.h"

namespace Ui {
class BookDelete;
}

class BookDelete : public QWidget
{
    Q_OBJECT

public:
    explicit BookDelete(QWidget *parent = 0);
    ~BookDelete();
private slots:
    void on_addbooks_clicked();
    void on_updatebooks_clicked();
    void on_deletebooks_clicked();
    void on_gotomainpage_clicked();
    void on_exitlogin_clicked();
    void on_confirmsure_clicked();
    void on_deletesure_clicked();
private:
    Ui::BookDelete *ui;
};

#endif // BOOKDELETE_H
