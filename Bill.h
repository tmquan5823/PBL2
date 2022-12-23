#pragma once
#include<iostream>
#include"listFoods.h"
#include"listDrinks.h"
using namespace std;

class Bill {
    protected:
        static int id;
        string mahd;
        LinkedList<Pair<order, int>> bill;
        bool tt; //true-da thanh toan, flase-chua thanh toan
        NhanVien nv;
    public:
        Bill();
        virtual ~Bill();
        virtual void GoiMon();
        virtual void DatThucAn();
        virtual void DatThucUong();
        virtual void CapNhatHoaDon();
        virtual long long TongTienHD();
        virtual void HoaDon();
        virtual void XuatHoaDon();
        friend ostream& operator << (ostream&, Bill&);
        Bill& operator = (const Bill&);
};
