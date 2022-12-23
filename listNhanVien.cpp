#include"listNhanVien.h"

listNhanVien::listNhanVien(){
}

listNhanVien::~listNhanVien(){
}

void listNhanVien::Add(const NhanVien& nv){
    this->list.push(nv);
}

void listNhanVien::show(){
    this->list.show();
}