/********************************************************************************
** Form generated from reading UI file 'onewelcomew.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEWELCOMEW_H
#define UI_ONEWELCOMEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OneWelcomeW
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QCheckBox *in_checkbox;
    QPushButton *in_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OneWelcomeW)
    {
        if (OneWelcomeW->objectName().isEmpty())
            OneWelcomeW->setObjectName(QStringLiteral("OneWelcomeW"));
        OneWelcomeW->resize(550, 408);
        QFont font;
        font.setPointSize(10);
        OneWelcomeW->setFont(font);
        centralWidget = new QWidget(OneWelcomeW);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 50, 381, 101));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(true);
        in_checkbox = new QCheckBox(centralWidget);
        in_checkbox->setObjectName(QStringLiteral("in_checkbox"));
        in_checkbox->setGeometry(QRect(130, 150, 191, 21));
        QFont font2;
        font2.setPointSize(9);
        in_checkbox->setFont(font2);
        in_button = new QPushButton(centralWidget);
        in_button->setObjectName(QStringLiteral("in_button"));
        in_button->setGeometry(QRect(120, 180, 81, 31));
        QFont font3;
        font3.setPointSize(11);
        in_button->setFont(font3);
        OneWelcomeW->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OneWelcomeW);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 550, 17));
        OneWelcomeW->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OneWelcomeW);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OneWelcomeW->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OneWelcomeW);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OneWelcomeW->setStatusBar(statusBar);

        retranslateUi(OneWelcomeW);

        QMetaObject::connectSlotsByName(OneWelcomeW);
    } // setupUi

    void retranslateUi(QMainWindow *OneWelcomeW)
    {
        OneWelcomeW->setWindowTitle(QApplication::translate("OneWelcomeW", "OneWelcomeW", Q_NULLPTR));
        label->setText(QApplication::translate("OneWelcomeW", "\346\254\242\350\277\216\346\235\245\345\210\260\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\357\274\201", Q_NULLPTR));
        in_checkbox->setText(QApplication::translate("OneWelcomeW", "\345\220\214\346\204\217\344\275\277\347\224\250\345\215\217\350\256\256", Q_NULLPTR));
        in_button->setText(QApplication::translate("OneWelcomeW", "\350\277\233\345\205\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OneWelcomeW: public Ui_OneWelcomeW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEWELCOMEW_H
