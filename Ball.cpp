#include "Ball.h"
#include <QTimer>
#include <QBrush>
#include "Game.h"
#include "paddle.h"
#include "Block.h"
#include <QRect>
#include <QGraphicsRectItem>

extern Game* game;
// Ghada Ismail
Ball::Ball(QGraphicsItem *parent): QGraphicsRectItem(parent), QObject(){
    // draw rect
    setRect(0,0,20,15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    // move up right initially
    x_velocity = 0;
    y_velocity = -7;

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(15);
}
// Menna elSafty
double Ball::getCenterX() const {
    return x() + rect().width() / 2;
}

// Menna elSafty
void Ball::move() {
    reverseVelocity();
    handlePaddleCollision();
    handleBlockCollision();
    move(x_velocity, y_velocity);
}

//Ghada Ismail
void Ball::reverseVelocity(){
    // check if out the ball is out of bounds so it reverses velocity
    double screenwidth = game->width();
    double screenheight = game->height();
    
    if (mapToScene(rect().topLeft()).y() <= 0){
        y_velocity = -1 * y_velocity;
    }

    if (mapToScene(rect().topRight()).x() >= screenwidth){
        x_velocity = -1 * x_velocity;
    }

    // left edge
    if (mapToScene(rect().topLeft()).x() <= 0){
        x_velocity = -1 * x_velocity;
    }

  
    // no need for the bottom check as the ball is only going to move up or right or left not down
}

// Menna elSafty
void Ball::handlePaddleCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
        if (paddle){
            // collides with paddle

            // reverse the y velocity
            y_velocity = -1 * y_velocity;

            // add to x velocity depending on where it hits the paddle
            double ballX = getCenterX();
            double paddleX = paddle->getCenterX();

            double dvx = ballX - paddleX;
            x-velocity = (x_velocity + dvx)/15;

            return;
        }
    }
}

//Ghada Ismail
void Ball::handleBlockCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Block* block = dynamic_cast<Block*>(cItems[i]);
        // collides with block
        if (block){
            double yPad = 15;
            double xPad = 15;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = block->pos().x();
            double blocky = block->pos().y();

            if ((bally > blocky + yPad && y_velocity < 0) || (blocky > bally + yPad && y_velocity > 0)) {
                            y_velocity = -y_velocity;
                        }

            if ((ballx > blockx + xPad && x_velocity < 0) || (blockx > ballx + xPad && x_velocity > 0)) {
                            x_velocity = -x_velocity;
                        }

            // delete block(s)
            game->scene->removeItem(block);
            delete block;
        }
    }
}


