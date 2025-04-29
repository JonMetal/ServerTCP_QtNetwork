#include "../include/commanddescriptor.h"

CommandDescriptor::CommandDescriptor() {
    commandMap.insert("SYSTem: STATe?", 1);
    commandMap.insert("SYST: STAT?", 1);
    commandMap.insert("MEASure: POINts?", 2);
    commandMap.insert("MEAS: POIN?", 2);
    commandMap.insert("MEASure: DATA?", 3);
    commandMap.insert("MEAS: DATA?", 3);
}

int CommandDescriptor::getCommandId(QString command) {
    return commandMap.value(command);
}

