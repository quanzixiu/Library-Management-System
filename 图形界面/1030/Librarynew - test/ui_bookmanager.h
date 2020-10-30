/********************************************************************************
** Form generated from reading UI file 'bookmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKMANAGER_H
#define UI_BOOKMANAGER_H

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

class Ui_BookManager
{
public:
    QPushButton *gotomainpage;
    QPushButton *exitlogin;
    QGroupBox *groupBox;
    QPushButton *addbooks;
    QPushButton *updatebooks;
    QPushButton *deletebooks;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QLabel *label;
    QPushButton *confirmsure;
    QLineEdit *le_id;
    QLineEdit *le_isbn;
    QLineEdit *le_writer;
    QLineEdit *le_bookname;
    QLineEdit *le_type;
    QTableWidget *infotable;

    void setupUi(QWidget *BookManager)
    {
        if (BookManager->objectName().isEmpty())
            BookManager->setObjectName(QStringLiteral("BookManager"));
        BookManager->resize(1319, 828);
        gotomainpage = new QPushButton(BookManager);
        gotomainpage->setObjectName(QStringLiteral("gotomainpage"));
        gotomainpage->setGeometry(QRect(1070, 60, 111, 41));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        gotomainpage->setFont(font);
        exitlogin = new QPushButton(BookManager);
        exitlogin->setObjectName(QStringLiteral("exitlogin"));
        exitlogin->setGeometry(QRect(1080, 630, 91, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        exitlogin->setFont(font1);
        groupBox = new QGroupBox(BookManager);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 150, 151, 361));
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
        groupBox_2 = new QGroupBox(BookManager);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(270, 120, 831, 441));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 30, 771, 111));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 10, 281, 31));
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        confirmsure = new QPushButton(groupBox_3);
        confirmsure->setObjectName(QStringLiteral("confirmsure"));
        confirmsure->setGeometry(QRect(660, 40, 91, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(16);
        confirmsure->setFont(font2);
        le_id = new QLineEdit(groupBox_3);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(20, 50, 81, 41));
        le_id->setFont(font);
        le_id->setClearButtonEnabled(false);
        le_isbn = new QLineEdit(groupBox_3);
        le_isbn->setObjectName(QStringLiteral("le_isbn"));
        le_isbn->setGeometry(QRect(100, 50, 81, 41));
        le_isbn->setFont(font);
        le_isbn->setClearButtonEnabled(false);
        le_writer = new QLineEdit(groupBox_3);
        le_writer->setObjectName(QStringLiteral("le_writer"));
        le_writer->setGeometry(QRect(290, 50, 161, 41));
        le_writer->setFont(font);
        le_writer->setClearButtonEnabled(false);
        le_bookname = new QLineEdit(groupBox_3);
        le_bookname->setObjectName(QStringLiteral("le_bookname"));
        le_bookname->setGeometry(QRect(180, 50, 111, 41));
        le_bookname->setFont(font);
        le_bookname->setClearButtonEnabled(false);
        le_type = new QLineEdit(groupBox_3);
        le_type->setObjectName(QStringLiteral("le_type"));
        le_type->setGeometry(QRect(450, 50, 171, 41));
        le_type->setFont(font);
        le_type->setClearButtonEnabled(false);
        infotable = new QTableWidget(groupBox_2);
        if (infotable->columnCount() < 5)
            infotable->setColumnCount(5);
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
        infotable->setObjectName(QStringLiteral("infotable"));
        infotable->setGeometry(QRect(40, 160, 771, 271));
        infotable->setRowCount(0);
        infotable->setColumnCount(5);
        infotable->horizontalHeader()->setStretchLastSection(true);
        infotable->verticalHeader()->setStretchLastSection(false);

        retranslateUi(BookManager);

        QMetaObject::connectSlotsByName(BookManager);
    } // setupUi

    void retranslateUi(QWidget *BookManager)
    {
        BookManager->setWindowTitle(QApplication::translate("BookManager", "\345\233\276\344\271\246\347\256\241\347\220\206", Q_NULLPTR));
        gotomainpage->setText(QApplication::translate("BookManager", "\351\246\226\351\241\265", Q_NULLPTR));
        exitlogin->setText(QApplication::translate("BookManager", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("BookManager", "\344\276\247\350\276\271\350\217\234\345\215\225\346\240\217", Q_NULLPTR));
        addbooks->setText(QApplication::translate("BookManager", "\345\242\236\345\212\240\345\233\276\344\271\246", Q_NULLPTR));
        updatebooks->setText(QApplication::translate("BookManager", "\344\277\256\346\224\271\345\233\276\344\271\246\344\277\241\346\201\257", Q_NULLPTR));
        deletebooks->setText(QApplication::translate("BookManager", "\345\210\240\351\231\244\345\233\276\344\271\246", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        label->setText(QApplication::translate("BookManager", "\350\276\223\345\205\245\345\233\276\344\271\246\344\277\241\346\201\257", Q_NULLPTR));
        confirmsure->setText(QApplication::translate("BookManager", "\347\241\256\345\256\232", Q_NULLPTR));
        le_id->setText(QString());
        le_id->setPlaceholderText(QApplication::translate("BookManager", "ID", Q_NULLPTR));
        le_isbn->setText(QString());
        le_isbn->setPlaceholderText(QApplication::translate("BookManager", "ISBN", Q_NULLPTR));
        le_writer->setText(QString());
        le_writer->setPlaceholderText(QApplication::translate("BookManager", "\344\275\234\350\200\205", Q_NULLPTR));
        le_bookname->setText(QString());
        le_bookname->setPlaceholderText(QApplication::translate("BookManager", "\344\271\246\345\220\215", Q_NULLPTR));
        le_type->setText(QString());
        le_type->setPlaceholderText(QApplication::translate("BookManager", "\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = infotable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("BookManager", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = infotable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("BookManager", "ISBN", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = infotable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("BookManager", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = infotable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("BookManager", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = infotable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("BookManager", "\347\261\273\345\236\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BookManager: public Ui_BookManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKMANAGER_H
