#ifndef BALL_H
#define BALL_H
#include <QGraphicsRectItem>
#include <QObject>
//#include <QSet>
class Ball : public QObject, public  QGraphicsPixmapItem {
    Q_OBJECT
public:
    Ball(QGraphicsItem *parent = nullptr);
    double getCenterX() const;

public slots:
    void move();

private:
    double xvelocity;
    double yvelocity;

    void reverseVelocity();
    void handlePaddleCollision();
    void handleBlockCollision();
};

#endif // BALL_H
