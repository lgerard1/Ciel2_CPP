#include "testalveoleslibres.h"
#include "ui_testalveoleslibres.h"

AlveolesLibres::AlveolesLibres(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestdesAlveolesLibres)
{
    ui->setupUi(this);
}

AlveolesLibres::~AlveolesLibres()
{
    delete ui;
}
