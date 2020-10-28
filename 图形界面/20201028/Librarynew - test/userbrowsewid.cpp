#include "userbrowsewid.h"
#include "ui_userbrowsewid.h"

UserBrowseWid::UserBrowseWid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserBrowseWid)
{
    ui->setupUi(this);
}

UserBrowseWid::~UserBrowseWid()
{
    delete ui;
}
