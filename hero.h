#ifndef HERO_H
#define HERO_H

#include <QObject>
#include<QPoint>
#include<QPixmap>
#include<QPainter>
#include"wugong.h"
#include<QList>
class hero : public QObject
{
    Q_OBJECT
public:
    hero(QPoint pos,QString pix,double weili);
    void draw(QPainter *painter);
    double getweili(){return _weili;}
private:
    QPoint _pos;
    QPixmap pixmap;
    double _weili;

signals:

public slots:
};

#endif // HERO_H
