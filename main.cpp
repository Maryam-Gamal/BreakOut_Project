#include <QApplication>
#include "Game.h"
#include <QMessageBox>


Game * game; // Global pointer to the Game object


// Main function of the application
int main(int argc, char *argv[]){
    QApplication a(argc, argv);


    game = new Game(); // Create a new Game object
    game->show();   // Show the game window

    // Start the game if it hasn't already started

    if (!game->gameStarted) {
        game->startGame();
    }
    return a.exec();
}
