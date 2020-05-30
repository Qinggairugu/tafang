#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>
class button : public QPushButton
{
    Q_OBJECT
public:
    explicit button(QString a);

    void up();
    void down();

signals:

public slots:
};

#endif // BUTTON_H
