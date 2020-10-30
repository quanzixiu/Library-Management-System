/********************************************************************************
** Form generated from reading UI file 'userdelete.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDELETE_H
#define UI_USERDELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserDelete
{
public:
    QPushButton *gotomainpage;
    QGroupBox *sidemenu;
    QPushButton *addusers;
    QPushButton *deleteusers;
    QPushButton *updateusers;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QPushButton *confirmsure;
    QLineEdit *le_id;
    QTextEdit *borrowinfotable;
    QPushButton *exitlogin;

    void setupUi(QWidget *UserDelete)
    {
        if (UserDelete->objectName().isEmpty())
            UserDelete->setObjectName(QStringLiteral("UserDelete"));
        UserDelete->resize(1282, 859);
        gotomainpage = new QPushButton(UserDelete);
        gotomainpage->setObjectName(QStringLiteral("gotomainpage"));
        gotomainpage->setGeometry(QRect(1110, 60, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        gotomainpage->setFont(font);
        sidemenu = new QGroupBox(UserDelete);
        sidemenu->setObjectName(QStringLiteral("sidemenu"));
        sidemenu->setGeometry(QRect(0, 170, 201, 391));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        sidemenu->setFont(font1);
        addusers = new QPushButton(sidemenu);
        addusers->setObjectName(QStringLiteral("addusers"));
        addusers->setGeometry(QRect(0, 70, 201, 51));
        deleteusers = new QPushButton(sidemenu);
        deleteusers->setObjectName(QStringLiteral("deleteusers"));
        deleteusers->setGeometry(QRect(0, 160, 201, 51));
        updateusers = new QPushButton(sidemenu);
        updateusers->setObjectName(QStringLiteral("updateusers"));
        updateusers->setGeometry(QRect(0, 260, 201, 51));
        groupBox = new QGroupBox(UserDelete);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(300, 140, 831, 441));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 30, 771, 111));
        confirmsure = new QPushButton(groupBox_2);
        confirmsure->setObjectName(QStringLiteral("confirmsure"));
        confirmsure->setGeometry(QRect(650, 30, 91, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(16);
        confirmsure->setFont(font2);
        le_id = new QLineEdit(groupBox_2);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(30, 40, 571, 41));
        le_id->setFont(font1);
        le_id->setClearButtonEnabled(false);
        borrowinfotable = new QTextEdit(groupBox);
        borrowinfotable->setObjectName(QStringLiteral("borrowinfotable"));
        borrowinfotable->setGeometry(QRect(40, 170, 771, 251));
        exitlogin = new QPushButton(UserDelete);
        exitlogin->setObjectName(QStringLiteral("exitlogin"));
        exitlogin->setGeometry(QRect(1050, 620, 131, 51));
        exitlogin->setFont(font1);

        retranslateUi(UserDelete);

        QMetaObject::connectSlotsByName(UserDelete);
    } // setupUi

    void retranslateUi(QWidget *UserDelete)
    {
        UserDelete->setWindowTitle(QApplication::translate("UserDelete", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        gotomainpage->setText(QApplication::translate("UserDelete", "\351\246\226\351\241\265", Q_NULLPTR));
        sidemenu->setTitle(QApplication::translate("UserDelete", "\344\276\247\350\276\271\350\217\234\345\215\225\346\240\217", Q_NULLPTR));
        addusers->setText(QApplication::translate("UserDelete", "\345\242\236\345\212\240\347\224\250\346\210\267", Q_NULLPTR));
        deleteusers->setText(QApplication::translate("UserDelete", "\345\210\240\351\231\244\347\224\250\346\210\267", Q_NULLPTR));
        updateusers->setText(QApplication::translate("UserDelete", "\344\277\256\346\224\271\347\224\250\346\210\267", Q_NULLPTR));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        confirmsure->setText(QApplication::translate("UserDelete", "\347\241\256\345\256\232", Q_NULLPTR));
        le_id->setText(QString());
        le_id->setPlaceholderText(QApplication::translate("UserDelete", "\350\276\223\345\205\245\345\255\246\347\224\237ID", Q_NULLPTR));
        exitlogin->setText(QApplication::translate("UserDelete", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserDelete: public Ui_UserDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDELETE_H
