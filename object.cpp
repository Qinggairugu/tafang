#include "object.h"

object::object(QPoint startpos, QPoint targetpos, QString pix):QObject(0),pixmap(pix){
    this->currentpos=startpos;
    this->startpos=startpos;
    this->targetpos=targetpos;
    animation =new QPropertyAnimation(this,"currentpos");
}
void object::draw(QPainter *painter){
    painter->drawPixmap(currentpos,pixmap);

}
QPoint object::getcurrentpos(){
    return this->currentpos;
}
void object::setcurrentpos(QPoint pos){
    this->currentpos=pos;
}
void object::move(){

    animation->setDuration(10000);
    animation->setStartValue(startpos);
    animation->setEndValue(targetpos);
    animation->start();
}
void object::movestop(){
    animation->stop();
}
