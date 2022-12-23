#include"listDrinks.h"
#include<fstream>
#include<iomanip>

listDrinks::listDrinks(){
    this->soLuong = 0;
    //Doc file drinks
    ifstream fileDrinks;
    fileDrinks.open("drinks.txt", ios::in);
    fileDrinks.seekg(0, ios::beg);
    while(!fileDrinks.eof()){
        foods f;
        string food;
        getline(fileDrinks, food);
        f.setTenMon(food);
        int price;
        fileDrinks >> price;
        string s;
        getline(fileDrinks, s);
        f.setGia(price);
        f.setKT(true);
        this->soLuong++;
        this->list.push(f);
    }
    fileDrinks.close();
}

listDrinks::~listDrinks(){}

int listDrinks::getSoLuong() const{
    return this->soLuong;
}


Vector<order> listDrinks::getList(){
    return this->list;
}

order listDrinks::operator[](const int& index){
    foods f;
    if(index >= 0 && index < this->soLuong){
        return list[index];
    }
    return f;
}

void listDrinks::DanhSach(){
    cout<<"\t\t=====DANH SACH MON AN======\n"<<endl;
    cout<<setfill('-')<<setw(56)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<setw(2)<<"||"<<left<<setw(5)<<" STT"<<setw(2)<<"|"<<left<<setw(30)<<" Ten mon"<<setw(5)<<"|"<<left<<setw(10)<<" Gia"<<setw(2)<<"||"<<endl;
    cout<<setfill('-')<<setw(56)<<"-"<<endl;
    cout<<setfill(' ');
    for(int i = 0;i<this->soLuong;i++){
        cout<<setw(2)<<"||"<<left<<setw(2)<<" "<<setw(3)<<i + 1<<setw(2)<<"|"<<left<<setw(30)<<list[i].getTenMon()<<setw(5)<<"|"<<left<<setw(10)<<list[i].getGia()<<setw(2)<<"||"<<endl;
    }
    cout<<setfill('-')<<setw(56)<<"-"<<endl;
    cout<<setfill(' ');
}