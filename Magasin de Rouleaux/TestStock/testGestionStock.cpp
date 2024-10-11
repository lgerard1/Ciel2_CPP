#include "testGestionStock.h"
#include "ui_Stock.h"

TestGestionStock::TestGestionStock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestGestionStock)
{
    ui->setupUi(this);
}

TestGestionStock::~TestGestionStock()
{
    delete ui;
}
