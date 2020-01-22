#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "m320t.h"
#include <QMainWindow>
#include <QObject>
#include <QModbusClient>
#include <QModbusDataUnit>



QT_BEGIN_NAMESPACE



namespace Ui { class MainWindow; }

class m320t;



QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_connectButton_clicked();


    void on_AllOn_clicked();


    void on_AllOff_clicked();

private:
    Ui::MainWindow *ui;
    QModbusTcpClient *m320t;
    void connectM320T(QString ipadr, unsigned short port);
    void writeAllOutputON();
    void writeAllOutputOFF();



};
#endif // MAINWINDOW_H
