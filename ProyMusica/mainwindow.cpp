#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <QDataStream>
#include <string.h>
#include <QFile>
#include <QDebug>
#include <QPixmap>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//armar array de reproductores
void MainWindow::on_BotonBombo_clicked()
{
    QMediaPlayer *reproductor1 = new QMediaPlayer();
    QMediaPlayer *reproductor2 = new QMediaPlayer();
    reproductor1->setMedia(QUrl("qrc:/sonidos/kick_7.wav"));
    reproductor2->setMedia(QUrl("qrc:/Closed-Hi-Hat-1.wav"));
    reproductor1->play();
    reproductor2->play();
}

void MainWindow::on_BotonHiHat_clicked()
{
    QMediaPlayer *reproductor = new QMediaPlayer();
    reproductor->setMedia(QUrl("qrc:/sonidos/Closed-Hi-Hat-1.wav"));
    reproductor->play();
}

void MainWindow::on_BotonRedoblante_clicked()
{
    QMediaPlayer *reproductor1 = new QMediaPlayer();
    QMediaPlayer *reproductor2 = new QMediaPlayer();
    reproductor1->setMedia(QUrl("qrc:/sonidos/Ensoniq-SQ-1-Rock-Snare.wav"));
    reproductor2->setMedia(QUrl("qrc:/Closed-Hi-Hat-1.wav"));
    reproductor1->play();
    reproductor2->play();
}

void MainWindow::on_BotonCrash_clicked()
{
    QMediaPlayer *reproductor = new QMediaPlayer();
    reproductor->setMedia(QUrl("qrc:/sonidos/Crash-Cymbal-1.wav"));
    reproductor->play();
}
