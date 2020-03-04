#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{

    delete ui;

}

QString MainWindow::convert(QString chaine)
{
  QString resultat;
  if(chaine.length()==10){
      for(int i(0);i<10;i++){
          switch(chaine.toLocal8Bit()[i])
          {

          case '&':
              resultat[i]='1';
              break;

          case '\xE9':
              resultat[i]='2';
              break;

         case '\"':
              resultat[i]='3';
              break;

          case '\'':
               resultat[i]='4';
               break;

          case '(':
               resultat[i]='5';
               break;

          case '-':
               resultat[i]='6';
               break;

          case '\xE8':
               resultat[i]='7';
               break;

          case '_':
               resultat[i]='8';
               break;

          case '\xE7':
               resultat[i]='9';
               break;

          case '\xE0':
               resultat[i]='0';
               break;
          }
      }
  }
return resultat;


}

void MainWindow::fonctionTimer(){


}



void MainWindow::on_textEdit_textChanged()
{
    QString str = ui->textEdit->toPlainText();

    if(str.length() == 10){
     ui->label->setText(convert(str));

    qDebug()<<str;
    qDebug()<<str.length();
    }
    if(str.contains("\n")){

        str.clear();
        ui->textEdit->setPlainText("");

     }


    }



