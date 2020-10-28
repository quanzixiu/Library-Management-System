/********************************************************************************
** Form generated from reading UI file 'usermanager.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGER_H
#define UI_USERMANAGER_H

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

class Ui_UserManager
{
public:
    QPushButton *gotomainpage;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *label;
    QPushButton *confirmsure;
    QLineEdit *le_id;
    QLineEdit *le_name;
    QLineEdit *le_school;
    QLineEdit *le_major;
    QLineEdit *le_email;
    QPushButton *addsure;
    QTableWidget *infotable;
    QGroupBox *sidemenu;
    QPushButton *addusers;
    QPushButton *deleteusers;
    QPushButton *updateusers;
    QPushButton *exitlogin1;

    void setupUi(QWidget *UserManager)
    {
        if (UserManager->objectName().isEmpty())
            UserManager->setObjectName(QStringLiteral("UserManager"));
        UserManager->resize(1200, 740);
        gotomainpage = new QPushButton(UserManager);
        gotomainpage->setObjectName(QStringLiteral("gotomainpage"));
        gotomainpage->setGeometry(QRect(1080, 100, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        gotomainpage->setFont(font);
        groupBox = new QGroupBox(UserManager);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(300, 160, 831, 441));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 30, 771, 111));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 10, 281, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        label->setFont(font1);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        confirmsure = new QPushButton(groupBox_2);
        confirmsure->setObjectName(QStringLiteral("confirmsure"));
        confirmsure->setGeometry(QRect(660, 40, 91, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(16);
        confirmsure->setFont(font2);
        le_id = new QLineEdit(groupBox_2);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(20, 50, 81, 41));
        le_id->setFont(font1);
        le_id->setClearButtonEnabled(false);
        le_name = new QLineEdit(groupBox_2);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setGeometry(QRect(100, 50, 81, 41));
        le_name->setFont(font1);
        le_name->setClearButtonEnabled(false);
        le_school = new QLineEdit(groupBox_2);
        le_school->setObjectName(QStringLiteral("le_school"));
        le_school->setGeometry(QRect(180, 50, 161, 41));
        le_school->setFont(font1);
        le_school->setClearButtonEnabled(false);
        le_major = new QLineEdit(groupBox_2);
        le_major->setObjectName(QStringLiteral("le_major"));
        le_major->setGeometry(QRect(340, 50, 111, 41));
        le_major->setFont(font1);
        le_major->setClearButtonEnabled(false);
        le_email = new QLineEdit(groupBox_2);
        le_email->setObjectName(QStringLiteral("le_email"));
        le_email->setGeometry(QRect(450, 50, 171, 41));
        le_email->setFont(font1);
        le_email->setClearButtonEnabled(false);
        addsure = new QPushButton(groupBox);
        addsure->setObjectName(QStringLiteral("addsure"));
        addsure->setGeometry(QRect(720, 390, 75, 23));
        infotable = new QTableWidget(groupBox);
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
        infotable->raise();
        groupBox_2->raise();
        addsure->raise();
        sidemenu = new QGroupBox(UserManager);
        sidemenu->setObjectName(QStringLiteral("sidemenu"));
        sidemenu->setGeometry(QRect(0, 170, 201, 391));
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
        exitlogin1 = new QPushButton(UserManager);
        exitlogin1->setObjectName(QStringLiteral("exitlogin1"));
        exitlogin1->setGeometry(QRect(1010, 630, 131, 51));
        exitlogin1->setFont(font1);

        retranslateUi(UserManager);

        QMetaObject::connectSlotsByName(UserManager);
    } // setupUi

    void retranslateUi(QWidget *UserManager)
    {
        UserManager->setWindowTitle(QApplication::translate("UserManager", "\347\224\250\346\210\267\347\256\241\347\220\206", Q_NULLPTR));
        gotomainpage->setText(QApplication::translate("UserManager", "\351\246\226\351\241\265", Q_NULLPTR));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("UserManager", "\350\276\223\345\205\245\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        confirmsure->setText(QApplication::translate("UserManager", "\347\241\256\345\256\232", Q_NULLPTR));
        le_id->setText(QString());
        le_id->setPlaceholderText(QApplication::translate("UserManager", "ID", Q_NULLPTR));
        le_name->setText(QString());
        le_name->setPlaceholderText(QApplication::translate("UserManager", "\345\247\223\345\220\215", Q_NULLPTR));
        le_school->setText(QString());
        le_school->setPlaceholderText(QApplication::translate("UserManager", "\345\255\246\346\240\241", Q_NULLPTR));
        le_major->setText(QString());
        le_major->setPlaceholderText(QApplication::translate("UserManager", "\344\270\223\344\270\232", Q_NULLPTR));
        le_email->setText(QString());
        le_email->setPlaceholderText(QApplication::translate("UserManager", "\351\202\256\347\256\261", Q_NULLPTR));
        addsure->setText(QApplication::translate("UserManager", "\346\267\273\345\212\240", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = infotable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserManager", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = infotable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserManager", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = infotable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserManager", "\345\255\246\346\240\241", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = infotable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("UserManager", "\344\270\223\344\270\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = infotable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("UserManager", "\351\202\256\347\256\261", Q_NULLPTR));
        sidemenu->setTitle(QApplication::translate("UserManager", "\344\276\247\350\276\271\350\217\234\345\215\225\346\240\217", Q_NULLPTR));
        addusers->setText(QApplication::translate("UserManager", "\345\242\236\345\212\240\347\224\250\346\210\267", Q_NULLPTR));
        deleteusers->setText(QApplication::translate("UserManager", "\345\210\240\351\231\244\347\224\250\346\210\267", Q_NULLPTR));
        updateusers->setText(QApplication::translate("UserManager", "\344\277\256\346\224\271\347\224\250\346\210\267", Q_NULLPTR));
        exitlogin1->setText(QApplication::translate("UserManager", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserManager: public Ui_UserManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGER_H
