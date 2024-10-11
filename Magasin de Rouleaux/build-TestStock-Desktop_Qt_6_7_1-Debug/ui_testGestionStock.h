/********************************************************************************
** Form generated from reading UI file 'testGestionStock.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTGESTIONSTOCK_H
#define UI_TESTGESTIONSTOCK_H

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

class Ui_TestGestionStock
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QListWidget *listWidgetStock;
    QPushButton *pushButtonRetrait;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *listWidgetRouleauxRetenus;
    QPushButton *pushButtonSupprimer;
    QWidget *widget2;
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

    void setupUi(QWidget *TestGestionStock)
    {
        if (TestGestionStock->objectName().isEmpty())
            TestGestionStock->setObjectName("TestGestionStock");
        TestGestionStock->resize(800, 600);
        widget = new QWidget(TestGestionStock);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(350, 150, 191, 321));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        listWidgetStock = new QListWidget(widget);
        listWidgetStock->setObjectName("listWidgetStock");

        verticalLayout->addWidget(listWidgetStock);

        pushButtonRetrait = new QPushButton(widget);
        pushButtonRetrait->setObjectName("pushButtonRetrait");

        verticalLayout->addWidget(pushButtonRetrait);

        widget1 = new QWidget(TestGestionStock);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(560, 150, 211, 321));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        listWidgetRouleauxRetenus = new QListWidget(widget1);
        listWidgetRouleauxRetenus->setObjectName("listWidgetRouleauxRetenus");

        verticalLayout_2->addWidget(listWidgetRouleauxRetenus);

        pushButtonSupprimer = new QPushButton(widget1);
        pushButtonSupprimer->setObjectName("pushButtonSupprimer");

        verticalLayout_2->addWidget(pushButtonSupprimer);

        widget2 = new QWidget(TestGestionStock);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(100, 260, 231, 211));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget2);
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

        pushButtonQuitter = new QPushButton(widget2);
        pushButtonQuitter->setObjectName("pushButtonQuitter");

        verticalLayout_3->addWidget(pushButtonQuitter);


        retranslateUi(TestGestionStock);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, TestGestionStock, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(TestGestionStock);
    } // setupUi

    void retranslateUi(QWidget *TestGestionStock)
    {
        TestGestionStock->setWindowTitle(QCoreApplication::translate("TestGestionStock", "TestAlveolesLibres", nullptr));
        label_4->setText(QCoreApplication::translate("TestGestionStock", "Rouleaux en stock", nullptr));
        pushButtonRetrait->setText(QCoreApplication::translate("TestGestionStock", "Demander retrait", nullptr));
        label_3->setText(QCoreApplication::translate("TestGestionStock", "Rouleaux retenus", nullptr));
        pushButtonSupprimer->setText(QCoreApplication::translate("TestGestionStock", "Supprimer du stock", nullptr));
        groupBox->setTitle(QCoreApplication::translate("TestGestionStock", "Entr\303\251e un rouleau", nullptr));
        label->setText(QCoreApplication::translate("TestGestionStock", "R\303\251f\303\251rence : ", nullptr));
        pushButtonNouveau->setText(QCoreApplication::translate("TestGestionStock", "Ajouter un nouveau", nullptr));
        label_2->setText(QCoreApplication::translate("TestGestionStock", "Diam\303\250tre : ", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("TestGestionStock", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestGestionStock: public Ui_TestGestionStock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTGESTIONSTOCK_H
