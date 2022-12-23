#pragma once
#include"Bill.h"

class BillTaiCho : public Bill{
    int soBan;
    public:
        BillTaiCho();
        ~BillTaiCho();
        void HoaDon();
        void XuatHoaDon();
};

BillTaiCho::BillTaiCho(){
    cout<<"Nhap so ban: ";
    cin>>this->soBan;
    Bill::Bill();
}