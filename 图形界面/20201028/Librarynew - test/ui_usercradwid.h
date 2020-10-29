/********************************************************************************
** Form generated from reading UI file 'usercradwid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCRADWID_H
#define UI_USERCRADWID_H

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

class Ui_UserCradWid
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QPushButton *cardok_button;
    QTableWidget *card_table;
    QLabel *label;
    QPushButton *cardseek_button;

    void setupUi(QWidget *UserCradWid)
    {
        if (UserCradWid->objectName().isEmpty())
            UserCradWid->setObjectName(QStringLiteral("UserCradWid"));
        UserCradWid->resize(587, 423);
        groupBox = new QGroupBox(UserCradWid);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 60, 441, 271));
        QFont font;
        font.setPointSize(11);
        groupBox->setFont(font);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 20, 161, 21));
        lineEdit->setAutoFillBackground(true);
        cardok_button = new QPushButton(groupBox);
        cardok_button->setObjectName(QStringLiteral("cardok_button"));
        cardok_button->setGeometry(QRect(250, 20, 41, 31));
        QFont font1;
        font1.setPointSize(9);
        cardok_button->setFont(font1);
        cardok_button->setAutoFillBackground(true);
        card_table = new QTableWidget(groupBox);
        if (card_table->columnCount() < 5)
            card_table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        card_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        card_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        card_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        card_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        card_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        card_table->setObjectName(QStringLiteral("card_table"));
        card_table->setGeometry(QRect(0, 50, 381, 201));
        label = new QLabel(UserCradWid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 121, 41));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAutoFillBackground(true);
        cardseek_button = new QPushButton(UserCradWid);
        cardseek_button->setObjectName(QStringLiteral("cardseek_button"));
        cardseek_button->setGeometry(QRect(420, 350, 151, 61));
        cardseek_button->setAutoFillBackground(true);

        retranslateUi(UserCradWid);

        QMetaObject::connectSlotsByName(UserCradWid);
    } // setupUi

    void retranslateUi(QWidget *UserCradWid)
    {
        UserCradWid->setWindowTitle(QApplication::translate("UserCradWid", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UserCradWid", "\350\257\267\345\234\250\344\270\213\351\235\242\350\276\223\345\205\245\350\246\201\346\237\245\347\234\213\345\200\237\351\230\205\345\216\206\345\217\262\347\232\204\345\233\276\344\271\246ID", Q_NULLPTR));
        cardok_button->setText(QApplication::translate("UserCradWid", "\347\241\256\345\256\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = card_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserCradWid", "\345\255\246\347\224\237ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = card_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserCradWid", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = card_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserCradWid", "\345\255\246\351\231\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = card_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("UserCradWid", "\344\270\223\344\270\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = card_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("UserCradWid", "\351\202\256\347\256\261", Q_NULLPTR));
        label->setText(QApplication::translate("UserCradWid", "\345\200\237\344\271\246\345\215\241", Q_NULLPTR));
        cardseek_button->setText(QApplication::translate("UserCradWid", "\350\277\224\345\233\236\346\237\245\346\211\276\345\200\237\351\230\205\345\233\276\344\271\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserCradWid: public Ui_UserCradWid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCRADWID_H
