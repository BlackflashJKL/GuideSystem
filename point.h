#ifndef POINT_H
#define POINT_H

#include <QDebug>
using namespace std;
class Point
{
protected:


    int x;
    int y;
    int name_num;
    string name[99];
public:
    int id;//地图点的序号

    void fuckPoint(int _id, int _x, int _y, int cnt,string lis[99]);
//    void initPoint(int _id,int _x,int _y,int cnt/*,string list[10]*/);
    bool isThisYourName(string req);
    int getid();
    string* getname();
    int getname_num();
};

#endif // POINT_H
