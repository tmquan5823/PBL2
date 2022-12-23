#include"KhachHang.h" 
#include<string>
using namespace std;

KhachHang::KhachHang(string ten, int tuoi, string sdt, bool gt, string diachi) :
person(ten, tuoi, sdt, gt, diachi){}

KhachHang::~KhachHang(){
}

void KhachHang::show() const{
    person::show();
}

bool KhachHang::operator == (const KhachHang& kh){
    if(this->ten == kh.ten && this->sdt == kh.sdt) return 1;
    return 0;
}

ostream& operator<< (ostream& o, const KhachHang& kh){
    o<<kh.ten<<" - "<<kh.tuoi<<" - "<<kh.sdt<<" - ";
    if(kh.gt == 1) o<<"Nam";
    else o<<"Nu";
    o<<" - "<<kh.diaChi;
    return o;
}

istream& operator>> (istream& i, KhachHang& kh){
    cout<<"======NHAP THONG TIN KHACH HANG======"<<endl;
    cout<<"Nhap ten: ";
    fflush(stdin);
    getline(cin, kh.ten);
    cout<<"Nhap tuoi: ";
    cin>>kh.tuoi;
    cout<<"Nhap SDT: ";
    cin>>kh.sdt;
    cout<<"Nhap gioi tinh (1-NAM, 0-NU): ";
    cin>>kh.gt;
    cout<<"Nhap dia chi: ";
    fflush(stdin);
    getline(cin, kh.diaChi);
    return i;
}