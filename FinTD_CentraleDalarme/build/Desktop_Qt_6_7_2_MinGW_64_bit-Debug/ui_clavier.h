/********************************************************************************
** Form generated from reading UI file 'clavier.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLAVIER_H
#define UI_CLAVIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clavier
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxLedVerte;
    QCheckBox *checkBoxLedRouge;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButtonMarche;
    QPushButton *pushButton_0;
    QPushButton *pushButtonArret;

    void setupUi(QWidget *Clavier)
    {
        if (Clavier->objectName().isEmpty())
            Clavier->setObjectName("Clavier");
        Clavier->resize(344, 240);
        layoutWidget = new QWidget(Clavier);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 0, 201, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxLedVerte = new QCheckBox(layoutWidget);
        checkBoxLedVerte->setObjectName("checkBoxLedVerte");
        checkBoxLedVerte->setEnabled(false);

        horizontalLayout->addWidget(checkBoxLedVerte);

        checkBoxLedRouge = new QCheckBox(layoutWidget);
        checkBoxLedRouge->setObjectName("checkBoxLedRouge");
        checkBoxLedRouge->setEnabled(false);

        horizontalLayout->addWidget(checkBoxLedRouge);

        layoutWidget1 = new QWidget(Clavier);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 40, 301, 171));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_1 = new QPushButton(layoutWidget1);
        pushButton_1->setObjectName("pushButton_1");

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget1);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget1);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget1);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget1);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget1);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("background rgb(239, 41, 41)"));

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButtonMarche = new QPushButton(layoutWidget1);
        pushButtonMarche->setObjectName("pushButtonMarche");

        gridLayout->addWidget(pushButtonMarche, 3, 0, 1, 1);

        pushButton_0 = new QPushButton(layoutWidget1);
        pushButton_0->setObjectName("pushButton_0");

        gridLayout->addWidget(pushButton_0, 3, 1, 1, 1);

        pushButtonArret = new QPushButton(layoutWidget1);
        pushButtonArret->setObjectName("pushButtonArret");

        gridLayout->addWidget(pushButtonArret, 3, 2, 1, 1);


        retranslateUi(Clavier);

        QMetaObject::connectSlotsByName(Clavier);
    } // setupUi

    void retranslateUi(QWidget *Clavier)
    {
        Clavier->setWindowTitle(QCoreApplication::translate("Clavier", "Centrale d'alarme", nullptr));
        checkBoxLedVerte->setText(QCoreApplication::translate("Clavier", "Led verte", nullptr));
        checkBoxLedRouge->setText(QCoreApplication::translate("Clavier", "Led Rouge", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Clavier", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Clavier", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Clavier", "3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Clavier", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Clavier", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Clavier", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Clavier", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Clavier", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Clavier", "9", nullptr));
        pushButtonMarche->setText(QCoreApplication::translate("Clavier", "Marche", nullptr));
        pushButton_0->setText(QCoreApplication::translate("Clavier", "0", nullptr));
        pushButtonArret->setText(QCoreApplication::translate("Clavier", "Arr\303\252t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clavier: public Ui_Clavier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLAVIER_H
