/********************************************************************************
** Form generated from reading UI file 'twologind.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOLOGIND_H
#define UI_TWOLOGIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TwoLoginD
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *id_linedit;
    QLineEdit *password_linedit;
    QCheckBox *checkBox;
    QPushButton *login_button;
    QPushButton *return_button;

    void setupUi(QDialog *TwoLoginD)
    {
        if (TwoLoginD->objectName().isEmpty())
            TwoLoginD->setObjectName(QStringLiteral("TwoLoginD"));
        TwoLoginD->resize(494, 351);
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        TwoLoginD->setFont(font);
        TwoLoginD->setLayoutDirection(Qt::LeftToRight);
        TwoLoginD->setAutoFillBackground(true);
        label = new QLabel(TwoLoginD);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 50, 71, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(TwoLoginD);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 90, 41, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAutoFillBackground(true);
        label_3 = new QLabel(TwoLoginD);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 120, 41, 21));
        label_3->setFont(font2);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAutoFillBackground(true);
        id_linedit = new QLineEdit(TwoLoginD);
        id_linedit->setObjectName(QStringLiteral("id_linedit"));
        id_linedit->setGeometry(QRect(120, 90, 113, 20));
        id_linedit->setFont(font);
        password_linedit = new QLineEdit(TwoLoginD);
        password_linedit->setObjectName(QStringLiteral("password_linedit"));
        password_linedit->setGeometry(QRect(120, 120, 113, 20));
        password_linedit->setFont(font);
        checkBox = new QCheckBox(TwoLoginD);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(240, 120, 141, 31));
        login_button = new QPushButton(TwoLoginD);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(140, 150, 61, 31));
        return_button = new QPushButton(TwoLoginD);
        return_button->setObjectName(QStringLiteral("return_button"));
        return_button->setGeometry(QRect(230, 200, 81, 31));

        retranslateUi(TwoLoginD);

        QMetaObject::connectSlotsByName(TwoLoginD);
    } // setupUi

    void retranslateUi(QDialog *TwoLoginD)
    {
        TwoLoginD->setWindowTitle(QApplication::translate("TwoLoginD", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("TwoLoginD", "\347\231\273\345\275\225", Q_NULLPTR));
        label_2->setText(QApplication::translate("TwoLoginD", "\350\264\246\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("TwoLoginD", "\345\257\206\347\240\201", Q_NULLPTR));
        checkBox->setText(QApplication::translate("TwoLoginD", "\347\256\241\347\220\206\345\221\230\350\272\253\344\273\275", Q_NULLPTR));
        login_button->setText(QApplication::translate("TwoLoginD", "\347\241\256\345\256\232", Q_NULLPTR));
        return_button->setText(QApplication::translate("TwoLoginD", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TwoLoginD: public Ui_TwoLoginD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOLOGIND_H
