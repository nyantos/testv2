#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString convert(QString chaine);

public slots:
    void fonctionTimer();
private slots:





    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    QString a;


};
#endif // MAINWINDOW_H
