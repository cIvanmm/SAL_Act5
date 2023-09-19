#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"neurona.h"
#include"listaneuronas.h"
#include <QMainWindow>
#include<QFileDialog>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QVector>
#include<QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ListaNeuronas lista;

private slots:
    void on_actionGuardar_triggered();

    void on_actionCargar_triggered();

    int delimitador(int, QString);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
