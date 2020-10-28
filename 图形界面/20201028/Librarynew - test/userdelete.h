#ifndef USERDELETE_H
#define USERDELETE_H

#include "chooseform.h"

namespace Ui {
class UserDelete;
}

class UserDelete : public QWidget
{
    Q_OBJECT

public:
    explicit UserDelete(QWidget *parent = 0);
    ~UserDelete();
private slots:
    void on_gotomainpage_clicked();
    void on_exitlogin_clicked();
    void on_confirmsure_clicked();
    void on_deletesure_clicked();
    void on_addusers_clicked();
    void on_updateusers_clicked();
    void on_deleteusers_clicked();
private:
    Ui::UserDelete *ui;
};

#endif // USERDELETE_H
