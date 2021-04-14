#ifndef MAP_H
#define MAP_H

#include"point.h"
#include<vector>
#define SpeedOfBike 5;

class Map
{
private:
    int NumberOfPoint;
    int NumberOfRoad;
    Point **point;//建立指向Point类的指针数组
    int **M_adj;//是否邻接的矩阵
    int **M_dis;//距离邻接矩阵
    int **M_bike;//道路能否骑行的矩阵

public:
    string IdToName(int id);//输入id，返回对应的地点名
    Point* NameToPoint(string name);//输入地点名，返回Point
    Map(string fileDir);//读入文件数据，初始化
    std::vector<Point> RoutePlanning(Point* src,Point* dst,QTime Departure);//输入起始地点，终点，开始时间，导航策略，调用Dijkstra进行路径规划
    std::vector<Point> Dijkstra(Point* src,Point* dst);
};

#endif // MAP_H
