#include "wugong.h"

wugong::wugong(QPoint startpos, QPoint targetpos, QString pix, double a):object(startpos,targetpos,pix){
    weili=a;
}
void wugong::move(){
    QPropertyAnimation * animation =new QPropertyAnimation(this,"currentpos");
    animation->setDuration(1000);
    animation->setStartValue(startpos);
    animation->setEndValue(targetpos);
    animation->start();
}
