#include "point.h"
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

void Point::fuckPoint(int _id, int _x, int _y, int cnt,string lis[99])
{
    id=_id;
    //cout<<id<<endl;
    this->x = _x;
    this->y = _y;
    this->name_num = cnt;
       for (int i = 0; i < cnt; i++)
       {
          this->name[i] = lis[i];
          //cout<<name[i]<<endl;
       }

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
