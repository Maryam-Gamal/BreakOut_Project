#include "Block.h"
#include <QBrush>
#include <QGraphicsScene>

// Constructor for Block class
Block::Block(QGraphicsItem *parent, int row): QGraphicsRectItem(parent) {
    // draw rect for the block
    setRect(0, 0, 80, 25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    // Set color based on the row number
    switch (row) {
        case 0:
            brush.setColor(Qt::blue);
            break;
        case 1:
            brush.setColor(Qt::red);
            break;
        case 2:
            brush.setColor(Qt::green);
            break;
        case 3:
            brush.setColor(Qt::yellow);
            break;
        // Add more cases for additional rows with different colors
        default:
            brush.setColor(Qt::gray);
            break;
    }

    setBrush(brush); // Set the brush color for the block
}

