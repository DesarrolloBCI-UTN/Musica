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
#include <QThread>
#include "variables.h"

//----------------------Defines de iconos y background de los botones---------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------
#define BOMBO_BLANCO        "background-color:white;image: url(:/iconos/kick-drum.png);border: 2px solid #8f8f91;"
#define BOMBO_AZUL          "background-color:rgb(114, 159, 207);image: url(:/iconos/kick-drum.png);border: 2px solid #8f8f91;"
#define HITHAT_BLANCO       "background-color: white;image: url(:/iconos/hihat.png);border: 2px solid #8f8f91;"
#define HITHAT_AMARILLO     "background-color: rgb(255, 245, 46);image: url(:/iconos/hihat.png);border: 2px solid #8f8f91;"
#define REDOBLANTE_BLANCO   "background-color:white;image: url(:/iconos/snare-drum.png);border: 2px solid #8f8f91;"
#define REDOBLANTE_VIOLETA  "background-color: rgb(173, 127, 168);image: url(:/iconos/snare-drum.png);border: 2px solid #8f8f91;"
#define CRASH_BLANCO        "background-color:white;image: url(:/iconos/crash2.png);border: 2px solid #8f8f91;"
#define CRASH_ROJO          "background-color:rgb(239, 41, 41);image: url(:/iconos/crash2.png);border: 2px solid #8f8f91;"
#define PLAY_BLANCO         "background-color:white;image: url(:/iconos/play.png);border: 2px solid #8f8f91;"
#define PLAY_VERDE          "background-color: rgb(138, 226, 52);image: url(:/iconos/play.png);border: 2px solid #8f8f91;"
#define BLANCA_BLANCO       "background-color:white;image: url(:/iconos/blanca.png);border: 2px solid #8f8f91;"
#define BLANCA_AZUL         "background-color:rgb(114, 159, 207);image: url(:/iconos/blanca.png);border: 2px solid #8f8f91;"
#define NEGRA_BLANCO        "background-color:white;image: url(:/iconos/negra.png);border: 2px solid #8f8f91;"
#define NEGRA_AMARILLO      "background-color:rgb(255, 245, 46);image: url(:/iconos/negra.png);border: 2px solid #8f8f91;"
#define CORCHEA_BLANCO      "background-color:white;image: url(:/iconos/corchea.png);border: 2px solid #8f8f91;"
#define CORCHEA_VIOLETA     "background-color: rgb(173, 127, 168);image: url(:/iconos/corchea.png);border: 2px solid #8f8f91;"
#define SEMIC_BLANCO        "background-color:white;image: url(:/iconos/semicorchea.png);border: 2px solid #8f8f91;"
#define SEMIC_ROJO          "background-color:rgb(239, 41, 41);image: url(:/iconos/semicorchea.png);border: 2px solid #8f8f91;"
//-----------------------------------------------------------------------------------------------------------------------------------
//--------------------------------Defines de sonidos---------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------
#define CRASH_SONIDO        "qrc:/sonidos/Crash-Cymbal-1.wav"
#define HITHAT_SONIDO       "qrc:/sonidos/Closed-Hi-Hat-1.wav"
#define BOMBO_SONIDO        "qrc:/sonidos/kick_7.wav"
#define REDOBLANTE_SONIDO   "qrc:/sonidos/Ensoniq-SQ-1-Rock-Snare.wav"
//-----------------------------------------------------------------------------------------------------------------------------------

#define TIEMPO_BARRIDO      2000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connected = false;
    socket = nullptr;
    connect(&server, SIGNAL(newConnection()), this, SLOT(server_newConnection()));
    ui->btnConnect->setFocus();
    b_general = new QTimer();
    b_instrumentos = new QTimer();
    b_tempo = new QTimer();
    b_reproduccion = new QTimer();
    posicion = 0;
    play = false;
//    lista_play = new QString();
    i_lista = 0;
