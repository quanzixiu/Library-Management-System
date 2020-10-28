#ifndef USERBORROWEDWID_H
#define USERBORROWEDWID_H

#include <QWidget>


namespace Ui {
class UserBorrowedWid;
}

class UserBorrowedWid : public QWidget
{
    Q_OBJECT

public:
    explicit UserBorrowedWid(QWidget *parent = 0);
    ~UserBorrowedWid();
    void Init();//登录后初始化界面
private slots:
    void on_shouye_button_clicked();

    void on_return_button_clicked();

private:
    Ui::UserBorrowedWid *ui;
};

#endif // USERBORROWEDWID_H
