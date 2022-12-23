#include"Bill.h"
#include<iomanip>
#include<string>
#include<ctime>
#include<sstream>
#include<fstream>
using namespace std;

int Bill::id = 0;
listFoods lf;
listDrinks ld;

Bill::Bill(){
    //Thong tin nhan vien
    cin>>this->nv;
    this->id++;
    stringstream ss;
    ss << this->id;
    string str = ss.str();
    this->mahd = str;
    this->tt = false;
    int choice;
    while (true)
    {
        system("cls");
        cout << "\t\t ==========GOI MON==========" << endl;
        cout << "1. Goi mon" << endl;
        cout << "2. Cap nhat hoa don" << endl;
        cout << "3. Xem hoa don" << endl;
        cout << "4. Xuat hoa don" << endl;
        cout << "0. Thoat" << endl;
        cout << "Vui long nhap lua chon: ";
        cin >> choice;
        if(choice ==  1){
            this->GoiMon();
        }
        else if(choice == 2){
            this->CapNhatHoaDon();
        }
        else if(choice == 3){
            system("cls");
            cout<<"\t\t============HOA DON============\n\n";
            this->HoaDon();
            system("pause");
        }
        else if(choice == 4){
            this->XuatHoaDon();
            break;
        }
        else if(choice == 0){
            break;
        }
        else {
            cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
            system("pause");
        }
    }   
}

Bill::~Bill(){}

void Bill::GoiMon(){
    while (true)
    {
        system("cls");
        cout<<"==========GOI MON=========="<<endl;
        cout<<"1. Dat thuc an"<<endl;
        cout<<"2. Dat thuc uong"<<endl;
        cout<<"0. Thoat"<<endl;
        int choice;
        cout<<"Vui long nhap lua chon: ";
        cin>>choice;
        if(choice == 1){
            this->DatThucAn();
        }
        else if(choice == 2){
            this->DatThucUong();
        }
        else if(choice == 0){
            break;
        }
        else {
            cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
            system("pause");
        }
    }
}

void Bill::DatThucAn(){
    cout<<"==========DAT THUC AN==========\n"<<endl;
    lf.DanhSach();
    cout<<"0. Thoat";
    while (true)
    {
        int goimon;
        Pair<order, int> tmp;
        cout<<"Vui long chon mon: ";
        cin>>goimon;
        if(goimon < 0 || goimon > lf.getSoLuong()){
            cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
            system("pause");
        }
        else if(goimon == 0) break;
        else{
            do{
                cout<<lf[goimon - 1];
                tmp.setFirst(lf[goimon - 1]);
                int sl;
                cout<<"\nNhap so luong mon: ";
                cin>>sl;

                tmp.setSecond(sl);
                if(this->bill.getIndex(tmp) == -1){
                    bill.push(tmp);
                }
                else{
                    bill.deleteNode(this->bill.getIndex(tmp));
                    bill.push(tmp);
                }
                if(tmp.getSecond() < 0) {
                    bill.deleteLastNode();
                    cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
                }
                if(tmp.getSecond() == 0) bill.deleteLastNode();
            } 
            while (tmp.getSecond() < 0);      
            cout<<"Dat thanh cong!"<<endl; 
        }
    }
}

void Bill::DatThucUong(){
    cout<<"==========DAT THUC UONG==========\n"<<endl;
    ld.DanhSach();
    cout<<"0. Thoat";
    while (true)
    {
        int goimon;
        Pair<order, int> tmp;
        cout<<"Vui long chon mon: ";
        cin>>goimon;
        if(goimon < 0 || goimon > ld.getSoLuong()){
            cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
            system("pause");
        }
        else if(goimon == 0) break;
        else{
            do{
                cout<<ld[goimon - 1];
                tmp.setFirst(ld[goimon - 1]);
                int sl;
                cout<<"\nNhap so luong mon: ";
                cin>>sl;

                tmp.setSecond(sl);
                if(this->bill.getIndex(tmp) == -1){
                    bill.push(tmp);
                }
                else{
                    bill.deleteNode(this->bill.getIndex(tmp));
                    bill.push(tmp);
                }
                if(tmp.getSecond() < 0) {
                    bill.deleteLastNode();
                    cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
                }
                if(tmp.getSecond() == 0) bill.deleteLastNode();
            } 
            while (tmp.getSecond() < 0);      
            cout<<"Dat thanh cong!"<<endl; 
        }
    }
}

