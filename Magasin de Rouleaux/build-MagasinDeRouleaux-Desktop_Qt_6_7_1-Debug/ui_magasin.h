/********************************************************************************
** Form generated from reading UI file 'magasin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGASIN_H
#define UI_MAGASIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Magasin
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEditReference;
    QLineEdit *lineEditDiametre;
    QPushButton *pushButtonNouveau;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelStock;
    QListWidget *listWidgetStock;
    QPushButton *pushButtonRetrait;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QListWidget *listWidgetEnceinte;

    void setupUi(QWidget *Magasin)
    {
        if (Magasin->objectName().isEmpty())
            Magasin->setObjectName("Magasin");
        Magasin->resize(800, 600);
        layoutWidget = new QWidget(Magasin);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 110, 231, 141));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditReference = new QLineEdit(groupBox);
        lineEditReference->setObjectName("lineEditReference");

        gridLayout->addWidget(lineEditReference, 0, 1, 1, 1);

        lineEditDiametre = new QLineEdit(groupBox);
        lineEditDiametre->setObjectName("lineEditDiametre");

        gridLayout->addWidget(lineEditDiametre, 2, 1, 1, 1);

        pushButtonNouveau = new QPushButton(groupBox);
        pushButtonNouveau->setObjectName("pushButtonNouveau");
        pushButtonNouveau->setEnabled(true);

        gridLayout->addWidget(pushButtonNouveau, 3, 0, 1, 2);


        verticalLayout_3->addWidget(groupBox);

        layoutWidget_2 = new QWidget(Magasin);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(280, 110, 191, 321));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelStock = new QLabel(layoutWidget_2);
        labelStock->setObjectName("labelStock");

        verticalLayout->addWidget(labelStock);

        listWidgetStock = new QListWidget(layoutWidget_2);
        listWidgetStock->setObjectName("listWidgetStock");

        verticalLayout->addWidget(listWidgetStock);

        pushButtonRetrait = new QPushButton(layoutWidget_2);
        pushButtonRetrait->setObjectName("pushButtonRetrait");

        verticalLayout->addWidget(pushButtonRetrait);

        widget = new QWidget(Magasin);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(490, 110, 191, 171));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        listWidgetEnceinte = new QListWidget(widget);
        listWidgetEnceinte->setObjectName("listWidgetEnceinte");

        gridLayout_2->addWidget(listWidgetEnceinte, 1, 0, 1, 1);


        retranslateUi(Magasin);

        QMetaObject::connectSlotsByName(Magasin);
    } // setupUi

    void retranslateUi(QWidget *Magasin)
    {
        Magasin->setWindowTitle(QCoreApplication::translate("Magasin", "Magasin", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Magasin", "Entr\303\251e d'un rouleau", nullptr));
        label_2->setText(QCoreApplication::translate("Magasin", "Diam\303\250tre : ", nullptr));
        label->setText(QCoreApplication::translate("Magasin", "R\303\251f\303\251rence : ", nullptr));
        pushButtonNouveau->setText(QCoreApplication::translate("Magasin", "Entrer un rouleau", nullptr));
        labelStock->setText(QCoreApplication::translate("Magasin", "Rouleaux dans le stock", nullptr));
        pushButtonRetrait->setText(QCoreApplication::translate("Magasin", "Sortir une s\303\251rie de rouleaux", nullptr));
        label_3->setText(QCoreApplication::translate("Magasin", "Rouleaux dans l'enceinte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Magasin: public Ui_Magasin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGASIN_H
