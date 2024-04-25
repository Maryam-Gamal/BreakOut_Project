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
// Constructor for Ball class

Ball::Ball(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/Ball.png")); // Set the pixmap for the ball

    // move up right initially
    xvelocity = 0;
    yvelocity = -7;

    // Create a timer to move the ball
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(15);
}


// Menna elSafty
// Get the center x-coordinate of the ball

double Ball::getCenterX() const {
    return x() + boundingRect().width() / 2;
}

// Menna elSafty
// Move the ball and handle collisions
void Ball::move() {
    reverseVelocity();  // Reverse the velocity if the ball hits the edges
    handlePaddleCollision();  // Handle collision with the paddle
    handleBlockCollision(); // Handle collision with blocks
    moveBy(xvelocity, yvelocity); // Move the ball
}


//Ghada Ismail
// Reverse the velocity if the ball hits the edges of the screen

void Ball::reverseVelocity(){
    // check if out the ball is out of bounds so it reverses velocity
    double screenwidth = game->width();
    double screenheight = game->height();
    

    // Reverse x-velocity if the ball hits the left or right edge

    if (mapToScene(boundingRect().topLeft()).x() <= 30){
        xvelocity = -1 * xvelocity;
    }

    // Reverse y-velocity if the ball hits the top edge

    if (mapToScene(boundingRect().topRight()).x() >= screenwidth - 30){
        xvelocity = -1 * xvelocity;
    }

    // left edge
    if (mapToScene(boundingRect().topLeft()).y() <= 140){
        yvelocity = -1 * yvelocity;
    }

    // Reset the game if the ball goes out of bounds at the bottom
  if (mapToScene(boundingRect().bottomLeft()).y() >= screenheight) {
        game->Health->decrease();
        delete this;
    }
}

// Menna elSafty
// Handle collision with the paddle

void Ball::handlePaddleCollision(){

    // Get a list of colliding items
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]); // Check if the colliding item is the paddle
        if (paddle){
            // collides with paddle

            // reverse the y velocity
            yvelocity = -1 * yvelocity;

            // add to x velocity depending on where it hits the paddle
            double ballX = getCenterX();
            double paddleX = paddle->paddleCenterX();

            double dvx = ballX - paddleX;
            xvelocity = (xvelocity + dvx)/15; // Adjust x velocity

            return;  // Exit the loop after handling collision
        }
    }
}

//Ghada Ismail
// Handle collision with blocks

void Ball::handleBlockCollision(){
   bool scoreIncremented = false; // Flag to indicate if score has been incremented for this collision

    QList<QGraphicsItem*> cItems = collidingItems();  // Get a list of colliding items
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

            // Reverse y-velocity if the ball hits the block from above or below

            if ((bally > blocky + yPad && yvelocity < 0) || (blocky > bally + yPad && yvelocity > 0)) {
                            yvelocity = -yvelocity;
            }

            // Reverse x-velocity if the ball hits the block from left or right

            if ((ballx > blockx + xPad && xvelocity < 0) || (blockx > ballx + xPad && xvelocity > 0)) {
                            xvelocity = -xvelocity;
            }

            // Remove the block from the scene, delete it, and mark it as hit
            game->scene->removeItem(block);
            delete block;

            if (!scoreIncremented) {
                game->score->increase(); // Increment score only once per block collision
               scoreIncremented = true; // Set flag to true to indicate that score has been incremented
            }


        }
    }


}


