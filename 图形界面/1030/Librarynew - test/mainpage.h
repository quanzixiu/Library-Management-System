#ifndef MAINPAGE_H
#define MAINPAGE_H

#include"chooseform.h"

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();
private slots:
    void on_usermanagement_clicked();
    void on_bookmanagement_clicked();
    void on_exitlogin_clicked();
private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H