void Bill::CapNhatHoaDon(){
    system("cls");
    cout<<"\t\t==========CAP NHAT HOA DON=========\n\n";
    cout<<this->mahd<<endl;
    this->HoaDon();
    cout<<setfill('-')<<setw(10)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<setw(1)<<"|"<<"0. Thoat"<<setw(1)<<"|"<<endl;
    cout<<setfill('-')<<setw(10)<<"-"<<endl;
    cout<<setfill(' ');
    int choice;
    cout<<"Vui long chon mon muon cap nhat: ";
    cin>>choice;
    choice--;
    if(choice >= 0 && choice < bill.getLength()){
        cout<<bill.getData(choice).getFirst()<<endl;
        cout<<"Nhap so luong mon muon chon: ";
        int sl;
        cin>>sl;
        if(sl<0){
            cout<<"Nhap khong hop le!"<<endl;
        }
        else{
            if(sl == 0){
                bill.deleteNode(choice);
            }
            else{
                Pair<order, int> tmp;
                tmp.setFirst(bill.getData(choice).getFirst());
                tmp.setSecond(sl);
                bill.deleteNode(choice);
                bill.push(tmp);
            }
        }
        cout<<"Cap nhat thanh cong!"<<endl;
        system("pause"); 
    }
}

void Bill::HoaDon(){
    cout<<"Ma hoa Don: "<<this->mahd<<endl;
    cout<<"Nhan vien: "<<this->nv<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(7)<<"STT"<<left<<setw(25)<<"Ten mon"<<left<<setw(10)<<"Gia"<<left<<setw(10)<<"So luong"<<left<<setw(10)<<"Thanh tien"<<endl;
    int i = 1;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    Node<Pair<order, int>> *tmp = this->bill.getHead();
    while(tmp!=NULL){
        cout<<left<<setw(7)<<i++<<left<<setw(25)<<tmp->data.getFirst().getTenMon()<<left<<setw(10)<<tmp->data.getFirst().getGia()<<left<<setw(10)<<tmp->data.getSecond()<<right<<setw(10)<<tmp->data.getFirst().getGia() * tmp->data.getSecond()<<endl;
        tmp = tmp->next;
    }
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(52)<<"TONG"<<right<<setw(10)<<this->TongTienHD()<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
}

long long Bill::TongTienHD(){
    long long total = 0;
    Node<Pair<order, int>> *tmp = this->bill.getHead();
    while(tmp!=NULL){
        total += (tmp->data.getFirst().getGia() * tmp->data.getSecond());
        tmp = tmp->next;
    }
    return total;
}

void Bill::XuatHoaDon(){
    time_t now = time('\0');
    tm *t = localtime(&now);
    char *ch = asctime(t);
    ofstream billOut("Bill.txt");
    billOut.clear();
    billOut << "\n\t =====================HOA DON======================" << endl;
    billOut<<"\n"<<ch<<endl;
    billOut<<setfill('-')<<setw(62)<<"-"<<endl;
	billOut<<setfill(' ');
    billOut<<left<<setw(7)<<"STT"<<left<<setw(25)<<"Ten mon"<<left<<setw(10)<<"Gia"<<left<<setw(10)<<"So luong"<<left<<setw(10)<<"Thanh tien"<<endl;
    int i = 1;
    billOut<<setfill('-')<<setw(62)<<"-"<<endl;
	billOut<<setfill(' ');
    Node<Pair<order, int>> *tmp = this->bill.getHead();
    while(tmp!=NULL){
        billOut<<left<<setw(7)<<i++<<left<<setw(25)<<tmp->data.getFirst().getTenMon()<<left<<setw(10)<<tmp->data.getFirst().getGia()<<left<<setw(10)<<tmp->data.getSecond()<<right<<setw(10)<<tmp->data.getFirst().getGia() * tmp->data.getSecond()<<endl;
        tmp = tmp->next;
    }
    billOut<<setfill('-')<<setw(62)<<"-"<<endl;
	billOut<<setfill(' ');
    billOut<<left<<setw(52)<<"TONG"<<right<<setw(10)<<this->TongTienHD()<<endl;
    billOut<<"\n\t\t\t\t\t\tCam on quy khach!"<<endl;
    this->tt = true;
    cout<<"Xuat hoa don thanh cong!"<<endl;
    system("pause");
}

ostream& operator << (ostream& o, Bill& b){
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

Bill& Bill::operator = (const Bill& b){
    this->mahd = b.mahd;
    this->bill = b.bill;
    this->tt = b.tt;
    this->nv = b.nv;
    return *(this);
}