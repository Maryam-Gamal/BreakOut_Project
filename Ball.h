
#ifndef BALL_H
#define BALL_H

#include <QGraphicsRectItem>
#include <QObject>

class Ball : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Ball(QGraphicsItem *parent = nullptr);
    double getCenterX() const;

public slots:
    void move();

private:
    double x_velocity;
    double y_velocity;

    void reverseVelocity();
    void handlePaddleCollision();
    void handleBlockCollision();
};

#endif // BALL_H
