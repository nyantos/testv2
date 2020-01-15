#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QStatusBar>
#include <QUrl>
#include <QObject>
#include <QAction>
#include <QModbusTcpClient>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modbusDevice = new QModbusTcpClient(this);
    if (ui->portEdit->text().isEmpty())
       ui->portEdit->setText(QLatin1Literal("192.168.1.110:502"));


}

MainWindow::~MainWindow()
{
    if (modbusDevice)
        modbusDevice->disconnectDevice();
    delete modbusDevice;

    delete ui;
}
void MainWindow::initActions()
{

}

void MainWindow::on_connectButton_clicked()
{
    if (!modbusDevice)
        return;

    statusBar()->clearMessage();
    if (modbusDevice->state() != QModbusDevice::ConnectedState) {
    const QUrl url = QUrl::fromUserInput(ui->portEdit->text());
    modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, url.port());
    modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, url.host());

    if (!modbusDevice->connectDevice()) {
        statusBar()->showMessage(tr("Connect failed: ") + modbusDevice->errorString(), 5000);
    }
    else {
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        }
}
    else {
            modbusDevice->disconnectDevice();
            ui->actionConnect->setEnabled(true);
            ui->actionDisconnect->setEnabled(false);
        }
}
