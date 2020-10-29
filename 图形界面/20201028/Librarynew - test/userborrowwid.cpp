#include "userborrowwid.h"
#include "ui_userborrowwid.h"

UserBorrowWid::UserBorrowWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserBorrowWid)
{
    ui->setupUi(this);
}

UserBorrowWid::~UserBorrowWid()
{
    delete ui;
}
