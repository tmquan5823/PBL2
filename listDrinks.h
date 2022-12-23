#pragma once
#include"Sample.h"

class listDrinks{
    private:
        Vector<order> list;    
        int soLuong;
    public:
        listDrinks();
        ~listDrinks();
        int getSoLuong() const;
        Vector<order> getList();
        order operator[](const int&);
        void DanhSach();
};