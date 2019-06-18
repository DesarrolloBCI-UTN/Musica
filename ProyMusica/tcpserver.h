#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QString>

#define actionIndex     0
#define intensityIndex  1


/*
 * Comandos desde el casco
 */

/*
 * El casco indica 1 como neutro, por eso lo defino como 1
 */
#define NEUTRO QString::number(1)
#define ACCION QString::number(2)




/*
 * Comandos hacia el hardware
 */
#define PARAR       QString::number(100)
#define SUBIR       QString::number(101)
#define BAJAR       QString::number(102)
#define ADELANTE    QString::number(103)
#define ATRAS       QString::number(104)
#define IZQUIERDA   QString::number(105)
#define DERECHA     QString::number(106)

#define INTENSIDAD_BASE 400


#endif // TCPSERVER_H
