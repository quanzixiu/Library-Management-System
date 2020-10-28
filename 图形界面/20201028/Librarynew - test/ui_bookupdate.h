/********************************************************************************
** Form generated from reading UI file 'bookupdate.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKUPDATE_H
#define UI_BOOKUPDATE_H

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

class Ui_BookUpdate
{
public:
    QPushButton *returnbookmanager;
    QPushButton *gotomainpage;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QLineEdit *inputid;
    QLineEdit *inputinfo;
    QPushButton *confirm1;
    QPushButton *confirm2;
    QTableWidget *infotable;
    QPushButton *updatesure;
    QGroupBox *groupBox;
    QPushButton *updateid;
    QPushButton *updateisbn;
    QPushButton *updatebookname;
    QPushButton *updatewriter;
    QPushButton *updatebooktype;
    QPushButton *updateshelf;
    QPushButton *updatestatus;

    void setupUi(QWidget *BookUpdate)
    {
        if (BookUpdate->objectName().isEmpty())
            BookUpdate->setObjectName(QStringLiteral("BookUpdate"));
        BookUpdate->resize(1309, 831);
        returnbookmanager = new QPushButton(BookUpdate);
        returnbookmanager->setObjectName(QStringLiteral("returnbookmanager"));
        returnbookmanager->setGeometry(QRect(970, 780, 191, 51));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        returnbookmanager->setFont(font);
        gotomainpage = new QPushButton(BookUpdate);
        gotomainpage->setObjectName(QStringLiteral("gotomainpage"));
        gotomainpage->setGeometry(QRect(1070, 10, 111, 41));
        gotomainpage->setFont(font);
        groupBox_2 = new QGroupBox(BookUpdate);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(210, 90, 941, 661));
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
        infotable->setObjectName(QStringLiteral("infotable"));
        infotable->setGeometry(QRect(20, 180, 901, 461));
        updatesure = new QPushButton(groupBox_2);
        updatesure->setObjectName(QStringLiteral("updatesure"));
        updatesure->setGeometry(QRect(760, 580, 121, 31));
        groupBox = new QGroupBox(BookUpdate);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 70, 151, 701));
        groupBox->setFont(font);
        updateid = new QPushButton(groupBox);
        updateid->setObjectName(QStringLiteral("updateid"));
        updateid->setGeometry(QRect(0, 40, 151, 51));
        updateisbn = new QPushButton(groupBox);
        updateisbn->setObjectName(QStringLiteral("updateisbn"));
        updateisbn->setGeometry(QRect(0, 110, 151, 51));
        updatebookname = new QPushButton(groupBox);
        updatebookname->setObjectName(QStringLiteral("updatebookname"));
        updatebookname->setGeometry(QRect(0, 180, 151, 51));
        updatewriter = new QPushButton(groupBox);
        updatewriter->setObjectName(QStringLiteral("updatewriter"));
        updatewriter->setGeometry(QRect(0, 250, 151, 51));
        updatebooktype = new QPushButton(groupBox);
        updatebooktype->setObjectName(QStringLiteral("updatebooktype"));
        updatebooktype->setGeometry(QRect(0, 330, 151, 51));
        updateshelf = new QPushButton(groupBox);
        updateshelf->setObjectName(QStringLiteral("updateshelf"));
        updateshelf->setGeometry(QRect(0, 410, 151, 51));
        updatestatus = new QPushButton(groupBox);
        updatestatus->setObjectName(QStringLiteral("updatestatus"));
        updatestatus->setGeometry(QRect(0, 490, 151, 51));

        retranslateUi(BookUpdate);

        QMetaObject::connectSlotsByName(BookUpdate);
    } // setupUi

    void retranslateUi(QWidget *BookUpdate)
    {
        BookUpdate->setWindowTitle(QApplication::translate("BookUpdate", "\344\277\256\346\224\271\345\233\276\344\271\246\344\277\241\346\201\257", Q_NULLPTR));
        returnbookmanager->setText(QApplication::translate("BookUpdate", "\350\277\224\345\233\236\345\233\276\344\271\246\347\256\241\347\220\206", Q_NULLPTR));
        gotomainpage->setText(QApplication::translate("BookUpdate", "\351\246\226\351\241\265", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        inputid->setPlaceholderText(QApplication::translate("BookUpdate", "\350\276\223\345\205\245ID", Q_NULLPTR));
        inputinfo->setText(QString());
        inputinfo->setPlaceholderText(QApplication::translate("BookUpdate", "\350\276\223\345\205\245\350\246\201\344\277\256\346\224\271\347\232\204\344\277\241\346\201\257", Q_NULLPTR));
        confirm1->setText(QApplication::translate("BookUpdate", "\347\241\256\345\256\232", Q_NULLPTR));
        confirm2->setText(QApplication::translate("BookUpdate", "\347\241\256\345\256\232", Q_NULLPTR));
        updatesure->setText(QApplication::translate("BookUpdate", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BookUpdate", "\344\276\247\350\276\271\350\217\234\345\215\225\346\240\217", Q_NULLPTR));
        updateid->setText(QApplication::translate("BookUpdate", "\344\277\256\346\224\271ID", Q_NULLPTR));
        updateisbn->setText(QApplication::translate("BookUpdate", "\344\277\256\346\224\271ISBN", Q_NULLPTR));
        updatebookname->setText(QApplication::translate("BookUpdate", "\344\277\256\346\224\271\344\271\246\345\220\215", Q_NULLPTR));
        updatewriter->setText(QApplication::translate("BookUpdate", "\344\277\256\346\224\271\344\275\234\350\200\205", Q_NULLPTR));
        updatebooktype->setText(QApplication::translate("BookUpdate", "\344\277\256\346\224\271\347\261\273\345\236\213", Q_NULLPTR));
        updateshelf->setText(QApplication::translate("BookUpdate", "\344\277\256\346\224\271\345\234\250\346\236\266\344\277\241\346\201\257", Q_NULLPTR));
        updatestatus->setText(QApplication::translate("BookUpdate", "\344\277\256\346\224\271\345\200\237\351\230\205\347\212\266\346\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BookUpdate: public Ui_BookUpdate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKUPDATE_H
