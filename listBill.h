#pragma once
#include"Bill.h"
#include"BillTaiCho.h"
#include"BillOnline.h"

class listBill{
    Vector<Bill> lBill;
    public:
        listBill(){}
        ~listBill(){}
        Vector<Bill> getListBill(){
            return this->lBill;
        }
        friend ostream& operator << (ostream&, const listBill&);
};

ostream& operator << (ostream& o, const listBill& lb){
    o<<lb;
    return o;
}