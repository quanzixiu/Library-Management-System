/********************************************************************************
** Form generated from reading UI file 'userreturnwid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERRETURNWID_H
#define UI_USERRETURNWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserReturnWid
{
public:
    QLabel *label;
    QPushButton *seekbor_button;
    QPushButton *return_button;
    QGroupBox *groupBox;
    QPushButton *returnok_button;
    QLineEdit *lineEdit;
    QTableWidget *returninfo_table;
    QPushButton *returnbook_button;

    void setupUi(QWidget *UserReturnWid)
    {
        if (UserReturnWid->objectName().isEmpty())
            UserReturnWid->setObjectName(QStringLiteral("UserReturnWid"));
        UserReturnWid->resize(603, 432);
        label = new QLabel(UserReturnWid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 10, 171, 61));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(true);
        seekbor_button = new QPushButton(UserReturnWid);
        seekbor_button->setObjectName(QStringLiteral("seekbor_button"));
        seekbor_button->setGeometry(QRect(440, 50, 101, 51));
        return_button = new QPushButton(UserReturnWid);
        return_button->setObjectName(QStringLiteral("return_button"));
        return_button->setGeometry(QRect(490, 380, 81, 41));
        groupBox = new QGroupBox(UserReturnWid);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 100, 411, 301));
        QFont font1;
        font1.setPointSize(11);
        groupBox->setFont(font1);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        returnok_button = new QPushButton(groupBox);
        returnok_button->setObjectName(QStringLiteral("returnok_button"));
        returnok_button->setGeometry(QRect(220, 20, 51, 31));
        QFont font2;
        font2.setPointSize(9);
        returnok_button->setFont(font2);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 30, 161, 21));
        returninfo_table = new QTableWidget(groupBox);
        if (returninfo_table->columnCount() < 7)
            returninfo_table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        returninfo_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        returninfo_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        returninfo_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        returninfo_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        returninfo_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        returninfo_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        returninfo_table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        returninfo_table->setObjectName(QStringLiteral("returninfo_table"));
        returninfo_table->setGeometry(QRect(0, 60, 411, 151));
        returnbook_button = new QPushButton(groupBox);
        returnbook_button->setObjectName(QStringLiteral("returnbook_button"));
        returnbook_button->setGeometry(QRect(310, 240, 61, 31));

        retranslateUi(UserReturnWid);

        QMetaObject::connectSlotsByName(UserReturnWid);
    } // setupUi

    void retranslateUi(QWidget *UserReturnWid)
    {
        UserReturnWid->setWindowTitle(QApplication::translate("UserReturnWid", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("UserReturnWid", "\345\275\222\350\277\230\345\233\276\344\271\246", Q_NULLPTR));
        seekbor_button->setText(QApplication::translate("UserReturnWid", "\346\237\245\346\211\276\345\200\237\351\230\205\345\233\276\344\271\246", Q_NULLPTR));
        return_button->setText(QApplication::translate("UserReturnWid", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UserReturnWid", "\350\257\267\345\234\250\344\270\213\351\235\242\350\276\223\345\205\245\345\233\276\344\271\246ID", Q_NULLPTR));
        returnok_button->setText(QApplication::translate("UserReturnWid", "\347\241\256\345\256\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = returninfo_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserReturnWid", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = returninfo_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserReturnWid", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = returninfo_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserReturnWid", "ISBN", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = returninfo_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("UserReturnWid", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = returninfo_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("UserReturnWid", "\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = returninfo_table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("UserReturnWid", "\345\200\237\344\271\246\346\227\245\346\234\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = returninfo_table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("UserReturnWid", "\345\272\224\350\277\230\346\227\245\346\234\237", Q_NULLPTR));
        returnbook_button->setText(QApplication::translate("UserReturnWid", "\345\275\222\350\277\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserReturnWid: public Ui_UserReturnWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERRETURNWID_H
