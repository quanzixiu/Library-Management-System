#ifndef ELEVENUSERWID_H
#define ELEVENUSERWID_H

#include <QWidget>

namespace Ui {
class ElevenUserwid;
}

class ElevenUserwid : public QWidget
{
    Q_OBJECT

public:
    explicit ElevenUserwid(QWidget *parent = 0);
    ~ElevenUserwid();

private slots:
    void on_pushButton_4_clicked();

    void on_seek_button_clicked();

    void on_borrowed_button_clicked();

    void on_returnbook_button_clicked();

    void on_relogin_button_clicked();

private:
    Ui::ElevenUserwid *ui;
};

#endif // ELEVENUSERWID_H
