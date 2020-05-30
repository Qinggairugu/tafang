#ifndef WUGONG_H
#define WUGONG_H

#include <QObject>
#include "object.h"
class wugong : public object
{
public:
    wugong(QPoint startpos,QPoint targetpos,QString pix,double a);
    double getweili(){return weili;}
    void move();
private:
    double weili;
};

#endif // WUGONG_H
