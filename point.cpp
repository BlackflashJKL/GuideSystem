#include "point.h"

Point::Point(int _id,int _x,int _y,int cnt,QString* list){
    id = _id;
    x = _x;
    y = _y;
    for (int i = 0; i < cnt; i++)
    {
        name[i] = list[i];
    }
    

}

