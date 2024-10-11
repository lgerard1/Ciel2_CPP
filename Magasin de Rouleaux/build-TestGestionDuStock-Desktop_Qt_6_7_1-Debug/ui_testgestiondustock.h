/********************************************************************************
** Form generated from reading UI file 'testgestiondustock.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTGESTIONDUSTOCK_H
#define UI_TESTGESTIONDUSTOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestGestionDuStock
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonNouveau;
    QLabel *label_2;
    QLineEdit *lineEditReference;
    QLineEdit *lineEditDiametre;
    QPushButton *pushButtonQuitter;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QListWidget *listWidgetStock;
    QPushButton *pushButtonRetrait;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *listWidgetRouleauxRetenus;
    QPushButton *pushButtonSupprimer;

    void setupUi(QWidget *TestGestionDuStock)
    {
        if (TestGestionDuStock->objectName().isEmpty())
            TestGestionDuStock->setObjectName("TestGestionDuStock");
        TestGestionDuStock->resize(800, 600);
        layoutWidget = new QWidget(TestGestionDuStock);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 180, 231, 211));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 2);

        pushButtonNouveau = new QPushButton(groupBox);
        pushButtonNouveau->setObjectName("pushButtonNouveau");

        gridLayout->addWidget(pushButtonNouveau, 4, 0, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEditReference = new QLineEdit(groupBox);
        lineEditReference->setObjectName("lineEditReference");

        gridLayout->addWidget(lineEditReference, 0, 1, 1, 1);

        lineEditDiametre = new QLineEdit(groupBox);
        lineEditDiametre->setObjectName("lineEditDiametre");

        gridLayout->addWidget(lineEditDiametre, 2, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        pushButtonQuitter = new QPushButton(layoutWidget);
        pushButtonQuitter->setObjectName("pushButtonQuitter");

        verticalLayout_3->addWidget(pushButtonQuitter);

        layoutWidget_2 = new QWidget(TestGestionDuStock);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(310, 70, 191, 321));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        listWidgetStock = new QListWidget(layoutWidget_2);
        listWidgetStock->setObjectName("listWidgetStock");

        verticalLayout->addWidget(listWidgetStock);

        pushButtonRetrait = new QPushButton(layoutWidget_2);
        pushButtonRetrait->setObjectName("pushButtonRetrait");

        verticalLayout->addWidget(pushButtonRetrait);

        layoutWidget_3 = new QWidget(TestGestionDuStock);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(520, 70, 211, 321));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        listWidgetRouleauxRetenus = new QListWidget(layoutWidget_3);
        listWidgetRouleauxRetenus->setObjectName("listWidgetRouleauxRetenus");

        verticalLayout_2->addWidget(listWidgetRouleauxRetenus);

        pushButtonSupprimer = new QPushButton(layoutWidget_3);
        pushButtonSupprimer->setObjectName("pushButtonSupprimer");

        verticalLayout_2->addWidget(pushButtonSupprimer);


        retranslateUi(TestGestionDuStock);

        QMetaObject::connectSlotsByName(TestGestionDuStock);
    } // setupUi

    void retranslateUi(QWidget *TestGestionDuStock)
    {
        TestGestionDuStock->setWindowTitle(QCoreApplication::translate("TestGestionDuStock", "TestGestionDuStock", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TestGestionDuStock", "Entr\303\251e un rouleau", nullptr));
        label->setText(QCoreApplication::translate("TestGestionDuStock", "R\303\251f\303\251rence : ", nullptr));
        pushButtonNouveau->setText(QCoreApplication::translate("TestGestionDuStock", "Ajouter un nouveau", nullptr));
        label_2->setText(QCoreApplication::translate("TestGestionDuStock", "Diam\303\250tre : ", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("TestGestionDuStock", "Quitter", nullptr));
        label_4->setText(QCoreApplication::translate("TestGestionDuStock", "Rouleaux en stock", nullptr));
        pushButtonRetrait->setText(QCoreApplication::translate("TestGestionDuStock", "Demander retrait", nullptr));
        label_3->setText(QCoreApplication::translate("TestGestionDuStock", "Rouleaux retenus", nullptr));
        pushButtonSupprimer->setText(QCoreApplication::translate("TestGestionDuStock", "Supprimer du stock", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestGestionDuStock: public Ui_TestGestionDuStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTGESTIONDUSTOCK_H
