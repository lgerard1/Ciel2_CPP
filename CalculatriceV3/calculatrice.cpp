#include "calculatrice.h"
#include "ui_calculatrice.h"

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
    , NB_TOUCHES(16)
{
    ui->setupUi(this);
    const QString tableDesSymboles[ ] = {"7", "8", "9", "+" ,"4", "5", "6", "-", "1", "2", "3", "*",
                                        "C", "0", "=", "/"};
    grille = new QGridLayout;
    afficheur = new QLineEdit;
    afficheur->setMinimumHeight(50);
    afficheur->setStyleSheet("background-color: rgb(143, 240, 164);color: rgb(0,0,0)");
    touches = new QPushButton*[NB_TOUCHES];
    grille->addWidget(afficheur,0,0,1,4);
    afficheur->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    afficheur->setReadOnly(true);
    QFont font;
    font.setPointSize(15);
    afficheur->setFont(font);
    this->resize(300, 250);
    this->setLayout(grille);
    for (int i =0 ; i < NB_TOUCHES; i++){
        touches[i] = new QPushButton;
        touches[i]->setText(tableDesSymboles[i]);
        touches[i]->setMinimumSize(QSize(50, 50));
        grille->addWidget(touches[i],i/4+1,i%4);
        connect(touches[i], &QPushButton::clicked, this, &Calculatrice::onQpushButtonClicked);
    }
}

Calculatrice::~Calculatrice()
{
    delete ui;
}

void Calculatrice::onQpushButtonClicked()
{
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    if(touche->text() == "=")
    {
        QString expression = afficheur->text();
        QJSEngine myEngine;
        QJSValue calcul = myEngine.evaluate(expression);
        QString resultat = calcul.toString();
        afficheur->setText(resultat);
    }
    else
    {
        if(touche->text() == "C")
            afficheur->clear();
        else{
            QString expression = afficheur->text();
            afficheur->setText(expression + touche ->text());
        }
    }



}
