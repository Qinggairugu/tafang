#ifndef FIRST_H
#define FIRST_H

#include <QMainWindow>
#include<QPainter>
#include"hero.h"
#include<QList>
#include"object.h"
#include"enemy.h"
#include"wugong.h"
class first : public QMainWindow
{
    Q_OBJECT
public:
    explicit first(QWidget *parent = nullptr);
    void set_hero(QPoint pos);
    void shuaxin();
    void addenemy();
    void setwugong(QPoint pos);
    void yungong();
private:
    QList<hero *> hero_list;
    QList<object *> object_list;
    QList<enemy *> enemy_list;
    QList<wugong *> wugong_list;
signals:

public slots:
protected:
    void paintEvent(QPaintEvent *);
};

#endif // FIRST_H