//-----------------------------------------------------------------------------------
//    test_seleccion = new QTimer();
//    connect(test_seleccion,SIGNAL(timeout()),this,SLOT(seleccion()));
//    test_seleccion->start(100);
//-----------------------------------------------------------------------------------

    connect(b_instrumentos,SIGNAL(timeout()),this,SLOT(Barrido_Instrumentos()));
    connect(b_general,SIGNAL(timeout()),this,SLOT(Barrido_General()));
    connect(b_tempo,SIGNAL(timeout()),this,SLOT(Barrido_Tempo()));
    connect(b_reproduccion,SIGNAL(timeout()),this,SLOT(Barrido_Reproduccion()));

    b_instrumentos->start((ui->CB_Tiempo_barrido->currentIndex() + 1)*1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BotonBombo_clicked()
{
    QMediaPlayer *reproductor = new QMediaPlayer();
    reproductor->setMedia(QUrl(BOMBO_SONIDO));
    reproductor->play();
//    if(BotonBlanca==SI){
//        vectorbombo[0].setMedia(QUrl(BOMBO_SONIDO));
//        BotonBlanca=NO;
//    }
//    if(BotonNegra==SI){
//        vectorbombo[0].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[4].setMedia(QUrl(BOMBO_SONIDO));
//        BotonNegra=NO;
//    }
//    if(BotonCorchea==SI){
//        vectorbombo[0].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[2].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[4].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[6].setMedia(QUrl(BOMBO_SONIDO));
//        BotonCorchea=NO;
//    }
//    if(BotonSemiC==SI){
//        vectorbombo[0].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[1].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[2].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[3].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[4].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[5].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[6].setMedia(QUrl(BOMBO_SONIDO));
//        vectorbombo[7].setMedia(QUrl(BOMBO_SONIDO));
//        BotonSemiC=NO;
//    }
//    QMediaPlayer *reproductor1 = new QMediaPlayer();
//    QMediaPlayer *reproductor2 = new QMediaPlayer();
//    reproductor1->setMedia(QUrl(BOMBO_SONIDO));
//    reproductor2->setMedia(QUrl(HITHAT_SONIDO));
//    reproductor1->play();
//    reproductor2->play();
}

void MainWindow::on_BotonHiHat_clicked()
{
    QMediaPlayer *reproductor = new QMediaPlayer();
    reproductor->setMedia(QUrl(HITHAT_SONIDO));
    reproductor->play();
//    if(BotonBlanca==SI){
//        vectorHH[0].setMedia(QUrl(HITHAT_SONIDO));
//        BotonBlanca=NO;
//    }
//    if(BotonNegra==SI){
//        vectorHH[0].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[4].setMedia(QUrl(HITHAT_SONIDO));
//        BotonNegra=NO;
//    }
//    if(BotonCorchea==SI){
//        vectorHH[0].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[2].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[4].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[6].setMedia(QUrl(HITHAT_SONIDO));
//        BotonCorchea=NO;
//    }
//    if(BotonSemiC==SI){
//        vectorHH[0].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[1].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[2].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[3].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[4].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[5].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[6].setMedia(QUrl(HITHAT_SONIDO));
//        vectorHH[7].setMedia(QUrl(HITHAT_SONIDO));
//        BotonSemiC=NO;
//    }
}

void MainWindow::on_BotonRedoblante_clicked()
{
    QMediaPlayer *reproductor = new QMediaPlayer();
    reproductor->setMedia(QUrl(REDOBLANTE_SONIDO));
    reproductor->play();
//    if(BotonBlanca==SI){
//        vectorredo[0].setMedia(QUrl(REDOBLANTE_SONIDO));
//        BotonBlanca=NO;
//    }
//    if(BotonNegra==SI){
//        vectorredo[0].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[4].setMedia(QUrl(REDOBLANTE_SONIDO));
//        BotonNegra=NO;
//    }
//    if(BotonCorchea==SI){
//        vectorredo[0].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[2].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[4].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[6].setMedia(QUrl(REDOBLANTE_SONIDO));
//        BotonCorchea=NO;
//    }
//    if(BotonSemiC==SI){
//        vectorredo[0].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[1].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[2].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[3].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[4].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[5].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[6].setMedia(QUrl(REDOBLANTE_SONIDO));
//        vectorredo[7].setMedia(QUrl(REDOBLANTE_SONIDO));
//        BotonSemiC=NO;
//    }
}

void MainWindow::on_BotonCrash_clicked()
{
    QMediaPlayer *reproductor = new QMediaPlayer();
    reproductor->setMedia(QUrl(CRASH_SONIDO));
    reproductor->play();
//    if(BotonBlanca==SI){
//        vectorcrash[0].setMedia(QUrl(CRASH_SONIDO));
//        BotonBlanca=NO;
//    }
//    if(BotonNegra==SI){
//        vectorcrash[0].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[4].setMedia(QUrl(CRASH_SONIDO));
//        BotonNegra=NO;
//    }
//    if(BotonCorchea==SI){
//        vectorcrash[0].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[2].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[4].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[6].setMedia(QUrl(CRASH_SONIDO));
//        BotonCorchea=NO;
//    }
//    if(BotonSemiC==SI){
//        vectorcrash[0].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[1].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[2].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[3].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[4].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[5].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[6].setMedia(QUrl(CRASH_SONIDO));
//        vectorcrash[7].setMedia(QUrl(CRASH_SONIDO));
//        BotonSemiC=NO;
//    }
}


void MainWindow::Barrido_General()
{
    posicion %= 5;
    Blanco_general();   //pongo el fondo en blanco
    switch (posicion) {
    case 0:
        ui->BotonBombo->setStyleSheet(BOMBO_AZUL);
        break;
    case 1:
        ui->BotonHiHat->setStyleSheet(HITHAT_AMARILLO);
        break;
    case 2:
        ui->BotonCrash->setStyleSheet(CRASH_ROJO);
        break;
    case 3:
        ui->BotonRedoblante->setStyleSheet(REDOBLANTE_VIOLETA);
        break;
    case 4:
        ui->BotonPlay->setStyleSheet(PLAY_VERDE);
        break;
    }
    posicion++;
}

void MainWindow::Barrido_Instrumentos()
{
    posicion %= 4;
    Blanco_general();  //pongo el fondo en blanco
    switch (posicion) {
    case 0:
        ui->BotonBombo->setStyleSheet(BOMBO_AZUL);
        break;
    case 1:
        ui->BotonHiHat->setStyleSheet(HITHAT_AMARILLO);
        break;
    case 2:
        ui->BotonCrash->setStyleSheet(CRASH_ROJO);
        break;
    case 3:
        ui->BotonRedoblante->setStyleSheet(REDOBLANTE_VIOLETA);
        break;
    }
    posicion++;
}

void MainWindow::Barrido_Tempo()
{
    if(posicion > 8)
        posicion = 5;
    Blanco_general(); //pongo el fondo en blanco
    switch (posicion) {
    case 5:
        ui->BotonBlanca->setStyleSheet(BLANCA_AZUL);
        break;
    case 6:
        ui->BotonNegra->setStyleSheet(NEGRA_AMARILLO);
        break;
    case 7:
        ui->BotonCorchea->setStyleSheet(CORCHEA_VIOLETA);
        break;
    case 8:
        ui->BotonSemiC->setStyleSheet(SEMIC_ROJO);
        break;
    }
    posicion++;
}

void MainWindow::Barrido_Reproduccion(){
    for(int i=0;i<7;i++){
        vectorbombo[i].play();
        vectorcrash[i].play();
        vectorredo[i].play();
        vectorHH[i].play();
        i%=7;
    }
}

void MainWindow::Blanco_general()
{
    ui->BotonHiHat->setStyleSheet(HITHAT_BLANCO);
    ui->BotonBombo->setStyleSheet(BOMBO_BLANCO);
    ui->BotonCrash->setStyleSheet(CRASH_BLANCO);
    ui->BotonRedoblante->setStyleSheet(REDOBLANTE_BLANCO);
    ui->BotonPlay->setStyleSheet(PLAY_BLANCO);
    ui->BotonBlanca->setStyleSheet(BLANCA_BLANCO);
    ui->BotonNegra->setStyleSheet(NEGRA_BLANCO);
    ui->BotonCorchea->setStyleSheet(CORCHEA_BLANCO);
    ui->BotonSemiC->setStyleSheet(SEMIC_BLANCO);
}

//void MainWindow::Blanco_instrumentos()
//{
//    ui->BotonHiHat->setStyleSheet(HITHAT_BLANCO);
//    ui->BotonBombo->setStyleSheet(BOMBO_BLANCO);
//    ui->BotonCrash->setStyleSheet(CRASH_BLANCO);
//    ui->BotonRedoblante->setStyleSheet(REDOBLANTE_BLANCO);
//}

//void MainWindow::Blanco_tempo()
//{
//    ui->BotonBlanca->setStyleSheet(BLANCA_BLANCO);
//    ui->BotonNegra->setStyleSheet(NEGRA_BLANCO);
//    ui->BotonCorchea->setStyleSheet(CORCHEA_BLANCO);
//    ui->BotonSemiC->setStyleSheet(SEMIC_BLANCO);
//}

void MainWindow::seleccion()
{
    QString *sel = new QString();
    QString Potencia = ui->LE_Potencia_min->text();

    //rcv = socket->readAll();

    if(strcmp(rcv.toStdString().c_str(), Potencia.toStdString().c_str()) >= 0)
    {
        b_instrumentos->stop();
        b_general->stop();
        b_tempo->stop();
        Blanco_general();

        posicion--;

        switch (posicion) {
        case 0:
            if(!play)
                Agregar_Instrumento(BOMBO_SONIDO);
            else
                on_BotonBombo_clicked();
            sel->append("instrumentos");
            break;
        case 1:
            if(!play)
                Agregar_Instrumento(HITHAT_SONIDO);
            else
                on_BotonHiHat_clicked();
            sel->append("instrumentos");
            break;
        case 2:
            if(!play)
                Agregar_Instrumento(CRASH_SONIDO);
            else
                on_BotonCrash_clicked();
            sel->append("instrumentos");
            break;
        case 3:
            if(!play)
                Agregar_Instrumento(REDOBLANTE_SONIDO);
            else
                on_BotonRedoblante_clicked();
            sel->append("instrumentos");
            break;
        case 4 :
            ui->BotonPlay->setStyleSheet(PLAY_VERDE);
            Reproducir();
            sel->append("play");
            play = true;
            break;
        case 5:
            Agregar_Tempo("Blanca");
            sel->append("tempo");
            break;
        case 6:
            Agregar_Tempo("Negra");
            sel->append("tempo");
            break;
        case 7:
            Agregar_Tempo("Corchea");
            sel->append("tempo");
            break;
        case 8:
            Agregar_Tempo("Semi_Corchea");
            sel->append("tempo");
            break;
        }
        posicion = 0;
        if((strcmp(sel->toStdString().c_str(),"instrumentos") == 0) && (play == false))
        {
            b_tempo->start((ui->CB_Tiempo_barrido->currentIndex() + 1)*1000);
            posicion = 5;
        }
        if((strcmp(sel->toStdString().c_str(),"instrumentos") == 0) && (play == true))
            b_instrumentos->start((ui->CB_Tiempo_barrido->currentIndex() + 1)*1000);
        if(strcmp(sel->toStdString().c_str(),"tempo") == 0)
            b_general->start((ui->CB_Tiempo_barrido->currentIndex() + 1)*1000);
        if(strcmp(sel->toStdString().c_str(),"play") == 0)
            b_instrumentos->start((ui->CB_Tiempo_barrido->currentIndex() + 1)*1000);
    }
//    delete []sel;
}

void MainWindow::Agregar_Instrumento(const char* sonido)
{

    lista_play.append(sonido);
//    if(!strcmp(sonido,BOMBO_SONIDO))
//        ui->Mostrar_Lista->appendPlainText("Bombo ");
//    if(!strcmp(sonido,HITHAT_SONIDO))
//        ui->Mostrar_Lista->appendPlainText("HitHat ");
//    if(!strcmp(sonido,REDOBLANTE_SONIDO))
//        ui->Mostrar_Lista->appendPlainText("Redoblante ");
//    if(!strcmp(sonido,CRASH_SONIDO))
//        ui->Mostrar_Lista->appendPlainText("Crash ");
    i_lista++;
}

void MainWindow::Get_Tempo(){
    int a = ui->BPSsb->value();
    tempo=a;
}

void MainWindow::Agregar_Tempo(const char *tempo)
{
    QString t(tempo);
    if(t == "Blanca") {
        if(lista_play.data()[--i_lista] == BOMBO_SONIDO)
            vectorbombo[0].setMedia(QUrl(BOMBO_SONIDO));
        if(lista_play.data()[--i_lista] == HITHAT_SONIDO)
            vectorHH[0].setMedia(QUrl(HITHAT_SONIDO));
        if(lista_play.data()[--i_lista] == REDOBLANTE_SONIDO)
            vectorredo[0].setMedia(QUrl(REDOBLANTE_SONIDO));
        if(lista_play.data()[--i_lista] == CRASH_SONIDO)
            vectorcrash[0].setMedia(QUrl(CRASH_SONIDO));
    }
    else if (t == "Negra") {
        if(lista_play.data()[--i_lista] == BOMBO_SONIDO){
            vectorbombo[0].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[4].setMedia(QUrl(BOMBO_SONIDO));
        }
        if(lista_play.data()[--i_lista] == HITHAT_SONIDO){
            vectorHH[0].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[4].setMedia(QUrl(HITHAT_SONIDO));
        }
        if(lista_play.data()[--i_lista] == REDOBLANTE_SONIDO){
            vectorredo[0].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[4].setMedia(QUrl(REDOBLANTE_SONIDO));
        }
        if(lista_play.data()[--i_lista] == CRASH_SONIDO){
            vectorcrash[0].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[4].setMedia(QUrl(CRASH_SONIDO));
        }
    }
    else if (t == "Corchea") {
        if(lista_play.data()[--i_lista] == BOMBO_SONIDO){
            vectorbombo[0].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[2].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[4].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[6].setMedia(QUrl(BOMBO_SONIDO));
        }
        if(lista_play.data()[--i_lista] == HITHAT_SONIDO){
            vectorHH[0].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[2].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[4].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[6].setMedia(QUrl(HITHAT_SONIDO));
        }
        if(lista_play.data()[--i_lista] == REDOBLANTE_SONIDO){
            vectorredo[0].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[2].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[4].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[6].setMedia(QUrl(REDOBLANTE_SONIDO));
        }
        if(lista_play.data()[--i_lista] == CRASH_SONIDO){
            vectorcrash[0].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[2].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[4].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[6].setMedia(QUrl(CRASH_SONIDO));
        }
    }
    else if (t == "Semi_Corchea") {
        if(lista_play.data()[--i_lista] == BOMBO_SONIDO){
            vectorbombo[0].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[1].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[2].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[3].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[4].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[5].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[6].setMedia(QUrl(BOMBO_SONIDO));
            vectorbombo[7].setMedia(QUrl(BOMBO_SONIDO));
        }
        if(lista_play.data()[--i_lista] == HITHAT_SONIDO){
            vectorHH[0].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[1].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[2].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[3].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[4].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[5].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[6].setMedia(QUrl(HITHAT_SONIDO));
            vectorHH[7].setMedia(QUrl(HITHAT_SONIDO));
        }
        if(lista_play.data()[--i_lista] == REDOBLANTE_SONIDO){
            vectorredo[0].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[1].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[2].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[3].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[4].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[5].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[6].setMedia(QUrl(REDOBLANTE_SONIDO));
            vectorredo[7].setMedia(QUrl(REDOBLANTE_SONIDO));
        }
        if(lista_play.data()[--i_lista] == CRASH_SONIDO){
            vectorcrash[0].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[1].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[2].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[3].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[4].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[5].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[6].setMedia(QUrl(CRASH_SONIDO));
            vectorcrash[7].setMedia(QUrl(CRASH_SONIDO));
        }
    }
}

void MainWindow::Reproducir()
{
    //idea:
    Get_Tempo();
    int velocidad= tempo/60;    //  A 60bps el timer va a operar a 1000 ms
    b_reproduccion->start(velocidad*1000);     //debería hacer el barrido de cada vez que aumenta el timer

//    QMediaPlayer *reproductor = new QMediaPlayer();
//    for(int i = 0; i < i_lista ; i++)
//    {
//        reproductor->setMedia(QUrl(lista_play[i]));
//        reproductor->play();
//        QThread::msleep(2000);
//    }
//    delete reproductor;
//    ui->Mostrar_Lista->appendPlainText("mostre todo");
}
