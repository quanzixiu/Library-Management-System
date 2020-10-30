/********************************************************************************
** Form generated from reading UI file 'userupdate.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERUPDATE_H
#define UI_USERUPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserUpdate
{
public:
    QGroupBox *groupBox;
    QPushButton *updatepassword;
    QPushButton *updatename;
    QPushButton *updateschool;
    QPushButton *updatemajor;
    QPushButton *updateemail;
    QPushButton *returnusermanager;
    QPushButton *gotomainpage;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QLineEdit *inputid;
    QLineEdit *inputinfo;
    QPushButton *confirm1;
    QPushButton *confirm2;
    QTableWidget *infotable;

    void setupUi(QWidget *UserUpdate)
    {
        if (UserUpdate->objectName().isEmpty())
            UserUpdate->setObjectName(QStringLiteral("UserUpdate"));
        UserUpdate->resize(1325, 810);
        groupBox = new QGroupBox(UserUpdate);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 130, 161, 491));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        groupBox->setFont(font);
        updatepassword = new QPushButton(groupBox);
        updatepassword->setObjectName(QStringLiteral("updatepassword"));
        updatepassword->setGeometry(QRect(0, 60, 161, 51));
        updatename = new QPushButton(groupBox);
        updatename->setObjectName(QStringLiteral("updatename"));
        updatename->setGeometry(QRect(0, 130, 161, 51));
        updateschool = new QPushButton(groupBox);
        updateschool->setObjectName(QStringLiteral("updateschool"));
        updateschool->setGeometry(QRect(0, 210, 161, 51));
        updatemajor = new QPushButton(groupBox);
        updatemajor->setObjectName(QStringLiteral("updatemajor"));
        updatemajor->setGeometry(QRect(0, 290, 161, 51));
        updateemail = new QPushButton(groupBox);
        updateemail->setObjectName(QStringLiteral("updateemail"));
        updateemail->setGeometry(QRect(0, 380, 161, 51));
        returnusermanager = new QPushButton(UserUpdate);
        returnusermanager->setObjectName(QStringLiteral("returnusermanager"));
        returnusermanager->setGeometry(QRect(980, 610, 201, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(18);
        returnusermanager->setFont(font1);
        gotomainpage = new QPushButton(UserUpdate);
        gotomainpage->setObjectName(QStringLiteral("gotomainpage"));
        gotomainpage->setGeometry(QRect(1084, 82, 101, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(12);
        gotomainpage->setFont(font2);
        groupBox_2 = new QGroupBox(UserUpdate);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(230, 140, 941, 441));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 20, 901, 131));
        inputid = new QLineEdit(groupBox_3);
        inputid->setObjectName(QStringLiteral("inputid"));
        inputid->setGeometry(QRect(30, 20, 651, 31));
        inputid->setAlignment(Qt::AlignCenter);
        inputinfo = new QLineEdit(groupBox_3);
        inputinfo->setObjectName(QStringLiteral("inputinfo"));
        inputinfo->setGeometry(QRect(30, 70, 651, 31));
        inputinfo->setAlignment(Qt::AlignCenter);
        confirm1 = new QPushButton(groupBox_3);
        confirm1->setObjectName(QStringLiteral("confirm1"));
        confirm1->setGeometry(QRect(720, 20, 111, 31));
        confirm2 = new QPushButton(groupBox_3);
        confirm2->setObjectName(QStringLiteral("confirm2"));
        confirm2->setGeometry(QRect(720, 70, 111, 31));
        infotable = new QTableWidget(groupBox_2);
        if (infotable->columnCount() < 6)
            infotable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        infotable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        infotable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        infotable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        infotable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        infotable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        infotable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        infotable->setObjectName(QStringLiteral("infotable"));
        infotable->setGeometry(QRect(50, 160, 871, 261));
        infotable->setRowCount(0);
        infotable->setColumnCount(6);
        infotable->horizontalHeader()->setStretchLastSection(true);
        infotable->verticalHeader()->setStretchLastSection(false);

        retranslateUi(UserUpdate);

        QMetaObject::connectSlotsByName(UserUpdate);
    } // setupUi

    void retranslateUi(QWidget *UserUpdate)
    {
        UserUpdate->setWindowTitle(QApplication::translate("UserUpdate", "\344\277\256\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UserUpdate", "\344\276\247\350\276\271\350\217\234\345\215\225\346\240\217", Q_NULLPTR));
        updatepassword->setText(QApplication::translate("UserUpdate", "\344\277\256\346\224\271\345\257\206\347\240\201", Q_NULLPTR));
        updatename->setText(QApplication::translate("UserUpdate", "\344\277\256\346\224\271\345\247\223\345\220\215", Q_NULLPTR));
        updateschool->setText(QApplication::translate("UserUpdate", "\344\277\256\346\224\271\345\255\246\346\240\241", Q_NULLPTR));
        updatemajor->setText(QApplication::translate("UserUpdate", "\344\277\256\346\224\271\344\270\223\344\270\232", Q_NULLPTR));
        updateemail->setText(QApplication::translate("UserUpdate", "\344\277\256\346\224\271\351\202\256\347\256\261", Q_NULLPTR));
        returnusermanager->setText(QApplication::translate("UserUpdate", "\350\277\224\345\233\236\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        gotomainpage->setText(QApplication::translate("UserUpdate", "\351\246\226\351\241\265", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        inputid->setPlaceholderText(QApplication::translate("UserUpdate", "\350\276\223\345\205\245ID", Q_NULLPTR));
        inputinfo->setText(QString());
        inputinfo->setPlaceholderText(QApplication::translate("UserUpdate", "\350\276\223\345\205\245\350\246\201\344\277\256\346\224\271\347\232\204\344\277\241\346\201\257", Q_NULLPTR));
        confirm1->setText(QApplication::translate("UserUpdate", "\347\241\256\345\256\232", Q_NULLPTR));
        confirm2->setText(QApplication::translate("UserUpdate", "\347\241\256\345\256\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = infotable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserUpdate", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = infotable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserUpdate", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = infotable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserUpdate", "\345\257\206\347\240\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = infotable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("UserUpdate", "\345\255\246\346\240\241", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = infotable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("UserUpdate", "\344\270\223\344\270\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = infotable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("UserUpdate", "\351\202\256\347\256\261", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserUpdate: public Ui_UserUpdate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERUPDATE_H
