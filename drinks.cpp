#include"drinks.h"

drinks::drinks(string s, int g){
    this->ten = s;
    this->gia = g;
    this->kt = false;
}

const drinks& drinks::operator = (const drinks& d){
    this->ten = d.ten;
    this->gia = d.gia;
    this->kt = d.kt;
    return *(this);
}   
