#ifndef RAINDROP_H
#define RAINDROP_H

#include <QGraphicsEllipseItem>
#include <QObject>

class Raindrop : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT

public:
    Raindrop(int x, int y, int width, int height, QObject *parent = nullptr);

    void moveDown(int speed); // Move the raindrop down by the given speed
    bool isOutOfScreen(int screenHeight) const; // Check if the raindrop is out of the screen
};

#endif // RAINDROP_H
