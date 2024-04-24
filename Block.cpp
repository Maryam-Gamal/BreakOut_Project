#include "Block.h"
#include <QBrush>
#include <QGraphicsScene>


Block::Block(QGraphicsItem *parent, int row): QGraphicsRectItem(parent) {
    // draw rect
    setRect(0, 0, 20, 10);
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

    setBrush(brush);
}

