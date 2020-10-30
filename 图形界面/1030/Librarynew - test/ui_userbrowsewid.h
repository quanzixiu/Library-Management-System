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
    QPushButton *reushouye_button;
    QPushButton *seekbor_button;

    void setupUi(QWidget *UserBrowseWid)
    {
        if (UserBrowseWid->objectName().isEmpty())
            UserBrowseWid->setObjectName(QStringLiteral("UserBrowseWid"));
        UserBrowseWid->resize(497, 354);
        label = new QLabel(UserBrowseWid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 50, 121, 71));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(true);
        comboBox = new QComboBox(UserBrowseWid);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(0, 90, 62, 22));
        reushouye_button = new QPushButton(UserBrowseWid);
        reushouye_button->setObjectName(QStringLiteral("reushouye_button"));
        reushouye_button->setGeometry(QRect(420, 90, 71, 31));
        reushouye_button->setAutoFillBackground(true);
        seekbor_button = new QPushButton(UserBrowseWid);
        seekbor_button->setObjectName(QStringLiteral("seekbor_button"));
        seekbor_button->setGeometry(QRect(410, 320, 81, 31));
        seekbor_button->setAutoFillBackground(true);

        retranslateUi(UserBrowseWid);

        QMetaObject::connectSlotsByName(UserBrowseWid);
    } // setupUi

    void retranslateUi(QWidget *UserBrowseWid)
    {
        UserBrowseWid->setWindowTitle(QApplication::translate("UserBrowseWid", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("UserBrowseWid", "\345\210\206\347\261\273\346\265\217\350\247\210", Q_NULLPTR));
        reushouye_button->setText(QApplication::translate("UserBrowseWid", "\351\246\226\351\241\265", Q_NULLPTR));
        seekbor_button->setText(QApplication::translate("UserBrowseWid", "\345\200\237\351\230\205\344\271\246\347\261\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserBrowseWid: public Ui_UserBrowseWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERBROWSEWID_H
