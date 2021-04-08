#include "map.h"
#include<fstream>
using namespace std;
Map::Map(QString fileDir)
{
    int dotNum=0;
    //this place needs the filestream readin
    //1st read the total num and initiate

    fstream map_file;
    string 
    map_file.open("fileDir",ios::in);
    if (!map_file)
    {
        cout<< "File not found!"<<endl;
    }
    else{
        cout<<"File found!!"<<endl;
        
    }
    
    point = (Point*)malloc(dotNum*sizeof (Point));

    //2nd read each point and put into the point vec
}
