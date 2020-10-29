/********************************************************************************
** Form generated from reading UI file 'elevenuserwid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELEVENUSERWID_H
#define UI_ELEVENUSERWID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ElevenUserwid
{
public:
    QLabel *label;
    QPushButton *seek_button;
    QPushButton *borrowed_button;
    QPushButton *returnbook_button;
    QPushButton *relogin_button;

    void setupUi(QWidget *ElevenUserwid)
    {
        if (ElevenUserwid->objectName().isEmpty())
            ElevenUserwid->setObjectName(QStringLiteral("ElevenUserwid"));
        ElevenUserwid->resize(462, 320);
        label = new QLabel(ElevenUserwid);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 50, 71, 31));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(true);
        seek_button = new QPushButton(ElevenUserwid);
        seek_button->setObjectName(QStringLiteral("seek_button"));
        seek_button->setGeometry(QRect(90, 90, 141, 41));
        QFont font1;
        font1.setPointSize(11);
        seek_button->setFont(font1);
        seek_button->setLayoutDirection(Qt::LeftToRight);
        seek_button->setAutoFillBackground(true);
        borrowed_button = new QPushButton(ElevenUserwid);
        borrowed_button->setObjectName(QStringLiteral("borrowed_button"));
        borrowed_button->setGeometry(QRect(90, 140, 141, 41));
        borrowed_button->setFont(font1);
        borrowed_button->setLayoutDirection(Qt::LeftToRight);
        borrowed_button->setAutoFillBackground(true);
        returnbook_button = new QPushButton(ElevenUserwid);
        returnbook_button->setObjectName(QStringLiteral("returnbook_button"));
        returnbook_button->setGeometry(QRect(90, 190, 141, 41));
        returnbook_button->setFont(font1);
        returnbook_button->setAutoFillBackground(true);
        relogin_button = new QPushButton(ElevenUserwid);
        relogin_button->setObjectName(QStringLiteral("relogin_button"));
        relogin_button->setGeometry(QRect(210, 250, 91, 31));

        retranslateUi(ElevenUserwid);

        QMetaObject::connectSlotsByName(ElevenUserwid);
    } // setupUi

    void retranslateUi(QWidget *ElevenUserwid)
    {
        ElevenUserwid->setWindowTitle(QApplication::translate("ElevenUserwid", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ElevenUserwid", "\351\246\226\351\241\265", Q_NULLPTR));
        seek_button->setText(QApplication::translate("ElevenUserwid", "\346\237\245\346\211\276\345\200\237\351\230\205\345\233\276\344\271\246", Q_NULLPTR));
        borrowed_button->setText(QApplication::translate("ElevenUserwid", "\345\267\262\345\200\237\345\233\276\344\271\246", Q_NULLPTR));
        returnbook_button->setText(QApplication::translate("ElevenUserwid", "\345\275\222\350\277\230\345\233\276\344\271\246", Q_NULLPTR));
        relogin_button->setText(QApplication::translate("ElevenUserwid", "\351\200\200\345\207\272\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ElevenUserwid: public Ui_ElevenUserwid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELEVENUSERWID_H
