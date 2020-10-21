#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QWidget>
#include <QApplication>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QTableView>
#include <QTableWidget>
#include <QHeaderView>
#include <QStandardItemModel>
namespace Ui {
class usermanager;
}

class usermanager : public QWidget
{
    Q_OBJECT

public:
    explicit usermanager(QWidget *parent = 0);
    ~usermanager();
private slots:
    void on_gotomainpage_clicked();
    void on_exitlogin1_clicked();
    void on_confirmsure_clicked();
    void on_addsure_clicked();
    void on_addusers_clicked();
    void on_updateusers_clicked();
    void on_deleteusers_clicked();
private:
    Ui::usermanager *ui;
};

#endif // USERMANAGER_H
