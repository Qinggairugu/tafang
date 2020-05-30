#include "button.h"
#include<QPixmap>
#include<QPropertyAnimation>
button::button(QString a) : QPushButton(0)
{
    QPixmap pixmap(a);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

void button::down(){
    QPropertyAnimation *a=new QPropertyAnimation(this,"geometry");
    a->setDuration(200);
    a->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    a->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    a->start();
}
void button::up(){
    QPropertyAnimation *a=new QPropertyAnimation(this,"geometry");
    a->setDuration(200);
    a->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    a->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    a->start();
}
