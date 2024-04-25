#include "Score.h"
#include "qgraphicsscene.h"
#include "qmessagebox.h"
#include <QFont>

// Constructor for Score class
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    // Set initial text and formatting for the score display
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",24, QFont::Bold));
}


// Reset the score to zero
void Score::reset() {
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score)); // Update displayed score
}

// Increase the score by one and update the displayed score
void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));

    // If score reaches 18, display a message box indicating level 1 completion
    if(score == 18){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Level 1 Completed");
        msgBox.setText("Congratulations! Level completed.");
        msgBox.addButton("Next Level", QMessageBox::AcceptRole);
        QFont font;
        font.setPointSize(16);
        msgBox.setFont(font);
        msgBox.move(250 ,350);
        msgBox.exec();
        exit(1);  // Exit the game after finishing level one... will be modified after adding the other levels
    }
}


//function to return the currebt score
int Score::get()
{
    return score;
}

