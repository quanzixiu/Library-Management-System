#include "bookmanager.h"
#include "ui_bookmanager.h"

bookmanager::bookmanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bookmanager)
{
    ui->setupUi(this);
}

bookmanager::~bookmanager()
{
    delete ui;
}
