#include "map.h"
#include <fstream>
using namespace std;
Map::Map(QString fileDir)
{
    int dotNum=0;
    //this place needs the filestream readin
    //1st read the total num and initiate

    fstream map_file;
    
    map_file.open("fileDir",ios::in);
    if (!map_file)
    {
        cout<< "File not found!"<<endl;
    }
    else{
        cout<<"File found!!"<<endl;
        //the first line should be eaten in advance
        
        int tot,id,x,y,cnt;
        QString name[999];
        map_file>>tot;
        point = (Point*)malloc(tot*sizeof (Point));
        for (int i = 0; i < tot; i++)
        {
            map_file>>id>>x>>y>>cnt;
            for (int j = 0; j < cnt; j++)
            {
                map_file>>name[j];
            }

            point[i] = Point(id,x,y,cnt,name);
            
        }
        
    }
    
    

    //2nd read each point and put into the point vec
}
