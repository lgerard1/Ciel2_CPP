#include "testgestiondustock.h"
#include "ui_testgestiondustock.h"

TestGestionDuStock::TestGestionDuStock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestGestionDuStock)
{
    ui->setupUi(this);
}

TestGestionDuStock::~TestGestionDuStock()
{
    delete ui;
}
