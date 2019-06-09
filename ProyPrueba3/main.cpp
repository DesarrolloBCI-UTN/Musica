#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

void read(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }

    QTextStream in(&file);
    QString myText = in.readAll();

    // put QString into qDebug stream
    qDebug() << myText;

    file.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    read(":/iconos.qrc");
    MainWindow w;
    w.show();

    return a.exec();
}
