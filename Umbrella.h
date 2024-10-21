#ifndef UMBRELLA_H
#define UMBRELLA_H

#include <QGraphicsRectItem>
#include <QObject>

class Umbrella : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    Umbrella(int x, int y, int width, int height, QObject *parent = nullptr);

    void moveLeft(int distance);
    void moveRight(int distance, int screenWidth);
    // void set1Pos(int x,int y,int width,int height);
    // int x_;
    // int y_;
    int height;
    int width;
    int location_right_now;
};



#endif // UMBRELLA_H
