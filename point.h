#ifndef POINT_H
#define POINT_H

#include <QDebug>
using namespace std;
class Point
{
protected:
    int id;//地图点的序号
    int x;
    int y;
    int name_num;
    char name[99];
public:
    void initPoint(int _id,int _x,int _y,int cnt,char* list);
    bool isThisYourName(string req);
    int getid();
};

#endif // POINT_H
