#pragma once
#include<iostream>
#include"Sample.h"
using namespace std;

template<class T>
class Vector{
        T *p;
        int length;
    public:
        Vector(int = 0);
        ~Vector();
        T &operator [] (const int& index);
        int getLength();
        int getIndex(const T&);
        void push(const T&);
        void show() const;
        friend ostream& operator << (ostream& o, const Vector<T> v){
            for(int i = 0; i<v.length;i++){
                cout<<v.p[i]<<endl;
            }
            return o;
        }
};