#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "m320t.h"
#include <QStandardItemModel>
#include <QObject>
#include <QModbusTcpClient>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m320t = new QModbusTcpClient;

}

MainWindow::~MainWindow()
{


    delete ui;
    delete m320t;
}
void MainWindow::connectM320T(QString ipAdr, unsigned short port)
{
    m320t->setConnectionParameter(QModbusDevice::NetworkAddressParameter, ipAdr);
    m320t->setConnectionParameter(QModbusDevice::NetworkPortParameter, port);
    m320t->connectDevice();


}

void MainWindow::writeAllOutputON()
{
    QModbusDataUnit allOut(QModbusDataUnit::Coils, 0, 8);
    for (int i = 0; i <8; i++) {
        allOut.setValue(i , 1 );
    }
    m320t->sendWriteRequest(allOut, 1);

}


void MainWindow::writeAllOutputOFF()
{
    QModbusDataUnit allOut(QModbusDataUnit::Coils, 0 , 8);
    for (int i = 0; i <8; i++) {
        allOut.setValue(i , 0 );
    }
    m320t->sendWriteRequest(allOut, 1);

}

void MainWindow::on_connectButton_clicked()
{

connectM320T("192.168.1.110", 502);
}


void MainWindow::on_AllOn_clicked()
{
      writeAllOutputON();
}


void MainWindow::on_AllOff_clicked()
{
       writeAllOutputOFF();
}
