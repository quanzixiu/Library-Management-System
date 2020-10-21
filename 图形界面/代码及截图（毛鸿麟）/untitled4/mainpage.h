#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QDebug>
namespace Ui {
class mainpage;
}

class mainpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainpage(QWidget *parent = 0);
    ~mainpage();
private slots:
    void on_usermanagement_clicked();
    void on_bookmanagement_clicked();
    void on_exitlogin_clicked();
private:
    Ui::mainpage *ui;
};

#endif // MAINPAGE_H
