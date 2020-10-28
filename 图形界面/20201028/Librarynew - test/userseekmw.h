#ifndef USERSEEKMW_H
#define USERSEEKMW_H

#include <QMainWindow>
#include <QMessageBox>
namespace Ui {
class UserSeekMw;
}

class UserSeekMw : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserSeekMw(QWidget *parent = 0);
    ~UserSeekMw();

private slots:
    void on_usershouye_button_clicked();

    void on_return_button_clicked();

    void on_bookcard_button_clicked();

    void on_seekok_button_clicked();

    void on_borrowok_button_clicked();

private:
    Ui::UserSeekMw *ui;
};

#endif // USERSEEKMW_H
