#pragma once
#include<iostream>
#include<string>
using namespace std;

class person{
    protected:
        string ten;
        int tuoi;
        string sdt;
        bool gt; //true-name, flase-nu
        string diaChi;
    public:
        person(string = "", int = 0, string = "", bool = true, string = "");
        virtual ~person();
        virtual void capNhat();
        void show() const;
};  