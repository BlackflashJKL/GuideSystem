#include "point.h"
using namespace std;

void Point::initPoint(int _id,int _x,int _y,int cnt,char* list){
    id=_id;
    x=_x;
    y=_y;
    name_num=cnt;
    for (int i = 0; i < cnt; i++)
    {
        name[i] = list[i];
    }
}

int Point::getid(){
    return this->id;
}

bool Point::isThisYourName(string req){
    for (int i = 0; i < name_num; i++)
    {
        if (name[i]!=req[i])
        {
            return false;
        }
    }
    return true;
    
}
