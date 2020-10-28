/********************************************************************************
** Form generated from reading UI file 'bookdelete.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKDELETE_H
#define UI_BOOKDELETE_H

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

class Ui_BookDelete
{
public:
    QGroupBox *groupBox;
    QPushButton *addbooks;
    QPushButton *updatebooks;
    QPushButton *deletebooks;
    QPushButton *gotomainpage;
    QPushButton *exitlogin;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QPushButton *confirmsure;
    QLineEdit *le_id;
    QPushButton *deletesure;
    QTableWidget *borrowinfotable;

    void setupUi(QWidget *BookDelete)
    {
        if (BookDelete->objectName().isEmpty())
            BookDelete->setObjectName(QStringLiteral("BookDelete"));
        BookDelete->resize(1329, 836);
        groupBox = new QGroupBox(BookDelete);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 200, 151, 361));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        groupBox->setFont(font);
        addbooks = new QPushButton(groupBox);
        addbooks->setObjectName(QStringLiteral("addbooks"));
        addbooks->setGeometry(QRect(0, 60, 151, 51));
        updatebooks = new QPushButton(groupBox);
        updatebooks->setObjectName(QStringLiteral("updatebooks"));
        updatebooks->setGeometry(QRect(0, 140, 151, 51));
        deletebooks = new QPushButton(groupBox);
        deletebooks->setObjectName(QStringLiteral("deletebooks"));
        deletebooks->setGeometry(QRect(0, 230, 151, 51));
        gotomainpage = new QPushButton(BookDelete);
        gotomainpage->setObjectName(QStringLiteral("gotomainpage"));
        gotomainpage->setGeometry(QRect(1060, 10, 111, 41));
        gotomainpage->setFont(font);
        exitlogin = new QPushButton(BookDelete);
        exitlogin->setObjectName(QStringLiteral("exitlogin"));
        exitlogin->setGeometry(QRect(1080, 800, 91, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        exitlogin->setFont(font1);
        groupBox_2 = new QGroupBox(BookDelete);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(220, 100, 851, 671));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 30, 771, 111));
        confirmsure = new QPushButton(groupBox_3);
        confirmsure->setObjectName(QStringLiteral("confirmsure"));
        confirmsure->setGeometry(QRect(650, 30, 91, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(16);
        confirmsure->setFont(font2);
        le_id = new QLineEdit(groupBox_3);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(30, 40, 571, 41));
        le_id->setFont(font);
        le_id->setClearButtonEnabled(false);
        deletesure = new QPushButton(groupBox_2);
        deletesure->setObjectName(QStringLiteral("deletesure"));
        deletesure->setGeometry(QRect(720, 610, 75, 23));
        borrowinfotable = new QTableWidget(groupBox_2);
        borrowinfotable->setObjectName(QStringLiteral("borrowinfotable"));
        borrowinfotable->setGeometry(QRect(40, 170, 781, 481));
        groupBox_3->raise();
        borrowinfotable->raise();
        deletesure->raise();

        retranslateUi(BookDelete);

        QMetaObject::connectSlotsByName(BookDelete);
    } // setupUi

    void retranslateUi(QWidget *BookDelete)
    {
        BookDelete->setWindowTitle(QApplication::translate("BookDelete", "\345\233\276\344\271\246\347\256\241\347\220\206", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BookDelete", "\344\276\247\350\276\271\350\217\234\345\215\225\346\240\217", Q_NULLPTR));
        addbooks->setText(QApplication::translate("BookDelete", "\345\242\236\345\212\240\345\233\276\344\271\246", Q_NULLPTR));
        updatebooks->setText(QApplication::translate("BookDelete", "\344\277\256\346\224\271\345\233\276\344\271\246\344\277\241\346\201\257", Q_NULLPTR));
        deletebooks->setText(QApplication::translate("BookDelete", "\345\210\240\351\231\244\345\233\276\344\271\246", Q_NULLPTR));
        gotomainpage->setText(QApplication::translate("BookDelete", "\351\246\226\351\241\265", Q_NULLPTR));
        exitlogin->setText(QApplication::translate("BookDelete", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        confirmsure->setText(QApplication::translate("BookDelete", "\347\241\256\345\256\232", Q_NULLPTR));
        le_id->setText(QString());
        le_id->setPlaceholderText(QApplication::translate("BookDelete", "\350\276\223\345\205\245\345\233\276\344\271\246ID", Q_NULLPTR));
        deletesure->setText(QApplication::translate("BookDelete", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BookDelete: public Ui_BookDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKDELETE_H
