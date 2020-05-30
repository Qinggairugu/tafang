#include "menu.h"
#include "button.h"
#include "mainwindow.h"
menu::menu(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(960,640);
    button *_back= new button("://button2.png");

    _back->setParent(this);
    _back->move(430,500);
    connect(_back,&button::clicked,this,[=](){
        _back->down();
        _back->up();
        emit backmw();

    });
    button *_first = new button("://button3.png");
    _first->setParent(this);
    _first->move(200,200);
    connect(_first,&button::clicked,this,[=](){
        _first->down();
        _first->up();
        emit guan1st();
    });

}
void menu::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("://menu_.png"));


}
