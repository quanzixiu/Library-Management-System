#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "chooseform.h"

namespace Ui {
class UserManager;
}

class UserManager : public QWidget
{
    Q_OBJECT

public:
    explicit UserManager(QWidget *parent = 0);
    ~UserManager();
private slots:
    void on_gotomainpage_clicked();
    void on_exitlogin1_clicked();
    void on_confirmsure_clicked();
    void on_addsure_clicked();
    void on_addusers_clicked();
    void on_updateusers_clicked();
    void on_deleteusers_clicked();
private:
    Ui::UserManager *ui;
};

#endif // USERMANAGER_H
