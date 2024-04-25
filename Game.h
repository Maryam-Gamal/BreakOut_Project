#ifndef GAME_H
#define GAME_H
#include "Ball.h"
#include "Health.h"
#include "Paddle.h"
#include "Score.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QSet>


class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    QGraphicsScene * scene;
    Ball* ball = new Ball();
    Paddle *paddle;
    Score * score;
    health * Health;
    void startGame();
    int level;
    bool gameStarted;
    void blocksgrid();

};

#endif // GAME_H

