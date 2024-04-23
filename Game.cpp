#include "Game.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include "Paddle.h"
#include <QApplication>
//#include "Block.h" //Ghada this will be the blocks class name when you work on it, becuase I had to include it for the spawn
#include<QBrush>

Game::Game(QWidget *parent): QGraphicsView(parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,750);
    setBackgroundBrush(QBrush(QImage(":/Images/background 4.jpg")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,750);


    //Creating a paddle
    paddleitem = new Paddle();
    paddleitem->setPos(this->width() / 2 - paddleitem->pixmap().width() / 2, this->height() - paddleitem->pixmap().height()); //the default width and height of the paddle
    scene->addItem(paddleitem);
    paddleitem->setFlag(QGraphicsItem::ItemIsFocusable);
    paddleitem->setFocus();





    //Guys: no need for spawn function because we will put the code in the main anyway so we will just initiate an object
    //blocks should take three parameters, width, height and colour
    //this main will be game1(Mariam)
    //for the other main everything should be the same except that parameters passed will be different.
    //Ghada: you should make each block is of height 30 and of width 20 becuase I will put the width 20 and height 10 so that half the window is filled
    //I will make the colour blue but also for each game or level (mariam this colour can be changed)
    //QBrush redbrush(Qt::red);
    //Blocks*blocks=new Blocks(20,10,redbrush);
    //scene->addItem(blocks);



}
