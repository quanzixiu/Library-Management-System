/********************************************************************************
** Form generated from reading UI file 'twochoosewid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOCHOOSEWID_H
#define UI_TWOCHOOSEWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TwoChooseWid
{
public:
    QPushButton *manager_button;
    QPushButton *user_button;
    QPushButton *returnsystem_button;
    QLabel *label;
    QPushButton *return_button;

    void setupUi(QWidget *TwoChooseWid)
    {
        if (TwoChooseWid->objectName().isEmpty())
            TwoChooseWid->setObjectName(QStringLiteral("TwoChooseWid"));
        TwoChooseWid->resize(575, 419);
        manager_button = new QPushButton(TwoChooseWid);
        manager_button->setObjectName(QStringLiteral("manager_button"));
        manager_button->setGeometry(QRect(160, 120, 101, 41));
        user_button = new QPushButton(TwoChooseWid);
        user_button->setObjectName(QStringLiteral("user_button"));
        user_button->setGeometry(QRect(160, 180, 101, 41));
        returnsystem_button = new QPushButton(TwoChooseWid);
        returnsystem_button->setObjectName(QStringLiteral("returnsystem_button"));
        returnsystem_button->setGeometry(QRect(160, 240, 101, 41));
        label = new QLabel(TwoChooseWid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 30, 211, 81));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(true);
        return_button = new QPushButton(TwoChooseWid);
        return_button->setObjectName(QStringLiteral("return_button"));
        return_button->setGeometry(QRect(469, 380, 51, 31));

        retranslateUi(TwoChooseWid);

        QMetaObject::connectSlotsByName(TwoChooseWid);
    } // setupUi

    void retranslateUi(QWidget *TwoChooseWid)
    {
        TwoChooseWid->setWindowTitle(QApplication::translate("TwoChooseWid", "Form", Q_NULLPTR));
        manager_button->setText(QApplication::translate("TwoChooseWid", "\347\256\241\347\220\206\345\221\230\347\263\273\347\273\237", Q_NULLPTR));
        user_button->setText(QApplication::translate("TwoChooseWid", "\345\200\237\351\230\205\347\263\273\347\273\237", Q_NULLPTR));
        returnsystem_button->setText(QApplication::translate("TwoChooseWid", "\350\277\230\344\271\246\347\263\273\347\273\237", Q_NULLPTR));
        label->setText(QApplication::translate("TwoChooseWid", "\350\257\267\351\200\211\346\213\251\346\202\250\351\234\200\350\246\201\347\232\204\347\263\273\347\273\237", Q_NULLPTR));
        return_button->setText(QApplication::translate("TwoChooseWid", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TwoChooseWid: public Ui_TwoChooseWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOCHOOSEWID_H
