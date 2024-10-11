#ifndef TESTGESTIONSTOCK_H
#define TESTGESTIONSTOCK_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TestGestionStock;
}
QT_END_NAMESPACE

class TestGestionStock : public QWidget
{
    Q_OBJECT

public:
    TestGestionStock(QWidget *parent = nullptr);
    ~TestGestionStock();

private:
    Ui::TestGestionStock *ui;
};
#endif // TESTGESTIONSTOCK_H
