#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QModbusClient>
#include <QModbusDataUnit>


QT_BEGIN_NAMESPACE



namespace Ui { class MainWindow; }

class QModbusClient;
class QModbusReply;



QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initActions();
    QModbusDataUnit readRequest() const;
    QModbusDataUnit writeRequest() const;


private slots:
    void on_connectButton_clicked();


private:
    Ui::MainWindow *ui;
    QModbusReply *lastRequest;
    QModbusClient *modbusDevice;
    //SettingsDialog *m_settingsDialog;
    //WriteRegisterModel *writeModel;
};
#endif // MAINWINDOW_H
