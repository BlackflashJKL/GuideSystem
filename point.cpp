#include "point.h"
#include <string>
#include <stdlib.h>
using namespace std;

Point::Point(){

}
void Point::initPoint(int _id,int _x,int _y,int cnt/*string list[10]*/){
    id=_id;
    this->x=_x;
    this->y=_y;
    this->name_num=cnt;
//    for (int i = 0; i < cnt; i++)
//    {
//       this->name[i] = list[i];
//    }
}

int Point::getid(){
    return this->id;
}

string* Point::getname(){
    return this->name;
}
int Point::getname_num(){
    return this->name_num;
}

bool Point::isThisYourName(string req){
    for (int i = 0; i < name_num; i++)
    {
        if (name[i]==req)
        {
            return true;
        }
    }
    return false;
    
}
