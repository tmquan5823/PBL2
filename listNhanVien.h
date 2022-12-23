#pragma once
#include"Sample.h"

class listNhanVien{
    Vector<NhanVien> list;
    int soLuong;
    public:
        listNhanVien();
        ~listNhanVien();
        void Add(const NhanVien&);
        void show();
};