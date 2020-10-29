/********************************************************************************
** Form generated from reading UI file 'userborrowwid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERBORROWWID_H
#define UI_USERBORROWWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserBorrowWid
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;

    void setupUi(QWidget *UserBorrowWid)
    {
        if (UserBorrowWid->objectName().isEmpty())
            UserBorrowWid->setObjectName(QStringLiteral("UserBorrowWid"));
        UserBorrowWid->resize(400, 300);
        label = new QLabel(UserBorrowWid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 61, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(true);
        pushButton = new QPushButton(UserBorrowWid);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 60, 80, 15));
        pushButton->setAutoFillBackground(true);
        pushButton_2 = new QPushButton(UserBorrowWid);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 270, 80, 15));
        pushButton_2->setAutoFillBackground(true);
        groupBox = new QGroupBox(UserBorrowWid);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(80, 100, 231, 161));
        QFont font1;
        font1.setPointSize(11);
        groupBox->setFont(font1);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 161, 21));
        lineEdit->setAutoFillBackground(true);
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 20, 31, 20));
        QFont font2;
        font2.setPointSize(9);
        pushButton_3->setFont(font2);
        pushButton_3->setAutoFillBackground(true);

        retranslateUi(UserBorrowWid);

        QMetaObject::connectSlotsByName(UserBorrowWid);
    } // setupUi

    void retranslateUi(QWidget *UserBorrowWid)
    {
        UserBorrowWid->setWindowTitle(QApplication::translate("UserBorrowWid", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("UserBorrowWid", "\345\200\237\351\230\205\344\271\246\347\261\215", Q_NULLPTR));
        pushButton->setText(QApplication::translate("UserBorrowWid", "\346\237\245\346\211\276\345\200\237\351\230\205\345\233\276\344\271\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("UserBorrowWid", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UserBorrowWid", "\350\257\267\345\234\250\344\270\213\351\235\242\350\276\223\345\205\245\350\246\201\345\200\237\351\230\205\347\232\204\345\233\276\344\271\246ID", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("UserBorrowWid", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserBorrowWid: public Ui_UserBorrowWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERBORROWWID_H
