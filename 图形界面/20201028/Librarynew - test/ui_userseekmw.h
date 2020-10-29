/********************************************************************************
** Form generated from reading UI file 'userseekmw.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSEEKMW_H
#define UI_USERSEEKMW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserSeekMw
{
public:
    QWidget *centralwidget;
    QGroupBox *menuseek_groupbox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *bookcard_button;
    QPushButton *usershouye_button;
    QPushButton *return_button;
    QGroupBox *groupBox;
    QLineEdit *id_linedit;
    QPushButton *seekok_button;
    QTableWidget *infobook_tablewid;
    QPushButton *borrowok_button;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserSeekMw)
    {
        if (UserSeekMw->objectName().isEmpty())
            UserSeekMw->setObjectName(QStringLiteral("UserSeekMw"));
        UserSeekMw->resize(755, 505);
        centralwidget = new QWidget(UserSeekMw);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        menuseek_groupbox = new QGroupBox(centralwidget);
        menuseek_groupbox->setObjectName(QStringLiteral("menuseek_groupbox"));
        menuseek_groupbox->setGeometry(QRect(0, 150, 131, 231));
        QFont font;
        font.setPointSize(10);
        menuseek_groupbox->setFont(font);
        pushButton = new QPushButton(menuseek_groupbox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 30, 101, 41));
        pushButton_2 = new QPushButton(menuseek_groupbox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 70, 101, 41));
        pushButton_3 = new QPushButton(menuseek_groupbox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 110, 101, 41));
        pushButton_4 = new QPushButton(menuseek_groupbox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 150, 101, 41));
        bookcard_button = new QPushButton(menuseek_groupbox);
        bookcard_button->setObjectName(QStringLiteral("bookcard_button"));
        bookcard_button->setGeometry(QRect(0, 190, 101, 41));
        usershouye_button = new QPushButton(centralwidget);
        usershouye_button->setObjectName(QStringLiteral("usershouye_button"));
        usershouye_button->setGeometry(QRect(510, 70, 81, 31));
        return_button = new QPushButton(centralwidget);
        return_button->setObjectName(QStringLiteral("return_button"));
        return_button->setGeometry(QRect(620, 410, 81, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(150, 120, 431, 331));
        id_linedit = new QLineEdit(groupBox);
        id_linedit->setObjectName(QStringLiteral("id_linedit"));
        id_linedit->setGeometry(QRect(60, 20, 113, 20));
        seekok_button = new QPushButton(groupBox);
        seekok_button->setObjectName(QStringLiteral("seekok_button"));
        seekok_button->setGeometry(QRect(220, 20, 51, 21));
        infobook_tablewid = new QTableWidget(groupBox);
        if (infobook_tablewid->columnCount() < 6)
            infobook_tablewid->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        infobook_tablewid->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        infobook_tablewid->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        infobook_tablewid->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        infobook_tablewid->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        infobook_tablewid->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        infobook_tablewid->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        infobook_tablewid->setObjectName(QStringLiteral("infobook_tablewid"));
        infobook_tablewid->setGeometry(QRect(-10, 50, 431, 191));
        infobook_tablewid->horizontalHeader()->setStretchLastSection(true);
        borrowok_button = new QPushButton(groupBox);
        borrowok_button->setObjectName(QStringLiteral("borrowok_button"));
        borrowok_button->setGeometry(QRect(340, 280, 51, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 10, 201, 71));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAutoFillBackground(true);
        UserSeekMw->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserSeekMw);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 755, 17));
        UserSeekMw->setMenuBar(menubar);
        statusbar = new QStatusBar(UserSeekMw);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UserSeekMw->setStatusBar(statusbar);

        retranslateUi(UserSeekMw);

        QMetaObject::connectSlotsByName(UserSeekMw);
    } // setupUi

    void retranslateUi(QMainWindow *UserSeekMw)
    {
        UserSeekMw->setWindowTitle(QApplication::translate("UserSeekMw", "MainWindow", Q_NULLPTR));
        menuseek_groupbox->setTitle(QApplication::translate("UserSeekMw", "\344\276\247\350\276\271\350\217\234\345\215\225\346\240\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("UserSeekMw", "ID\346\237\245\346\211\276", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("UserSeekMw", "ISBN\346\237\245\346\211\276", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("UserSeekMw", "\344\271\246\345\220\215\346\237\245\346\211\276", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("UserSeekMw", "\345\210\206\347\261\273\346\265\217\350\247\210", Q_NULLPTR));
        bookcard_button->setText(QApplication::translate("UserSeekMw", "\345\200\237\344\271\246\345\215\241", Q_NULLPTR));
        usershouye_button->setText(QApplication::translate("UserSeekMw", "\351\246\226\351\241\265", Q_NULLPTR));
        return_button->setText(QApplication::translate("UserSeekMw", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("UserSeekMw", "\350\257\267\345\205\210\351\200\211\346\213\251\346\237\245\346\211\276\346\226\271\345\274\217\357\274\214\345\234\250\344\270\213\346\226\271\350\276\223\345\205\245ISBN\346\210\226ID\346\210\226\344\271\246\345\220\215", Q_NULLPTR));
        seekok_button->setText(QApplication::translate("UserSeekMw", "\347\241\256\345\256\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = infobook_tablewid->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserSeekMw", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = infobook_tablewid->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserSeekMw", "\344\271\246\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = infobook_tablewid->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserSeekMw", "ISBN", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = infobook_tablewid->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("UserSeekMw", "\345\234\250\346\236\266\344\277\241\346\201\257", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = infobook_tablewid->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("UserSeekMw", "\344\275\234\350\200\205", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = infobook_tablewid->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("UserSeekMw", "\347\261\273\345\236\213", Q_NULLPTR));
        borrowok_button->setText(QApplication::translate("UserSeekMw", "\345\200\237\351\230\205", Q_NULLPTR));
        label->setText(QApplication::translate("UserSeekMw", "\346\237\245\346\211\276\345\200\237\351\230\205\345\233\276\344\271\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserSeekMw: public Ui_UserSeekMw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSEEKMW_H
