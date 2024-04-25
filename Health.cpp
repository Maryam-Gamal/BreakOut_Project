#include <QFont>
#include <QMessageBox>
#include "Game.h"

extern Game * game;

// Constructor for health class
health::health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    Health = 3;

    // Set initial text and formatting for the health display
    setPlainText(QString("Health: ") + QString::number(Health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("Monospace",24,QFont::Bold));
}


// Decrease the health by one and update the displayed health
void health::decrease(){
    Health--;
    setPlainText(QString("Health: ") + QString::number(Health));
    setDefaultTextColor(Qt::red);

     // If health reaches 0, trigger game over logic
    if(Health == 0){
        game->startGame();
        QMessageBox msgBox;
        msgBox.setWindowTitle("GameOver");
        msgBox.setText("GameOver!");
        msgBox.addButton("Restart", QMessageBox::AcceptRole);
        QFont font;
        font.setPointSize(16);  // Set the desired font size
        msgBox.setFont(font);
        msgBox.move(250 ,350);
        msgBox.exec();
        Health = 3; // Reset health to 3 after gameover message
        setPlainText(QString("Health: ") + QString::number(Health));

    }

    // Create a new ball and add it to the scene
    Ball *newball = new Ball();
    newball->setPos(300, 600);
    scene()->addItem(newball);

    // Reset the score
    game->score->reset();
    game->blocksgrid(); // Regenerate the blocks grid

}
