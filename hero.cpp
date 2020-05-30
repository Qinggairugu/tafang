#include "hero.h"
#include<QPoint>
#include<QPixmap>
#include <QPainter>
hero::hero(QPoint pos, QString pix,double weili):QObject(0),pixmap(pix){
    _pos=pos;
    _weili=weili;
}
void hero::draw(QPainter *painter){
    painter->drawPixmap(_pos,pixmap);
}
