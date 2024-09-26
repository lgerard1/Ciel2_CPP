#include "monwidget.h"
#include "ui_monwidget.h"
#include <QMessageBox>

MonWidget::MonWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MonWidget)
{
    ui->setupUi(this);
}

MonWidget::~MonWidget()
{
    delete ui;
}

void MonWidget::on_pushButton1erbouton_clicked()
{
    QMessageBox message;
    message.setText("Bonjour");
    message.exec();
    ui->pushButton1erbouton->setText("Bonjour");
    ui->groupBox->hide();
}

