/********************************************************************************
** Form generated from reading UI file 'userbrowsewid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERBROWSEWID_H
#define UI_USERBROWSEWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserBrowseWid
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *UserBrowseWid)
    {
        if (UserBrowseWid->objectName().isEmpty())
            UserBrowseWid->setObjectName(QStringLiteral("UserBrowseWid"));
        UserBrowseWid->resize(400, 300);
        label = new QLabel(UserBrowseWid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 61, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(true);
        comboBox = new QComboBox(UserBrowseWid);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(30, 70, 62, 22));
        pushButton = new QPushButton(UserBrowseWid);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 70, 31, 20));
        pushButton->setAutoFillBackground(true);
        pushButton_2 = new QPushButton(UserBrowseWid);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 270, 61, 20));
        pushButton_2->setAutoFillBackground(true);

        retranslateUi(UserBrowseWid);

        QMetaObject::connectSlotsByName(UserBrowseWid);
    } // setupUi

    void retranslateUi(QWidget *UserBrowseWid)
    {
        UserBrowseWid->setWindowTitle(QApplication::translate("UserBrowseWid", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("UserBrowseWid", "\345\210\206\347\261\273\346\265\217\350\247\210", Q_NULLPTR));
        pushButton->setText(QApplication::translate("UserBrowseWid", "\351\246\226\351\241\265", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("UserBrowseWid", "\345\200\237\351\230\205\344\271\246\347\261\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserBrowseWid: public Ui_UserBrowseWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERBROWSEWID_H
