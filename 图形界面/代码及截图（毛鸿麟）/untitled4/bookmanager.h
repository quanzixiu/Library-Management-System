#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <QWidget>

namespace Ui {
class bookmanager;
}

class bookmanager : public QWidget
{
    Q_OBJECT

public:
    explicit bookmanager(QWidget *parent = 0);
    ~bookmanager();

private:
    Ui::bookmanager *ui;
};

#endif // BOOKMANAGER_H
