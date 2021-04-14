#include "map.h"
#include <fstream>
#include<iostream>
#include"point.h"
#include<QTime>
#include<stdio.h>
#include<QDebug>
#include<iostream>
#include<string>

using namespace std;

Map::Map(string fileDir)
{
    int dotNum=0;
    //this place needs the filestream readin
    //1st read the total num and initiate

    ifstream map_file(fileDir,ios::in);
    
   // map_file.open(fileDir,ios::in);
    if (!map_file.is_open())
    {
        cout<< "File not found!"<<endl;
    }
    else{
        cout<<"File found!!"<<endl;
        //the first line should be eaten in advance
        
        int _id,_x,_y,cnt;
        char name[50];
        map_file>>NumberOfPoint;
        point=(Point**)malloc(NumberOfPoint*sizeof (Point*));
        for (int i = 0; i < NumberOfPoint; i++)
        {
            map_file>>_id>>_x>>_y>>cnt;
            for (int j = 0; j < cnt; j++)
            {
                map_file>>name;
            }

            point[i]->initPoint(_id,_x,_y,cnt,name);
            //在map类的构造函数里，读文件，初始化点
        }
        
    }
    map_file.close();
    
    Dijkstra(point[40],point[41]);//测试一下下
    //2nd read each point and put into the point vec
}

Point* Map::NameToPoint(string req){
    for (int i = 0; i < NumberOfPoint; i++)
    {
        if(point[i]->isThisYourName(req)==true)
            return point[i];
    }
    
}

std::vector<Point> Map::RoutePlanning(Point* src,Point* dst,QTime Departure){

}
std::vector<Point> Map::Dijkstra(Point* src,Point* dst){
    double INF=9999;
    int N=NumberOfPoint;
    double mp[N][N];	//用邻接矩阵来存图；
    double dis[N];		//用了记录源点到各顶点的距离；
    int vis[N];		//标记顶点是否访问过；
    int n=N;

    /*初始化*/
    int i,j;
        memset(vis, 0, sizeof(vis));

     /*输入邻接矩阵*/
     FILE *fp=fopen("M_dis.txt","r");
     for(i=0;i<N;i++)
         for(j=0;j<N;j++)
             fscanf(fp,"%lf",&mp[i][j]);

    int  p;
    int st=src->getid()-1;
    for (i = 0; i < n; i++)//用dis数组记录源点到与它相连接的顶点的距离；
    {
        dis[i] = mp[st][i];
    }
    vis[st] = 1;//标记刚才源点,表示已经访问；

    while (1)
    {
        p = -1;
        double min = INF;
        for (i = 0; i < n; i++)//在当前的dis距离数组中找到一个最小的路径，并将这条路到达的顶点记录；
        {
            if (vis[i] != 1 && dis[i] < min)
            {
                min = dis[i];
                p = i;
            }
        }
        vis[p] = 1;
        if (p == -1)//直到所有的顶点都已访问过，结束循环，当然，这是最坏的情况，如果在不考虑时间的情况下，可以这么写；
            break;
        for (i = 0; i < n; i++)//更新dis数组，
        {
            if (vis[i] != 1 && dis[i] > min + mp[p][i])
            {
                dis[i] = min + mp[p][i];
            }
        }

    }
    qDebug()<<dis[dst->getid()-1];

}
