#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

#include <QPainter>
class menu : public QMainWindow
{
    Q_OBJECT
public:
    explicit menu(QWidget *parent = nullptr);

signals:
    void backmw();
    void guan1st();
public slots:
protected:
    void paintEvent(QPaintEvent *);
};

#endif // MENU_H
