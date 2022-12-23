#include"person.h"

person::person(string ten, int tuoi, string sdt, bool gt, string diachi) :
ten(ten), tuoi(tuoi), sdt(sdt), gt(gt), diaChi(diachi){}

person::~person(){}

void person::capNhat(){}

void person::show() const{
    cout<<"Ten: "<<this->ten<<endl;
    cout<<"Tuoi: "<<this->tuoi<<endl;
    cout<<"SDT: "<<this->sdt<<endl;
    cout<<"Gioi tinh: ";
    if(this->gt == 1) cout<<"Nam"<<endl;
    else cout<<"Nu"<<endl;
    cout<<"Dia chi: "<<this->diaChi<<endl;
}