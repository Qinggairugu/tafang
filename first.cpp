#include "first.h"
#include"button.h"
#include<QPainter>
#include<QPoint>
#include<QPixmap>
#include<QTimer>
#include<QTime>
#include<math.h>
#include<QCoreApplication>
first::first(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(960,640);
    QPushButton *setHero= new QPushButton;
    setHero->setParent(this);
    setHero->setFixedSize(50,50);
    setHero->setFlat(true);
    setHero->move(30,150);
    QPoint a=setHero->pos();
    button *jingong= new button(":/button3.png");
    jingong->setParent(this);
    jingong->move(800,500);
    connect(setHero,&button::clicked,this,[=](){
        first::set_hero(a);
        first::setwugong(a);

    });
    connect(jingong,&button::clicked,this,[=](){
        jingong->down();
        jingong->up();
        jingong->setEnabled(false);
        QTimer *dixitimer =new QTimer;
        connect(dixitimer,&QTimer::timeout,this,[=](){
            first::addenemy();
            first::yungong();
        });

        dixitimer->start(2000);

    });
    QTimer *timer=new QTimer;
    connect(timer,&QTimer::timeout,this,[=](){
        first::shuaxin();


    });
    timer->start(20);

}
void first::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0, 0, QPixmap("://ditu.png"));
    foreach(hero *_hero,hero_list)
        _hero->draw(&painter);
    foreach(enemy *_enemy,enemy_list){
        if(_enemy->getcurrentpos().x()>=40&&_enemy->gethp()>40)
            _enemy->draw(&painter);
    }
    foreach(wugong *_wugong,wugong_list){
        _wugong->draw(&painter);
    }

}

void first::set_hero(QPoint pos){
    hero *a =new hero(pos,"://huangyaoshi.png",100);
    hero_list.push_back(a);
    update();
}
void first::shuaxin(){
    update();
}
void first::addenemy(){
    int d=1+rand()%4;
    int x1,x2,y1,y2;
    x1=880;
    x2=30;
    switch(d){
    case 1:
        y1=y2=30;

        break;
    case 2:
        y1=y2=150;
        break;
    case 3:
        y1=y2=280;
        break;
    case 4:
        y1=y2=410;
        break;

    }
    enemy *a =new enemy(QPoint(x1,y1),QPoint(x2,y2),"://dongfangbubai.png");
    a->sethp(100);
    enemy_list.push_back(a);
    a->move();
    update();



}
void first::setwugong(QPoint pos){
    wugong *a=new wugong (pos,QPoint(960,pos.y()),"://bullet.png",100);
    wugong_list.push_back(a);
}
void first::yungong(){
    int n=-1;
    int minx=1000;
    foreach(wugong *a,wugong_list){
        QTimer *jizhong =new QTimer;
        jizhong->start(20);
        int b=a->getcurrentpos().y();
        int c=a->getcurrentpos().x();
        for(int i=0;i<enemy_list.size();i++){
            if(b==enemy_list.at(i)->getcurrentpos().y()){
                if(enemy_list.at(i)->getcurrentpos().x()<minx){
                    minx=enemy_list.at(i)->getcurrentpos().x();
                    n=i;
                }
            }
        }
        if(n>=0){
            a->move();
            connect(jizhong,&QTimer::timeout,this,[=](){
                if(abs(a->getcurrentpos().x()-enemy_list.at(n)->getcurrentpos().x())<20){
                    wugong_list.removeAt(n);
                    jizhong->stop();

                }
            });
        }
    }
}
//        foreach(enemy *_enemy,enemy_list){
//            int c=_enemy->getcurrentpos().y();
//            int e=_enemy->getcurrentpos().x();

//            if(d<e&&b==c&&_enemy->gethp()>0){
//            a->move();
//            connect(jizhong,&QTimer::timeout,this,[=](){
//                if(abs(d-e)<20){
//                    a->setcurrentpos(a->getstartpos());
//                    wugong *p=a;
//                    wugong_list.removeOne(a);
//                    wugong_list.push_back(p);
//                    delete a;
//                    jizhong->stop();
//                    _enemy->sethp(_enemy->gethp()-a->getweili());
//                }
//                else if(a->getcurrentpos().x()>900){
//                    a->setcurrentpos(a->getstartpos());
//                    jizhong->stop();
//                }

//            });
//            }


//        }

//    }
//}


