#ifndef USERBROWSEWID_H
#define USERBROWSEWID_H

#include <QWidget>

namespace Ui {
class UserBrowseWid;
}

class UserBrowseWid : public QWidget
{
    Q_OBJECT

public:
    explicit UserBrowseWid(QWidget *parent = 0);
    ~UserBrowseWid();

private:
    Ui::UserBrowseWid *ui;
};

#endif // USERBROWSEWID_H
