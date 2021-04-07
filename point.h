#ifndef POINT_H
#define POINT_H

#include <QDebug>
#include <QString>

class Point
{
protected:
    int id;//地图点的序号
    int x;
    int y;
    QString name;
public:
    Point();
};

#endif // POINT_H
