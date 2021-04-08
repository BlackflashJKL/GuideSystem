#include "point.h"

Point::Point(int _id,int _x,int _y,int cnt,QString* list){
    id = _id;
    x = _x;
    y = _y;
    name_num = cnt;
    for (int i = 0; i < cnt; i++)
    {
        name[i] = list[i];
    }
    

}

Point::    bool isThisYourName(QString req){
    for (int i = 0; i < name_num; i++)
    {
        if (name[i]==req)
        {
            return true;
        }
        
        
        
    }
    return false;
    
}
