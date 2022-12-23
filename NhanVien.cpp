#include"NhanVien.h"

NhanVien::NhanVien(string manv,string ten, int tuoi, string sdt, bool gt, string diachi) :
person(ten, tuoi, sdt, gt, diachi){
    this->manv = manv;
}

NhanVien::~NhanVien(){}

void NhanVien::show() const{
    cout<<"Ma nhan vien: "<<this->manv<<endl;
    person::show();
}

bool NhanVien::operator == (const NhanVien& nv){
    if(this->manv == nv.manv) return 1;
    return 0;
}

ostream& operator<< (ostream& o, const NhanVien& nv){
    o<<nv.manv<<" - "<<nv.ten<<" - "<<nv.tuoi<<" - "<<nv.sdt<<" - ";
    if(nv.gt == 1) o<<"Nam";
    else o<<"Nu";
    o<<" - "<<nv.diaChi;
    return o;
}

istream& operator>> (istream& i, NhanVien& nv){
    cout<<"=====NHAP THONG TIN NHAN VIEN====="<<endl;
    cout<<"Nhap ma nhan vien: ";
    cin>>nv.manv;
    cout<<"Nhap ten: ";
    fflush(stdin);
    getline(cin, nv.ten);
    cout<<"Nhap tuoi: ";
    cin>>nv.tuoi;
    cout<<"Nhap sdt: ";
    cin>>nv.sdt;
    cout<<"Nhap gioi tinh (1-Nam, 0-Nu): ";
    cin>>nv.gt;
    cout<<"Nhap dia chi: ";
    fflush(stdin);
    getline(cin, nv.diaChi);
    return i;
}