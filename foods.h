#pragma once
#include"order.h"

class foods : public order {
    private:
    public:
        foods(string = "", int = 0);
        friend ostream& operator << (ostream& o, const foods& f){
            o<<f.ten<<": "<<f.gia;
            return o;
        }
        const foods& operator = (const foods&);
};