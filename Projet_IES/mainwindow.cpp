#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(refresh()),this, SLOT(refreshBdd()));

    bdd = QSqlDatabase::addDatabase("QSQLITE");
    bdd.setDatabaseName("C:/Users/dylan/Documents/Lycée/bts 2nd année/qt/repo/Projet_IES/bdd.db");
    bdd.open();

    this->model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM renseignement");
    ui->tableView->setModel(model);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
       QSqlQuery query;
    QString nom, prenom,date,RFID,licence,imageTir;

        nom = ui->lineEdit->text();
        prenom = ui->lineEdit_2->text();
        licence = ui->lineEdit_3->text();
        RFID = ui->lineEdit_4->text();
        imageTir = ui->lineEdit_5->text();
        date = ui->lineEdit_6->text();

     qDebug() << "tout va bien";

 //    query.prepare("INSERT INTO renseignement (Nom, Prenom) values ('azerty', 'qwerty')");
 //   query.exec();

       query.prepare("INSERT INTO renseignement (Nom, Prenom,Licence,Tag_RFID,Image_tir,Date)"
                      " VALUES (?,?,?,?,?,?)");
     qDebug() << "ça va bien";

    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(licence);
    query.addBindValue(RFID);
    query.addBindValue(imageTir);
    query.addBindValue(date);
    query.exec();

    qDebug() << "envoi OK";

    emit refresh();
}

void MainWindow::refreshBdd()
{
    model->setQuery("SELECT * FROM renseignement");
    ui->tableView->setModel(model);

    qDebug() << "test SLOT";
}

