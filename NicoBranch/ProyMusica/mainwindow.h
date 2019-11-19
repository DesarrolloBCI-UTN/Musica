#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BotonBombo_clicked();
    void on_BotonHiHat_clicked();
    void on_BotonRedoblante_clicked();
    void on_BotonCrash_clicked();

    void on_btnConnect_clicked();
    void on_btnListen_clicked();
    void on_btnSend_clicked();
    void on_btnClear_clicked();
    void socket_aboutToClose();
    void socket_bytesWritten(qint64 bytes);
    void socket_connected();
    void socket_disconnected();
    void socket_error();
    void socket_readyRead();
    void socket_stateChanged();
    void server_newConnection();

    void Barrido_General();
    void Barrido_Instrumentos();
    void Barrido_Tempo();
    void Barrido_Reproduccion();
    void Blanco_general();
//    void Blanco_instrumentos();
//    void Blanco_tempo();
    void seleccion();
    void Agregar_Instrumento(const char*);
    void Get_Tempo();
    void Agregar_Tempo(const char *);
    void Reproducir();
//    void CargarPlaylist();
    void on_BotonPlay_clicked();

private:
    Ui::MainWindow *ui;
    bool connected;
    QTcpServer server;
    QTcpSocket *socket;
    QTimer *b_general;
    QTimer *b_instrumentos;
    QTimer *b_tempo;
    QTimer *b_reproduccion;
//    QTimer *test_seleccion; //es solo para probar el cambio de barrido
    int tempo;
    char posicion;
    bool play;
    QVector<QString> lista_play;
    QString rcv;
    int i_lista;

//    vectores de carga de sonidos a utilizarse con QUrl
    QVector<QString> vectorbombo;
    QVector<QString> vectorcrash;
    QVector<QString> vectorredo;
    QVector<QString> vectorHH;

//  Crear reproductores para cada uno
    QMediaPlayer *reproductorbombo = new QMediaPlayer;
    QMediaPlayer *reproductorHH = new QMediaPlayer;
    QMediaPlayer *reproductorredo = new QMediaPlayer;
    QMediaPlayer *reproductorcrash = new QMediaPlayer;

private:
    void log(QString msg);
    void socket_events();
    void update(bool connected);

};

#endif // MAINWINDOW_H
