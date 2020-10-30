#ifndef USERRETURNWID_H
#define USERRETURNWID_H

#include <QWidget>

namespace Ui {
class UserReturnWid;
}

class UserReturnWid : public QWidget
{
    Q_OBJECT

public:
    explicit UserReturnWid(QWidget *parent = 0);
    ~UserReturnWid();

private slots:
    void on_seekbor_button_clicked();

    void on_return_button_clicked();

    void on_returnok_button_clicked();

    void on_returnbook_button_clicked();

private:
    Ui::UserReturnWid *ui;
};

#endif // USERRETURNWID_H
