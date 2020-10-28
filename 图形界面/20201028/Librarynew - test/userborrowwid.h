#ifndef USERBORROWWID_H
#define USERBORROWWID_H

#include <QWidget>

namespace Ui {
class UserBorrowWid;
}

class UserBorrowWid : public QWidget
{
    Q_OBJECT

public:
    explicit UserBorrowWid(QWidget *parent = 0);
    ~UserBorrowWid();

private:
    Ui::UserBorrowWid *ui;
};

#endif // USERBORROWWID_H
