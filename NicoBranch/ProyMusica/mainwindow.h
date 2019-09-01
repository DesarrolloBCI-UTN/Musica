#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QMediaPlayer>

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
    QMediaPlayer vectorbombo[7];
    QMediaPlayer vectorcrash[7];
    QMediaPlayer vectorredo[7];
    QMediaPlayer vectorHH[7];

private:
    void log(QString msg);
    void socket_events();
    void update(bool connected);

};

#endif // MAINWINDOW_H