/********************************************************************************
** Form generated from reading UI file 'userborrowedwid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERBORROWEDWID_H
#define UI_USERBORROWEDWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserBorrowedWid
{
public:
    QLabel *label;
    QPushButton *shouye_button;
    QPushButton *return_button;
    QTableWidget *borrowed_table;

    void setupUi(QWidget *UserBorrowedWid)
    {
        if (UserBorrowedWid->objectName().isEmpty())
            UserBorrowedWid->setObjectName(QStringLiteral("UserBorrowedWid"));
        UserBorrowedWid->resize(493, 347);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        UserBorrowedWid->setFont(font);
        UserBorrowedWid->setAutoFillBackground(true);
        label = new QLabel(UserBorrowedWid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 20, 141, 41));
        shouye_button = new QPushButton(UserBorrowedWid);
        shouye_button->setObjectName(QStringLiteral("shouye_button"));
        shouye_button->setGeometry(QRect(400, 30, 51, 31));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        shouye_button->setFont(font1);
        shouye_button->setAutoFillBackground(true);
        return_button = new QPushButton(UserBorrowedWid);
        return_button->setObjectName(QStringLiteral("return_button"));
        return_button->setGeometry(QRect(360, 290, 81, 31));
        return_button->setFont(font1);
        return_button->setAutoFillBackground(true);
        borrowed_table = new QTableWidget(UserBorrowedWid);
        if (borrowed_table->columnCount() < 7)
            borrowed_table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        borrowed_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        borrowed_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        borrowed_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        borrowed_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        borrowed_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        borrowed_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        borrowed_table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        borrowed_table->setObjectName(QStringLiteral("borrowed_table"));
        borrowed_table->setGeometry(QRect(50, 70, 381, 211));

        retranslateUi(UserBorrowedWid);

        QMetaObject::connectSlotsByName(UserBorrowedWid);
    } // setupUi

    void retranslateUi(QWidget *UserBorrowedWid)
    {
        UserBorrowedWid->setWindowTitle(QApplication::translate("UserBorrowedWid", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("UserBorrowedWid", "\345\267\262\345\200\237\344\271\246\347\261\215", Q_NULLPTR));
        shouye_button->setText(QApplication::translate("UserBorrowedWid", "\351\246\226\351\241\265", Q_NULLPTR));
        return_button->setText(QApplication::translate("UserBorrowedWid", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = borrowed_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserBorrowedWid", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = borrowed_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserBorrowedWid", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = borrowed_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserBorrowedWid", "ISBN", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = borrowed_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("UserBorrowedWid", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = borrowed_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("UserBorrowedWid", "\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = borrowed_table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("UserBorrowedWid", "\345\200\237\344\271\246\346\227\245\346\234\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = borrowed_table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("UserBorrowedWid", "\345\272\224\350\277\230\346\227\245\346\234\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserBorrowedWid: public Ui_UserBorrowedWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERBORROWEDWID_H
