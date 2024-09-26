#include "splitterwidget.h"
#include "ui_splitterwidget.h"
#include <QString>
#include <QStringList>

SplitterWidget::SplitterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SplitterWidget)
{
    ui->setupUi(this);
}

SplitterWidget::~SplitterWidget()
{
    delete ui;
}


void SplitterWidget::on_pushButtonDecoder_clicked()
{
    QString texte = ui->lineEditDecoder->text();
    QStringList liste = texte.split(";");
    ui->lineEditNom->setText(liste.at(0));
    ui->lineEditPrenom->setText(liste.at(1));
    ui->lineEditAge->setText(liste.at(2));
    ui->lcdNumberAge->value(liste.at(2).toInt());
    ui->lineEditPoids->setText(liste.at(3));
    ui->lineEditTaille->setText(liste.at(4));
}

