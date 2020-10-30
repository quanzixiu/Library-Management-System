#ifndef ONEWELCOMEW_H
#define ONEWELCOMEW_H

#include <QMainWindow>
#include <QMessageBox>
namespace Ui {
class OneWelcomeW;
}

class OneWelcomeW : public QMainWindow
{
    Q_OBJECT

public:
    explicit OneWelcomeW(QWidget *parent = 0);
    ~OneWelcomeW();

private slots:
    void on_in_button_clicked();
    void on_in_checkbox_clicked();

private:
    Ui::OneWelcomeW *ui;
};

#endif // ONEWELCOMEW_H
