#include "Raindrop.h"
#include<QBrush>
Raindrop::Raindrop(int x, int y, int width, int height, QObject *parent)
    : QObject(parent), QGraphicsEllipseItem(x, y, width, height) {
    setBrush(Qt::blue); // Blue raindrops
}

void Raindrop::moveDown(int speed) {
    setPos(x(), y() + speed);
}

bool Raindrop::isOutOfScreen(int screenHeight) const {
    return y() > screenHeight;
}
