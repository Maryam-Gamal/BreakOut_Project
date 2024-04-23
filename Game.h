#ifndef GAME_H
#define GAME_H

#include "Paddle.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    Paddle *paddleitem;
};

#endif // GAME_H
