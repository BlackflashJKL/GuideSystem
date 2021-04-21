#include "map.h"
#include <fstream>
#include <iostream>
#include "point.h"
#include <QTime>
#include <stdio.h>
#include <QDebug>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
#include <string.h>

using namespace std;

Map::Map(string fileDir)
{
    //int dotNum=0;
    //this place needs the filestream readin
    //1st read the total num and initiate
    ifstream map_file(fileDir,ios::in);

   // map_file.open(fileDir,ios::in);
    if (!map_file.is_open())
    {
        cout<< "File not found!"<<endl;
    }
    else{
        //cout<<"File found!!"<<endl;
        //the first line should be eaten in advance

        int _id,_x,_y,cnt;

        map_file>>NumberOfPoint;
//        Point point[99];
        // point=(Point**)malloc(NumberOfPoint*sizeof (Point*));
        for (int i = 0; i < NumberOfPoint; i++)
        {
            map_file>>_id>>_x>>_y>>cnt;
//            cout<<_id<<' '<<_x<<' '<<_y<<' '<<cnt<<' ';
            string name[10];
            for (int j = 0; j < cnt; j++)
            {
                map_file>>name[j];
            }
//            for(int j=0;j<cnt;j++){
//                cout<<name[j]<<endl;
//            }

            point[i].fuckPoint(_id,_x,_y,cnt,name);

            //在map类的构造函数里，读文件，初始化点
        }

    }
    map_file.close();
    //2nd read each point and put into the point vec

    //cout<<"cout works";
    //cout<<"Input src and dst, test now!";
    //string src="快递站",dst="医务室";
    //this->Dijkstra(point[0],point[15]);
    int src=point[0].getid();
    int dst=point[15].id;
    cout<<src<<endl;
    cout<<dst<<endl;
    this->Dijkstra(point[5],point[15]);
}

Point Map::NameToPoint(string req){
    for (int i = 0; i < NumberOfPoint; i++)
    {
        if(point[i].isThisYourName(req)==true)
            return point[i];
    }
}

std::vector<Point> Map::RoutePlanning(Point* src,Point* dst,QTime Departure){
    //this->Dijkstra(src,dst);
}
void Map::Dijkstra(Point src,Point dst){
    //cout<<"what";
    double INF=9999;
    int N=NumberOfPoint;
    double mp[N][N];	//用邻接矩阵来存图；
    double dis[N];		//用了记录源点到各顶点的距离；
    int vis[N];//标记顶点是否访问过；
    int path[N];//记录路径
    int n=N;

    /*初始化*/
    int i,j;
    memset(vis, 0, sizeof(vis));
    for(i=0;i<N;i++)
        path[i]=-1;

     /*通过文件读入邻接矩阵*/
     FILE *fp=fopen("M_dis.txt","r");
     if(fp==NULL)
         cout<<"it doesn't work";
     for(i=0;i<N;i++)
         for(j=0;j<N;j++)
             fscanf(fp,"%lf",&mp[i][j]);
     fclose(fp);

    int  min_number;//路径最短的点序号
    int st=src.getid()-1;//源点数组下标

    for (i = 0; i < n; i++)//用dis数组记录源点到与它相连接的顶点的距离；
    {
        dis[i] = mp[st][i];
    }
    vis[st] = 1;//标记刚才源点,表示已经访问；

    while (1)
    {
        min_number = -1;
        double min = INF;
        for (i = 0; i < n; i++)//在当前的dis距离数组中找到一个最小的路径，并将这条路到达的顶点记录；
        {
            if (vis[i] != 1 && dis[i] < min)
            {
                min = dis[i];
                min_number = i;
            }
        }
        vis[min_number] = 1;
        if (min_number == -1)//直到所有的顶点都已访问过，结束循环，当然，这是最坏的情况，如果在不考虑时间的情况下，可以这么写；
            break;
        for (i = 0; i < n; i++)//更新dis数组，
        {
            if (vis[i] != 1 && dis[i] > min + mp[min_number][i])
            {
                dis[i] = min + mp[min_number][i];//更新dis
                path[i]=min_number;//path[i]记录dis[i]暂时最短路径的最后一个中途节点min_num，表明dis[i]最后一段从节点min_num到节点i
            }
        }

    }

    /*打印测试*/
    int sec=st;
    //cout<<dis[dst->getid()-1]<<endl;
    stack<double> q;               //由于记录的中途节点是倒序的，所以使用栈（先进后出），获得正序
    for(i=1;i<n;i++)            //打印从出发节点到各节点的最短距离和经过的路径
    {
        j=i;
        while(path[j]!=-1)      //如果j有中途节点
        {
            q.push(j);          //将j压入堆
            j=path[j];          //将j的前个中途节点赋给j
        }
        q.push(j);
//        printf("%d=>%d, length:%d, path: %d ",sec,i,dis[i],sec);
        cout<<sec+1<<"=>"<<i+1<<", length:"<<dis[i]+1<<", path:"<<sec+1<<' ';
        while(!q.empty())       //先进后出,获得正序
        {
            cout<<q.top()<<' ';//打印堆的头节点
            q.pop();            //将堆的头节点弹出
        }
        cout<<endl;
    }


}
