#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <algorithm>
#include <cmath>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    T = 0;
    A = 0;
    B = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *mo)
{
    emit Mouse_Pressed();
    if(F==0){
        QPoint p = mo->pos();
        x = p.rx();
        y = p.ry();

        T++;
        if(T==1) {
            A = x;
            B = y;
        }
    }
    update();
    if(T==1){
        ui->label_4->setText(QString::number(x)+" "+QString::number(y));
    }
    else{
        ui->label_5->setText(QString::number(x)+" "+QString::number(y));
    }
    qDebug()<<x<<" " <<y;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter qp;
    qp.begin(this);
    QPen pen(Qt::black, 6, Qt::SolidLine);
    qp.drawLine(50, 400, 750, 400);
    qp.drawLine(400, 50, 400,750);
    qp.drawLine(400, 50, 395,55);
    qp.drawLine(400, 50, 405,55);
    qp.drawLine(750, 400, 745,395);
    qp.drawLine(750, 400, 745,405);

    qp.drawLine(75, 400, 75,394);
    qp.drawLine(100, 400, 100,394);
    qp.drawLine(125, 400, 125,394);
    qp.drawLine(150, 400, 150,394);
    qp.drawLine(175, 400, 175,394);
    qp.drawLine(200, 400, 200,394);
    qp.drawLine(225, 400, 225,394);
    qp.drawLine(250, 400, 250,394);
    qp.drawLine(275, 400, 275,394);
    qp.drawLine(300, 400, 300,394);
    qp.drawLine(325, 400, 325,394);
    qp.drawLine(350, 400, 350,394);
    qp.drawLine(375, 400, 375,394);
    qp.drawLine(400, 400, 400,394);
    qp.drawLine(425, 400, 425,394);
    qp.drawLine(450, 400, 450,394);
    qp.drawLine(475, 400, 475,394);
    qp.drawLine(500, 400, 500,394);
    qp.drawLine(525, 400, 525,394);
    qp.drawLine(550, 400, 550,394);
    qp.drawLine(575, 400, 575,394);
    qp.drawLine(600, 400, 600,394);
    qp.drawLine(625, 400, 625,394);
    qp.drawLine(650, 400, 650,394);
    qp.drawLine(675, 400, 675,394);
    qp.drawLine(700, 400, 700,394);
    qp.drawLine(725, 400, 725,394);
    qp.drawLine(400, 75, 405,75);
    qp.drawLine(400, 100, 405,100);
    qp.drawLine(400, 125, 405,125);
    qp.drawLine(400, 150, 405,150);
    qp.drawLine(400, 175, 405,175);
    qp.drawLine(400, 200, 405,200);
    qp.drawLine(400, 225, 405,225);
    qp.drawLine(400, 250, 405,250);
    qp.drawLine(400, 275, 405,275);
    qp.drawLine(400, 300, 405,300);
    qp.drawLine(400, 325, 405,325);
    qp.drawLine(400, 350, 405,350);
    qp.drawLine(400, 375, 405,375);
    qp.drawLine(400, 400, 405,400);
    qp.drawLine(400, 425, 405,425);
    qp.drawLine(400, 450, 405,450);
    qp.drawLine(400, 475, 405,475);
    qp.drawLine(400, 500, 405,500);
    qp.drawLine(400, 525, 405,525);
    qp.drawLine(400, 550, 405,550);
    qp.drawLine(400, 575, 405,575);
    qp.drawLine(400, 600, 405,600);
    qp.drawLine(400, 625, 405,625);
    qp.drawLine(400, 650, 405,650);
    qp.drawLine(400, 675, 405,675);
    qp.drawLine(400, 700, 405,700);
    qp.drawLine(400, 725, 405,725);
    qp.drawLine(400, 750, 405,750);

    for(int i = 0;i<vec.size();i++){
        qp.drawPoint(vec[i].first,vec[i].second);
    }

    if(T>1){
        F=1;
    }
    if(T==1) {
        qp.drawEllipse(x,y,1,1);
    } else {
        qp.drawEllipse(x,y,1,1);
        k = 1;
    }
    QFont font = qp.font();
    font.setPixelSize(24);
    qp.setFont(font);
    qp.end();
}

void MainWindow::on_brezenh_clicked()
{
    if(k==1){
        const int deltaX = abs(A - x);
        const int deltaY = abs(B - y);
        const int signX = x < A ? 1 : -1;
        const int signY = y < B ? 1 : -1;
        int error = deltaX - deltaY;
        vec.push_back({A,B});
        while(x != A || y != B)
       {
            vec.push_back({x,y});
            int error2 = error * 2;
            if(error2 > -deltaY)
            {
                error -= deltaY;
                x += signX;
            }
            if(error2 < deltaX)
            {
                error += deltaX;
                y += signY;
            }
        }
    }
    update();
}

void MainWindow::on_pushButton_4_clicked()
{
    int i;    float  L, xstart, ystart, xend, yend;
     float dX, dY, x1[10000], y1[10000];
     xstart = roundf(x);
     ystart = roundf(y);
     xend = roundf(A);
     yend = roundf(B);
     L = max(abs(xend-xstart), abs(yend-ystart));
     dX = (A-x) / L;
     dY = (B-y) / L;
     i = 0;
     x1[i] = x;
     y1[i] = y;
     i++;
     while (i < L)
     {
      x1[i] = x1[i-1] + dX;
      y1[i] = y1[i-1] + dY;
      i++;
     }
     x1[i] = A;
     y1[i] = B;
     i = 0;
     while (i <= L)
     {
      vec.push_back({roundf(x1[i]), roundf(y1[i])});
      i++;
     }
     update();
}

void MainWindow::on_pushButton_2_clicked() {
    int radius = sqrt((A-x)*(A-x)+(B-y)*(B-y));
    int x1 = 0;
    int y1 = radius;
    int delta = 1 - 2 * radius;
    int error = 0;
    while(y1 >= 0) {
        vec.push_back({x + x1, y + y1});
        vec.push_back({x + x1, y - y1});
        vec.push_back({x - x1, y + y1});
        vec.push_back({x - x1, y - y1});
        error = 2 * (delta + y1) - 1;
        if(delta < 0 && error <= 0) {
            ++x1    ;
            delta += 2 * x1 + 1;
            continue;
        }
        error = 2 * (delta - x1) - 1;
        if(delta > 0 && error > 0) {
            --y1;
            delta += 1 - 2 * y1;
            continue;
        }
        ++x1;
        delta += 2 * (x1 - y1);
        --y1;
    }
    update();
}

void MainWindow::on_pushButton_clicked()
{
    vec.clear();
    T = 0;
    F = 0;
    ui->label_4->setText("-");
    ui->label_5->setText("-");
    update();
}
