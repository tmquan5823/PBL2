#include<iostream>
#include"listBill.h"
using namespace std;

int main(){
    listBill list;
    BillTaiCho btc;
    list.getListBill().push(btc);
    BillOnline bo;
    list.getListBill().push(bo);
    cout<<list<<endl;
    return 0;
}