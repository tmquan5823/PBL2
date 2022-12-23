#pragma once
#include"listBill.h"

class QuanLy{
    private:
        string tenNhaHang;
        listNhanVien listNV;
        listBill list;
        listFoods lf;
        listDrinks ld;
    public:
        QuanLy();
        ~QuanLy();
        void DatHoaDon();
        void CapNhatNhaHang();
        void CapNhatTenNhaHang();
        //Cap nhat menu
        void CapNhatMenu();
        void CapNhatGia();
        void ThemMon();
        void XoaMon();
        //Quan ly nhan vien
        void QuanLyNhanVien();
        void DoanhThuTrongNgay();
        void DoanhThuTrongThang();
};

QuanLy::QuanLy(){
    do
    {
        try
        {
            system("cls");
            cout<<"=====NHA HANG VUI VE======"<<endl;
            cout<<"1. Dat hoa don"<<endl;
            cout<<"2. Cap nhat nha hang"<<endl;
            cout<<"3. Quan ly nhan vien"<<endl;
            cout<<"4. Doanh thu trong ngay"<<endl;
            cout<<"5. Doanh Thu trong thang"<<endl;
            cout<<"0. Thoat"<<endl;
            cout<<"Vui long nhap lua chon: ";
            int choice; fflush(stdin); cin>>choice;
            if(cin.fail()){
                throw MyException("Nhap khong hop le");
            }
            if(choice == 1){
                this->DatHoaDon();
            }
            else if(choice == 2){
                this->CapNhatNhaHang();
            }
            else if(choice == 3){
                this->QuanLyNhanVien();
            }
            else if(choice == 4){
                this->DoanhThuTrongNgay();
            }
            else if(choice == 5){
                this->DoanhThuTrongThang();
            }
            else if(choice == 0){
                break;
            }
            else{
                throw MyException("Nhap khong hop le!");
            }
        }
        catch(const MyException& e)
        {
            cout << e.what() << '\n';
            system("pause");
        }
        
    } while (true);
    
}

QuanLy::~QuanLy(){}

void QuanLy::DatHoaDon(){
    this->list.QuanLy();
}

void QuanLy::CapNhatNhaHang(){
    do
    {
        system("cls");
        cout<<"======CAP NHAT NHA HANH======="<<endl;
        cout<<"1. Cap nhat ten nha hang"<<endl;
        cout<<"2. Cap nhat Menu"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon";
        int choice;
        cin>>choice;
        if(choice == 1){
            this->CapNhatTenNhaHang();
        }
        else if(choice == 2){
            this->CapNhatMenu();
        }
        else if(choice == 0){
            break;
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
    
}

void QuanLy::CapNhatTenNhaHang(){

}

void QuanLy::CapNhatGia(){
    do
    {
        system("cls");
        cout<<"======CAP NHAT GIA BAN======"<<endl;
        cout<<"1. Cap nhat gia mon an"<<endl;
        cout<<"2. Cap nhat gia thuc uong"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        cin>>choice;
        if(choice == 1){
            lf.CapNhatGiaBan();
        }
        else if(choice == 2){
            ld.CapNhatGiaBan();
        }
        else if(choice == 0){
            break;
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
    
}

void QuanLy::ThemMon(){
    do
    {
        system("cls");
        cout<<"======THEM MON======"<<endl;
        cout<<"1. Them thuc an"<<endl;
        cout<<"2. Them thuc uong"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        cin>>choice;
        if(choice == 1){
            lf.ThemMonAn();
        }   
        else if(choice == 2){
            this->ld.ThemThucUong();
        }
        else if(choice == 0){
            break;
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
}

void QuanLy::XoaMon(){
    do
    {
        system("cls");
        cout<<"======THEM MON======"<<endl;
        cout<<"1. Xoa thuc an"<<endl;
        cout<<"2. Xoa thuc uong"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        cin>>choice;
        if(choice == 1){
            lf.XoaMonAn();
        }
        else if(choice == 2){
            ld.XoaThucUong();
        }
        else if(choice == 0){
            break;
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
}



void QuanLy::CapNhatMenu(){
    do
    {
        system("cls");
        cout<<"=====CAP NHAT MENU======"<<endl;
        cout<<"1. Cap nhat gia ban"<<endl;
        cout<<"2. Xoa mon khoi menu"<<endl;
        cout<<"3. Them mon vao menu"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        cin>>choice;
        if(choice == 1){
            this->CapNhatGia();
        }
        else if(choice == 2){
            this->XoaMon();
        }
        else if(choice == 3){
            this->ThemMon();
        }
        else if(choice == 0){
            break;
        }   
        else {
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
    
}



void QuanLy::QuanLyNhanVien(){
    lNV.QuanLy();
}

void QuanLy::DoanhThuTrongNgay(){
    system("cls");
}

void QuanLy::DoanhThuTrongThang(){

}
