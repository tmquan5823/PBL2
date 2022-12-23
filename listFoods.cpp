#include"listFoods.h"
#include<fstream>
#include<iomanip>

listFoods::listFoods(){
    this->soLuong = 0;
    //Doc file foods
    ifstream fileFoods;
    fileFoods.open("foods.txt", ios::in);
    // fileFoods.seekg(0, ios::beg);
    while(!fileFoods.eof()){
        foods f;
        string food;
        getline(fileFoods, food);
        f.setTenMon(food);
        int price;
        fileFoods >> price;
        string s;
        getline(fileFoods, s);
        f.setGia(price);
        f.setKT(true);
        this->soLuong++;
        this->list.push(f);
    }
    fileFoods.close();
}

listFoods::~listFoods(){}

int listFoods::getSoLuong() const{
    return this->soLuong;
}


Vector<order> listFoods::getList(){
    return this->list;
}

order listFoods::operator[](const int& index){
    foods f;
    if(index >= 0 && index < this->soLuong){
        return list[index];
    }
    return f;
}

void listFoods::DanhSach(){
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