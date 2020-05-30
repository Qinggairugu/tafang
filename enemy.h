#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include "object.h"
class enemy : public object
{
public:
    enemy(QPoint startpos,QPoint targetpos,QString pix);
    double gethp(){return hp;}
    double sethp(double x){hp=x;}
private:
    double hp;
};

#endif // ENEMY_H
