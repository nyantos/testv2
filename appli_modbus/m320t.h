#ifndef M320T_H
#define M320T_H

#include <QObject>
#include <QModbusTcpClient>
#include <QDebug>


class M320T : public QObject
{
    Q_OBJECT
public:
    explicit M320T(QObject *parent = nullptr);



private:


signals:



};

#endif // M320T_H
