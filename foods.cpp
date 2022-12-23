#include"foods.h"

foods::foods(string s, int g){
    this->ten = s;
    this->gia = g;
    this->kt = true;
}

const foods& foods::operator = (const foods& f){
    this->ten = f.ten;
    this->gia = f.gia;
    this->kt = f.kt;
    return *(this);
}