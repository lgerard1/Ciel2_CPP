#ifndef TESTGESTIONDUSTOCK_H
#define TESTGESTIONDUSTOCK_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TestGestionDuStock;
}
QT_END_NAMESPACE

class TestGestionDuStock : public QWidget
{
    Q_OBJECT

public:
    TestGestionDuStock(QWidget *parent = nullptr);
    ~TestGestionDuStock();

private:
    Ui::TestGestionDuStock *ui;
};
#endif // TESTGESTIONDUSTOCK_H
