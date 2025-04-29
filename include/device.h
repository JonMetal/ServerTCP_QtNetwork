#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>

class Device
{
public:
    Device();
    quint32 countPoints;
    quint16* points;
};

#endif // DEVICE_H
