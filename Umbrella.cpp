#include "Umbrella.h"
#include<QBrush>
Umbrella::Umbrella(int x, int y, int width, int height, QObject *parent)
    : QObject(parent), QGraphicsRectItem(x, y, width, height) {
    setBrush(Qt::green); // Green umbrella
    // x_=x;
    // y_=y;
    this->width=width;
    this->height=height;
    location_right_now=x;
}

void Umbrella::moveLeft(int distance) {

    if(location_right_now-distance>=-width){
        setPos(x()-distance,y());
        location_right_now-=distance;
    }
}

void Umbrella::moveRight(int distance, int screenWidth) {

    if(location_right_now+distance<=screenWidth+width){
        setPos(x()+distance,y());
        location_right_now+=distance;
    }
}





// qDebug() << x();
// if (x_-distance>=-width) {
//     setPos(x_ - distance, y_);
//     qDebug() << "Moved left to:" << x_-distance;
// }
// if(x-distance>=-(x_)){
//     setPos(x()-distance)
// }
// if (x_+ distance <= screenWidth+width) {
//     setPos(x_ + distance, y_);
//     qDebug() << "Moved right to:" << x_+distance;
// }
