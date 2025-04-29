#include "../include/device.h"
#include <QRandomGenerator>

Device::Device() {
    countPoints = 1000;
    QRandomGenerator gen1 = QRandomGenerator();
    points = new quint16[1000];
    for(quint16 i = 0; i < 1000; i++) {
        points[i] = (gen1.bounded(100));
    }
}
