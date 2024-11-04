/********************************************************************************
** Form generated from reading UI file 'detecteurtemporise.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTEURTEMPORISE_H
#define UI_DETECTEURTEMPORISE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DetecteurTemporise
{
public:
    QPushButton *pushButtonIntrus;

    void setupUi(QDialog *DetecteurTemporise)
    {
        if (DetecteurTemporise->objectName().isEmpty())
            DetecteurTemporise->setObjectName("DetecteurTemporise");
        DetecteurTemporise->resize(379, 140);
        pushButtonIntrus = new QPushButton(DetecteurTemporise);
        pushButtonIntrus->setObjectName("pushButtonIntrus");
        pushButtonIntrus->setGeometry(QRect(10, 10, 361, 121));
        QFont font;
        font.setPointSize(29);
        pushButtonIntrus->setFont(font);

        retranslateUi(DetecteurTemporise);

        QMetaObject::connectSlotsByName(DetecteurTemporise);
    } // setupUi

    void retranslateUi(QDialog *DetecteurTemporise)
    {
        DetecteurTemporise->setWindowTitle(QCoreApplication::translate("DetecteurTemporise", "Dialog", nullptr));
        pushButtonIntrus->setText(QCoreApplication::translate("DetecteurTemporise", "Pr\303\251sence d\303\251tect\303\251e", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetecteurTemporise: public Ui_DetecteurTemporise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTEURTEMPORISE_H
