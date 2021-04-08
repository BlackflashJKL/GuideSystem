#ifndef MAP_H
#define MAP_H

#include"point.h"
#include"road.h"
#define SpeedOfBike 5;

class Map
{
private:
    int NumberOfPoint;
    int NumberOfRoad;
    Point *point;
    Road *road;
    int **M_adj;//是否邻接的矩阵
    int **M_dis;//距离邻接矩阵
    int **M_bike;//道路能否骑行的矩阵

    QString IdToName(int id);//返回id对应的地点名
    int NameToId(QString name);//返回地点名对应的id
public:
    Map(QString fileDir);//读入文件数据，初始化
    void RoutePlanning(Point src,Point dst);
    void Find(QString req);
};

#endif // MAP_H
