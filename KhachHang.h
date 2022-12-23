#pragma once
#include"person.h"

class KhachHang : public person {
    public:
        KhachHang(string = "", int = 0, string = "", bool = true, string = "");
        ~KhachHang();
        void show() const;
        bool operator == (const KhachHang&);
        friend ostream& operator<< (ostream&, const KhachHang&);
        friend istream& operator>> (istream&, KhachHang&);
};