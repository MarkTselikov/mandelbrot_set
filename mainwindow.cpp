#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphicsScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(graphicsScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_iterButton_clicked()
{
    int iterations = ui -> iterInput -> text().toInt();
    int hght = ui -> heightLine -> text().toInt();
    int wdth = ui -> widthLine -> text().toInt();

    for(int i = 0; i < wdth; i++) {
        for(int j = 0; j < hght; j++) {

            double x = i * 1.0 / wdth * 4.0 - 2.0;
            double y = j * 1.0 / hght * 4.0 - 2.0;
            const double X_INIT = x;
            const double Y_INIT = y;
            int n = 0;
            bool check = true;
            double scale = 0;

            while(n < iterations) {

                double xTemp =  X_INIT + (x * x - y * y);
                double yTemp = Y_INIT + (2 * x * y);
                x = xTemp;
                y = yTemp;

                if(fabs(x * x + y * y) > 4.0) {
                    check = false;
                    scale = (double)n / (double)iterations * 255;
                    //QPen pen(QColor(scale, scale, scale));
                    QPen pen(QColor(scale, scale / 4, scale / 3));
                    pen.setWidth(0);
                    //QBrush brush(QColor(scale, scale, scale));
                    QBrush brush(QColor(scale, scale / 4, scale / 3));
                    graphicsScene->addRect(i, j, 1, 1, pen, brush);
                    break;
                }

                n++;
            }

            if(check) {
                //scale = (double)n / (double)iterations * 255;
                //QPen pen(QColor(scale, scale, scale));
                /*QPen pen(QColor(0, 0, 0));
                pen.setWidth(0);
                QBrush brush(QColor(scale, scale, scale));
                //QBrush brush(QColor(scale, scale, 150));
                graphicsScene->addRect(i, j, 1, 1, pen, brush);*/
            }
        }
    } //for end
}

void MainWindow::on_pushButton_clicked()
{
    int hght = ui -> heightLine -> text().toInt();
    int wdth = ui -> widthLine -> text().toInt();

    for(int i = 0; i < wdth; i++) {
        for(int j = 0; j < hght; j++) {
            QPen pen(QColor(255, 255, 255));
            pen.setWidth(0);
            QBrush brush(QColor(255, 255, 255));
            graphicsScene->addRect(i, j, 1, 1, pen, brush);
        }
    }
}

int colorScheme(int scheme_num) {
    return 0;
}
