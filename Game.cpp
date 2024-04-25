#include "Game.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include "Paddle.h"
#include <QApplication>
#include "Block.h"
#include <QMessageBox>
//Ghada this will be the blocks class name when you work on it, becuase I had to include it for the spawn
#include<QBrush>

// Constructor for the Game class
Game::Game(QWidget *parent): QGraphicsView(parent){

    // Create a new QGraphicsScene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,800);   // Set the scene rectangle
    setBackgroundBrush(QBrush(QImage(":/images/background 4.jpg"))); // Set the background brush
    setScene(scene);  // Set the scene for the view
     // Disable horizontal ans vertical scrollbars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Set the fixed size for the view
    setFixedSize(600,800);
}


// Start the game

void Game::startGame(){


      // Check if the game hasn't started yet
    if (!gameStarted) {
        // Set gameStarted flag to true
        gameStarted = true;

        // Show a message box to start the game
        QMessageBox msgBox;
        msgBox.setWindowTitle("Start");
        msgBox.setText("Click to start");
        msgBox.addButton("Start", QMessageBox::AcceptRole);
        QFont font;
        font.setPointSize(16);  // Set the desired font size
        msgBox.setFont(font);
        msgBox.move(250 ,350);
        msgBox.exec();

        // Create and add a text item for the level
        QGraphicsTextItem *levelText = new QGraphicsTextItem();
        levelText->setDefaultTextColor(Qt::blue);
        QFont font1("times", 24, QFont::Bold);
        levelText->setFont(font1);
        levelText->setPos(350,10);
        scene->addItem(levelText);
        level = 1;
        levelText->setPlainText(QString("Level: ") + QString::number(level));

       //Creating a paddle
       paddle = new Paddle();
       paddle->setPos(this->width() / 2 - paddle->pixmap().width() / 2, this->height() - paddle->pixmap().height());
       scene->addItem(paddle);
       paddle->setFlag(QGraphicsItem::ItemIsFocusable);
       paddle->setFocus();
       score = new Score();
       // Create and add a score item

       score->setPos(30, 10);
       scene->addItem(score);

       // Create and add a health item
       Health = new health();
       Health->setPos(30, 50);
       scene->addItem(Health);
        // Create and add a ball
       ball = new Ball();
       ball->setPos(300, 600);
       scene->addItem(ball);

       // Create the blocks grid

       blocksgrid();

    }


}

// Create the grid of blocks

void Game::blocksgrid()
{
    const int numRows = 3;
    const int numColumns = 6;
    const int blockWidth = 80;
    const int blockHeight = 25;
    const int startY = 190;
    const int startX = 48;
    // Loop to create and add blocks to the scene

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numColumns; ++col) {
            // Calculate position for each block

            int x = startX + col * (blockWidth + 5);  //5 is the space between two blocks
            int y = startY + row * (blockHeight + 5);

            // Create a block and set its position
            Block* block = new Block(nullptr, row);
            block->setRect(x, y, blockWidth, blockHeight);

            // Add the block to the scene
            scene->addItem(block);
        }

    }
}







    //Guys: no need for spawn function because we will put the code in the main anyway so we will just initiate an object
    //blocks should take three parameters, width, height and colour
    //this main will be game1(Mariam)
    //for the other main everything should be the same except that parameters passed will be different.
    //Ghada: you should make each block is of height 30 and of width 20 becuase I will put the width 20 and height 10 so that half the window is filled
    //I will make the colour blue but also for each game or level (mariam this colour can be changed)
    //QBrush redbrush(Qt::red);
    //Blocks*blocks=new Blocks(20,10,redbrush);
    //scene->addItem(blocks);



