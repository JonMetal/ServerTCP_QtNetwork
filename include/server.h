#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QVector>
#include <QTcpServer>
#include <QTcpSocket>
#include "device.h"
#include "commanddescriptor.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(Device device, QString ip, quint16 port);
    bool state;
    QTcpSocket *socket;
    Device device;
    CommandDescriptor descriptor;
private:
    QVector<QTcpSocket *> Sockets;
    QByteArray Data;
    template<typename Type> void sendToClientValue(Type data);
    template<typename Type> void sendToClientArray(Type* data, quint16 len);
    void callCommand(quint16 Id);
public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
};

#endif // SERVER_H
