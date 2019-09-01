#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QString>

#define actionIndex     0
#define intensityIndex  1


/*
 * Comandos desde el casco
 */
#define NEUTRO QString::number(1)
#define ACCION QString::number(2)

/*
 * Comandos hacia el hardware
 */
#define INTENSIDAD_BASE 400


#endif // TCPSERVER_H
