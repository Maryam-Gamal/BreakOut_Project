#include "paddle.h"
#include<QGraphicsScene>
#include<QKeyEvent>


Paddle::Paddle(QGraphicsPixmapItem *parent)
{
    setPixmap(QPixmap(":/Images/paddle.png"));
}


void Paddle::keyPressEvent(QKeyEvent*event)
{
    if(event->key()==Qt::Key_Left)
    {
        if(pos().x()>0)
            setPos(x()-30,y());
    }
    else if(event->key()==Qt::Key_Right)
    {
        if(pos().x()+20<800)
            setPos(x()+30,y());
    }
}
