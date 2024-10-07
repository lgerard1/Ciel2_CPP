#ifndef SIRENE_H
#define SIRENE_H

#include <QObject>
#include <QMediaPlayer>

class Sirene : public QObject
{
    Q_OBJECT
public:
    explicit Sirene(QObject *parent = nullptr);
    void Enclencher();
    void Arreter();

signals:

public slots:

private:
    QMediaPlayer son;
};

#endif // SIRENE_H
