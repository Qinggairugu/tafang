#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include<QPropertyAnimation>
#include<QPoint>
#include<QPixmap>
#include<QPainter>
class object : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint currentpos READ getcurrentpos WRITE setcurrentpos)
public:
    object(QPoint startpos,QPoint targetpos,QString pix);
    void draw(QPainter *painter);
    void move();
    void movestop();
    QPoint getcurrentpos();
    QPoint getstartpos(){return this->startpos;}
    void setcurrentpos(QPoint pos);
protected:
    QPoint startpos;
    QPoint targetpos;
    QPoint currentpos;
    QPixmap pixmap;
    QPropertyAnimation * animation;
signals:

public slots:
};

#endif // OBJECT_H
