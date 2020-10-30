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

private slots:
    void on_reushouye_button_clicked();

    void on_seekbor_button_clicked();

private:
    Ui::UserBrowseWid *ui;
};

#endif // USERBROWSEWID_H
