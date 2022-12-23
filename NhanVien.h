#pragma once 
#include"person.h"

class NhanVien : public person {
    string manv;
    public:
        NhanVien(string = "", string = "", int = 0, string = "", bool = true, string = "");
        ~NhanVien();
        void show() const;
        bool operator == (const NhanVien&);
        friend ostream& operator<< (ostream&, const NhanVien&);
        friend istream& operator>> (istream&, NhanVien&);
};