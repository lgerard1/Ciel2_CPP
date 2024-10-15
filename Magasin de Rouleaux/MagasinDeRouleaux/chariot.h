#ifndef CHARIOT_H
#define CHARIOT_H
#include <QObject>

class Chariot : public QObject
{
    Q_OBJECT
public:
    explicit Chariot(QObject *parent = nullptr);
    void DeplacerChariot(const int _rangee, const int _colonne, const bool _sens);

signals:
};

#endif // CHARIOT_H
