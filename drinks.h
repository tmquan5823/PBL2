#pragma once
#include"order.h"

class drinks : public order {
    private:
    public:
        drinks(string = "", int = 0);
        friend ostream& operator << (ostream& o, const drinks& d){
            o<<d.ten<<": "<<d.gia;
            return o;
        }
        const drinks& operator = (const drinks&);
};