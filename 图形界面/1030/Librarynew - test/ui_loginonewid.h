/********************************************************************************
** Form generated from reading UI file 'loginonewid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINONEWID_H
#define UI_LOGINONEWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginOneWid
{
public:
    QLabel *label_3;
    QLineEdit *id_linedit;
    QPushButton *return_button;
    QLineEdit *password_linedit;
    QLabel *label_2;
    QLabel *label;
    QPushButton *login_button;

    void setupUi(QWidget *LoginOneWid)
    {
        if (LoginOneWid->objectName().isEmpty())
            LoginOneWid->setObjectName(QStringLiteral("LoginOneWid"));
        LoginOneWid->resize(518, 377);
        label_3 = new QLabel(LoginOneWid);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 170, 41, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label_3->setFont(font);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAutoFillBackground(true);
        id_linedit = new QLineEdit(LoginOneWid);
        id_linedit->setObjectName(QStringLiteral("id_linedit"));
        id_linedit->setGeometry(QRect(220, 140, 113, 20));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        id_linedit->setFont(font1);
        return_button = new QPushButton(LoginOneWid);
        return_button->setObjectName(QStringLiteral("return_button"));
        return_button->setGeometry(QRect(340, 290, 81, 31));
        password_linedit = new QLineEdit(LoginOneWid);
        password_linedit->setObjectName(QStringLiteral("password_linedit"));
        password_linedit->setGeometry(QRect(220, 170, 113, 20));
        password_linedit->setFont(font1);
        label_2 = new QLabel(LoginOneWid);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 140, 41, 21));
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAutoFillBackground(true);
        label = new QLabel(LoginOneWid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 90, 71, 31));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        login_button = new QPushButton(LoginOneWid);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(230, 210, 61, 31));

        retranslateUi(LoginOneWid);

        QMetaObject::connectSlotsByName(LoginOneWid);
    } // setupUi

    void retranslateUi(QWidget *LoginOneWid)
    {
        LoginOneWid->setWindowTitle(QApplication::translate("LoginOneWid", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginOneWid", "\345\257\206\347\240\201", Q_NULLPTR));
        return_button->setText(QApplication::translate("LoginOneWid", "\351\200\200\345\207\272", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginOneWid", "\350\264\246\345\217\267", Q_NULLPTR));
        label->setText(QApplication::translate("LoginOneWid", "\347\231\273\345\275\225", Q_NULLPTR));
        login_button->setText(QApplication::translate("LoginOneWid", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginOneWid: public Ui_LoginOneWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINONEWID_H
