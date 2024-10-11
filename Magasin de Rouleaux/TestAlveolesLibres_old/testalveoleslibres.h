#ifndef TESTALVEOLESLIBRES_H
#define TESTALVEOLESLIBRES_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class AlveolesLibres;
}
QT_END_NAMESPACE

class AlveolesLibres : public QWidget
{
    Q_OBJECT

public:
    AlveolesLibres(QWidget *parent = nullptr);
    ~AlveolesLibres();

private:
    Ui::AlveolesLibres *ui;
};
#endif // TESTALVEOLESLIBRES_H
