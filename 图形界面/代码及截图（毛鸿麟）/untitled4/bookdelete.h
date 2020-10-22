#ifndef BOOKDELETE_H
#define BOOKDELETE_H

#include"chooseform.h"

namespace Ui {
class bookdelete;
}

class bookdelete : public QWidget
{
    Q_OBJECT

public:
    explicit bookdelete(QWidget *parent = 0);
    ~bookdelete();
private slots:
    void on_addbooks_clicked();
    void on_updatebooks_clicked();
    void on_deletebooks_clicked();
    void on_gotomainpage_clicked();
    void on_exitlogin_clicked();
    void on_confirmsure_clicked();
    void on_deletesure_clicked();
private:
    Ui::bookdelete *ui;
};

#endif // BOOKDELETE_H
