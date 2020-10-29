/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QPushButton *usermanagement;
    QPushButton *exitlogin;
    QPushButton *bookmanagement;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName(QStringLiteral("MainPage"));
        MainPage->resize(1322, 822);
        usermanagement = new QPushButton(MainPage);
        usermanagement->setObjectName(QStringLiteral("usermanagement"));
        usermanagement->setGeometry(QRect(370, 140, 291, 91));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(24);
        usermanagement->setFont(font);
        exitlogin = new QPushButton(MainPage);
        exitlogin->setObjectName(QStringLiteral("exitlogin"));
        exitlogin->setGeometry(QRect(840, 510, 141, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(18);
        exitlogin->setFont(font1);
        bookmanagement = new QPushButton(MainPage);
        bookmanagement->setObjectName(QStringLiteral("bookmanagement"));
        bookmanagement->setGeometry(QRect(370, 320, 291, 91));
        bookmanagement->setFont(font);

        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        MainPage->setWindowTitle(QApplication::translate("MainPage", "\351\246\226\351\241\265", Q_NULLPTR));
        usermanagement->setText(QApplication::translate("MainPage", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        exitlogin->setText(QApplication::translate("MainPage", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        bookmanagement->setText(QApplication::translate("MainPage", "\345\233\276\344\271\246\347\256\241\347\220\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
