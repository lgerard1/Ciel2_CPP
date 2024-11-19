/********************************************************************************
** Form generated from reading UI file 'serveur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVEUR_H
#define UI_SERVEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serveur
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEditMeteo;
    QLabel *label_3;
    QPushButton *pushButtonSupprimer;
    QLabel *label;
    QLabel *label_4;
    QPushButton *pushButtonAlerte;
    QLabel *label_2;
    QPushButton *pushButtonDiffusion;
    QPushButton *pushButtonMeteo;
    QTextEdit *textEditAlerte;
    QTextEdit *textEditInformation;
    QPushButton *pushButtonAjouter;
    QListWidget *listWidgetMessage;

    void setupUi(QWidget *Serveur)
    {
        if (Serveur->objectName().isEmpty())
            Serveur->setObjectName("Serveur");
        Serveur->resize(800, 600);
        gridLayout = new QGridLayout(Serveur);
        gridLayout->setObjectName("gridLayout");
        lineEditMeteo = new QLineEdit(Serveur);
        lineEditMeteo->setObjectName("lineEditMeteo");

        gridLayout->addWidget(lineEditMeteo, 7, 0, 1, 1);

        label_3 = new QLabel(Serveur);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        pushButtonSupprimer = new QPushButton(Serveur);
        pushButtonSupprimer->setObjectName("pushButtonSupprimer");

        gridLayout->addWidget(pushButtonSupprimer, 5, 3, 1, 1);

        label = new QLabel(Serveur);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_4 = new QLabel(Serveur);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        pushButtonAlerte = new QPushButton(Serveur);
        pushButtonAlerte->setObjectName("pushButtonAlerte");

        gridLayout->addWidget(pushButtonAlerte, 5, 0, 1, 1);

        label_2 = new QLabel(Serveur);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        pushButtonDiffusion = new QPushButton(Serveur);
        pushButtonDiffusion->setObjectName("pushButtonDiffusion");

        gridLayout->addWidget(pushButtonDiffusion, 8, 0, 1, 4);

        pushButtonMeteo = new QPushButton(Serveur);
        pushButtonMeteo->setObjectName("pushButtonMeteo");

        gridLayout->addWidget(pushButtonMeteo, 7, 1, 1, 3);

        textEditAlerte = new QTextEdit(Serveur);
        textEditAlerte->setObjectName("textEditAlerte");

        gridLayout->addWidget(textEditAlerte, 4, 0, 1, 1);

        textEditInformation = new QTextEdit(Serveur);
        textEditInformation->setObjectName("textEditInformation");

        gridLayout->addWidget(textEditInformation, 1, 0, 1, 2);

        pushButtonAjouter = new QPushButton(Serveur);
        pushButtonAjouter->setObjectName("pushButtonAjouter");

        gridLayout->addWidget(pushButtonAjouter, 2, 0, 1, 2);

        listWidgetMessage = new QListWidget(Serveur);
        listWidgetMessage->setObjectName("listWidgetMessage");

        gridLayout->addWidget(listWidgetMessage, 1, 3, 4, 1);


        retranslateUi(Serveur);

        QMetaObject::connectSlotsByName(Serveur);
    } // setupUi

    void retranslateUi(QWidget *Serveur)
    {
        Serveur->setWindowTitle(QCoreApplication::translate("Serveur", "Serveur", nullptr));
        label_3->setText(QCoreApplication::translate("Serveur", "Liste des messages en cours de diffusion : ", nullptr));
        pushButtonSupprimer->setText(QCoreApplication::translate("Serveur", "Supprimer un message", nullptr));
        label->setText(QCoreApplication::translate("Serveur", "Message d'information :", nullptr));
        label_4->setText(QCoreApplication::translate("Serveur", "Bulletin m\303\251t\303\251o : ", nullptr));
        pushButtonAlerte->setText(QCoreApplication::translate("Serveur", "Cr\303\251er une alerte ", nullptr));
        label_2->setText(QCoreApplication::translate("Serveur", "Message d'alerte : ", nullptr));
        pushButtonDiffusion->setText(QCoreApplication::translate("Serveur", "Lancer la diffusion", nullptr));
        pushButtonMeteo->setText(QCoreApplication::translate("Serveur", "Modifier le bulletin m\303\251t\303\251o", nullptr));
        pushButtonAjouter->setText(QCoreApplication::translate("Serveur", "Ajouter un message ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Serveur: public Ui_Serveur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVEUR_H
