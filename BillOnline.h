#pragma once
#include"Bill.h"
#include"KhachHang.h"
#include<iomanip>

class BillOnline : public Bill{
    KhachHang kh;
    public:
        BillOnline();
        ~BillOnline();
        long long TongTienHD();
        void HoaDon();
        void XuatHoaDon();
        friend ostream& operator<<(ostream&, BillOnline&);
        BillOnline& operator = (const BillOnline&);
};

BillOnline::BillOnline(){
    cin>>this->kh;
    Bill::Bill();
}

BillOnline::~BillOnline(){
}

long long BillOnline::TongTienHD(){
    return Bill::TongTienHD() + 15000;
}

ostream& operator << (ostream& o, BillOnline& b){
    cout<<"Ma hoa Don: "<<b.mahd<<endl;
    cout<<"Nhan vien: "<<b.nv<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(7)<<"STT"<<left<<setw(25)<<"Ten mon"<<left<<setw(10)<<"Gia"<<left<<setw(10)<<"So luong"<<left<<setw(10)<<"Thanh tien"<<endl;
    int i = 1;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    Node<Pair<order, int>> *tmp = b.bill.getHead();
    while(tmp!=NULL){
        cout<<left<<setw(7)<<i++<<left<<setw(25)<<tmp->data.getFirst().getTenMon()<<left<<setw(10)<<tmp->data.getFirst().getGia()<<left<<setw(10)<<tmp->data.getSecond()<<right<<setw(10)<<tmp->data.getFirst().getGia() * tmp->data.getSecond()<<endl;
        tmp = tmp->next;
    }
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(52)<<"TONG"<<right<<setw(10)<<b.TongTienHD()<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
}

BillOnline& BillOnline::operator = (const BillOnline& b){
    this->mahd = b.mahd;
    this->bill = b.bill;
    this->tt = b.tt;
    this->nv = b.nv;
    this->kh = b.kh;
    return *(this);
}