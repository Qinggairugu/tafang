#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>

#include<iostream>
#include "button.h"
#include"menu.h"
#include"first.h"
#include<QTimer>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button *a=new button("://button1.png");
    a->setParent(this);
    a->move(430,500);
    menu *_menu=new menu;
    first *_guan1st=new first;
    connect(a,&button::clicked,this,[=](){
        a->down();
        a->up();
        QTimer::singleShot(500,this,[=](){
            this->close();
            _menu->show();
        });
    });
    connect(_menu,&menu::backmw,this,[=](){
        QTimer::singleShot(500,this,[=](){
            _menu->hide();
            this->show();
        });
    });
    connect(_menu,&menu::guan1st,_guan1st,[=](){
        QTimer::singleShot(500,this,[=](){
            _menu->hide();
            _guan1st->show();
        });
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("://begin_.png"));

}
