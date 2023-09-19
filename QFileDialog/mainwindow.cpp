#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui ->pushButton_5 ->setFixedSize(0, 0);
    ui ->plainTextEdit ->setFixedSize(0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionGuardar_triggered()
{
    QString filename =QFileDialog::getOpenFileName(this, tr("Open File"),"C:/Users/Ivan/Downloads", tr("Text Files(*.txt)"));
    QFile archivo(filename);
    if(!archivo.open(QFile::WriteOnly |QFile::Text)){
        QMessageBox::warning(this, "title", "No se pudo abrir el archivo...");
    }
    QTextStream out(&archivo);
    QString datos;
    if(lista.cant_neuronas() ==0){
        datos =QString("");
    }
    else{
        for(size_t i =0; i <lista.cant_neuronas(); i ++){
            datos =QString("%1;%2;%3;%4;%5;%6;%7\n").arg(lista.getnid(i))
                            .arg(lista.getnvoltaje(i)).arg(lista.getnx(i))
                            .arg(lista.getny(i)).arg(lista.getnred(i))
                            .arg(lista.getngreen(i)).arg(lista.getnblue(i));
            out <<datos;
        }
    }
    archivo.close();
}

void MainWindow::on_actionCargar_triggered()
{
    QString filename =QFileDialog::getOpenFileName(this, tr("Open File"),"C:/Users/Ivan/Downloads", tr("Text Files(*.txt)"));
    QFile archivo(filename);
    if(!archivo.open(QFile::ReadOnly |QFile::Text)){
        QMessageBox::warning(this, "title", "No se pudo abrir el archivo...");
    }
    QTextStream in(&archivo);
    QString datos;
    int pyc1, pyc2;
    while(!in.atEnd()){
        datos =in.readLine();
        pyc1 =0;
        pyc2 =delimitador(pyc1 +1, datos);
        ui ->form_id ->setText(datos.sliced(pyc1, (pyc2 -pyc1)));
        pyc2 ++;
        pyc1 =delimitador(pyc2 +1, datos);
        ui ->form_voltaje ->setText(datos.sliced(pyc2, (pyc1 -pyc2)));
        pyc1 ++;
        pyc2 =delimitador(pyc1 +1, datos);
        ui ->form_x ->setText(datos.sliced(pyc1, (pyc2 -pyc1)));
        pyc2 ++;
        pyc1 =delimitador(pyc2 +1, datos);
        ui ->form_y ->setText(datos.sliced(pyc2, (pyc1 -pyc2)));
        pyc1 ++;
        pyc2 =delimitador(pyc1 +1, datos);
        ui ->form_red ->setText(datos.sliced(pyc1, (pyc2 -pyc1)));
        pyc2 ++;
        pyc1 =delimitador(pyc2 +1, datos);
        ui ->form_green ->setText(datos.sliced(pyc2, (pyc1 -pyc2)));
        pyc1 ++;
        pyc2 =delimitador(pyc1 +1, datos);
        ui ->form_blue ->setText(datos.sliced(pyc1, (pyc2 -pyc1)));
        on_pushButton_2_clicked();
    }
    archivo.close();
}

int MainWindow::delimitador(int pyc, QString datos){
    for(; pyc <datos.length(); pyc ++){
        if(datos[pyc] ==';'){
            return pyc;
        }
    }
    return pyc;
}

void MainWindow::on_pushButton_clicked()
{
    QString id, voltaje, x, y, red, green, blue;
    id =ui ->form_id ->text();
    voltaje =ui ->form_voltaje ->text();
    x =ui ->form_x ->text();
    y =ui ->form_y ->text();
    red =ui ->form_red ->text();
    green =ui ->form_green ->text();
    blue =ui ->form_blue ->text();
    Neurona neurona(id.toInt(), voltaje.toFloat(), x.toInt(), y.toInt(), red.toInt(), green.toInt(), blue.toInt());
    lista.agregar_inicio(neurona);
    ui ->form_id ->setText("");
    ui ->form_voltaje ->setText("");
    ui ->form_x ->setText("");
    ui ->form_y ->setText("");
    ui ->form_red ->setText("");
    ui ->form_green ->setText("");
    ui ->form_blue ->setText("");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString id, voltaje, x, y, red, green, blue;
    id =ui ->form_id ->text();
    voltaje =ui ->form_voltaje ->text();
    x =ui ->form_x ->text();
    y =ui ->form_y ->text();
    red =ui ->form_red ->text();
    green =ui ->form_green ->text();
    blue =ui ->form_blue ->text();
    Neurona neurona(id.toInt(), voltaje.toFloat(), x.toInt(), y.toInt(), red.toInt(), green.toInt(), blue.toInt());
    lista.agregar_final(neurona);
    ui ->form_id ->setText("");
    ui ->form_voltaje ->setText("");
    ui ->form_x ->setText("");
    ui ->form_y ->setText("");
    ui ->form_red ->setText("");
    ui ->form_green ->setText("");
    ui ->form_blue ->setText("");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui ->label ->setText("");
    ui ->label_2 ->setText("");
    ui ->label_3 ->setText("");
    ui ->label_4 ->setText("");
    ui ->label_5 ->setText("");
    ui ->label_6 ->setText("");
    ui ->label_7 ->setText("");
    ui ->form_id ->setFixedSize(0, 0);
    ui ->form_voltaje ->setFixedSize(0, 0);
    ui ->form_x ->setFixedSize(0, 0);
    ui ->form_y ->setFixedSize(0, 0);
    ui ->form_red ->setFixedSize(0, 0);
    ui ->form_green ->setFixedSize(0, 0);
    ui ->form_blue ->setFixedSize(0, 0);
    ui ->pushButton ->setFixedSize(0, 0);
    ui ->pushButton_2 ->setFixedSize(0, 0);
    ui ->pushButton_3 ->setFixedSize(0, 0);
    ui ->pushButton_4 ->setFixedSize(0, 0);
    ui ->pushButton_5 ->setFixedSize(111, 31);
    ui ->plainTextEdit ->setFixedSize(251, 291);
    if(lista.cant_neuronas() ==0)
        ui ->plainTextEdit ->setPlainText("No hay ninguna neurona registrada...");
    else{
        QString cadena;
        for(size_t i =0; i <lista.cant_neuronas(); i ++){
            cadena =QString("Neurona: %1\nVoltaje: %2\nPosicion: ("
                             "%3, %4)\nRGB: (%5, %6, %7)\n\n").arg(lista.getnid(i))
                         .arg(lista.getnvoltaje(i)).arg(lista.getnx(i))
                         .arg(lista.getny(i)).arg(lista.getnred(i))
                         .arg(lista.getngreen(i)).arg(lista.getnblue(i));
            ui ->plainTextEdit ->insertPlainText(cadena);
        }
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui ->label ->setText("Id:");
    ui ->label_2 ->setText("Voltaje:");
    ui ->label_3 ->setText("Posicion X:");
    ui ->label_4 ->setText("Posicion Y:");
    ui ->label_5 ->setText("Red:");
    ui ->label_6 ->setText("Green:");
    ui ->label_7 ->setText("Blue:");
    ui ->form_id ->setFixedSize(113, 24);
    ui ->form_voltaje ->setFixedSize(113, 24);
    ui ->form_x ->setFixedSize(113, 24);
    ui ->form_y ->setFixedSize(113, 24);
    ui ->form_red ->setFixedSize(113, 24);
    ui ->form_green ->setFixedSize(113, 24);
    ui ->form_blue ->setFixedSize(113, 24);
    ui ->pushButton ->setFixedSize(111, 31);
    ui ->pushButton_2 ->setFixedSize(111, 31);
    ui ->pushButton_3 ->setFixedSize(111, 31);
    ui ->pushButton_4 ->setFixedSize(111, 31);
    ui ->pushButton_5 ->setFixedSize(0, 0);
    ui ->plainTextEdit ->setPlainText("");
    ui ->plainTextEdit ->setFixedSize(0, 0);
}
