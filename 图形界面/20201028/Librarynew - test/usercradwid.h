#ifndef USERCRADWID_H
#define USERCRADWID_H

#include <QWidget>

namespace Ui {
class UserCradWid;
}

class UserCradWid : public QWidget
{
    Q_OBJECT

public:
    explicit UserCradWid(QWidget *parent = 0);
    ~UserCradWid();

private slots:
    void on_cardseek_button_clicked();

    void on_cardok_button_clicked();

private:
    Ui::UserCradWid *ui;
};

#endif // USERCRADWID_H
