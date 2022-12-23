#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <vector>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent*) override;
public:
    MainWindow(QWidget *parent = nullptr);
    QPainter qp;
    bool k = 0;
    std::vector <std::pair<int,int> > vec;
    ~MainWindow();

    void mousePressEvent(QMouseEvent *mo);
    int x,y;

signals:
    void Mouse_Pressed();

private slots:
    void on_brezenh_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int T;
    int A,B;
    int F = 0;
};

#endif // MAINWINDOW_H
