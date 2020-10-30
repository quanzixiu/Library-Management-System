#ifndef TWOCHOOSEWID_H
#define TWOCHOOSEWID_H

#include <QWidget>

namespace Ui {
class TwoChooseWid;
}

class TwoChooseWid : public QWidget
{
    Q_OBJECT

public:
    explicit TwoChooseWid(QWidget *parent = 0);
    ~TwoChooseWid();

private slots:
    void on_manager_button_clicked();

    void on_user_button_clicked();

    void on_returnsystem_button_clicked();

    void on_return_button_clicked();

private:
    Ui::TwoChooseWid *ui;
};

#endif // TWOCHOOSEWID_H
