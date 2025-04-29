#ifndef COMMANDDESCRIPTOR_H
#define COMMANDDESCRIPTOR_H

#include <QMultiMap>

class CommandDescriptor
{
public:
    CommandDescriptor();
    int getCommandId(QString command);
private:
    QMultiMap<QString, int> commandMap;
};


#endif // COMMANDDESCRIPTOR_H
