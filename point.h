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
    int name_num;
    QString name[999];
public:
    Point(int _id,int _x,int _y,int cnt,QString* list);
    bool isThisYourName(QString req);
};

#endif // POINT_H
