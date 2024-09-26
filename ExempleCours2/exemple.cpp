#include "exemple.h"
#include "ui_exemple.h"

Exemple::Exemple(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Exemple)
{
    ui->setupUi(this);
}

Exemple::~Exemple()
{
    delete ui;
}
