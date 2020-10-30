#ifndef TWOLOGIND_H
#define TWOLOGIND_H

#include <QDialog>
#include <QMessageBox>

#include "chooseform.h"
namespace Ui {
class TwoLoginD;
}

class TwoLoginD : public QDialog
{
    Q_OBJECT

public:
    explicit TwoLoginD(QWidget *parent = 0);
    ~TwoLoginD();
 QString GetId();
 QString GetPassword();
private slots:
    void on_login_button_clicked();

    void on_return_button_clicked();

private:
    Ui::TwoLoginD *ui;
};

#endif // TWOLOGIND_H
