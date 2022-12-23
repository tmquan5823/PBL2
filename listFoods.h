#pragma once
#include"Sample.h"

class listFoods{
    private:
        Vector<order> list;    
        int soLuong;
    public:
        listFoods();
        ~listFoods();
        int getSoLuong() const;
        Vector<order> getList();
        order operator[](const int&);
        void DanhSach();
};