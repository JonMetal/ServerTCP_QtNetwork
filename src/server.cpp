#include "../include/server.h"
#include <iostream>

Server::Server(Device device, QString ip, quint16 port) {
    if(this->listen(QHostAddress(ip), port))
    {
        std::cout << "Start" << std::endl;
    }
    this->device = device;
    state = 1;
}

void Server::incomingConnection(qintptr socketDescriptor) {
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

void Server::slotReadyRead() {
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_8);
    if(in.status() == QDataStream::Ok) {
        QString str;
        in >> str;
        callCommand(descriptor.getCommandId(str));
    }
}

void Server::callCommand(quint16 Id) {
    switch(Id) {
    case 0:
        std::cout << "unidentified request" << std::endl;
        break;
    case 1:
        std::cout << "SYST: STAT" << std::endl;
        sendToClientValue(state);
        break;
    case 2:
        std::cout << "MEAS: POIN" << std::endl;
        sendToClientValue(device.countPoints);
        break;
    case 3:
        std::cout << "MEAS: DATA" << std::endl;
        sendToClientArray(device.points, device.countPoints);
        break;
    }
}

template<typename Type> void Server::sendToClientValue(Type data) {
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_8);
    out << data;
    socket->write(Data);
}

template<typename Type> void Server::sendToClientArray(Type* data, quint16 len) {
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_8);
    for(quint16 i = 0; i < len; i++) {
        out << data[i];
    }
    socket->write(Data);
}
