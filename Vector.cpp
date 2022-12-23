#include"Vector.h"

template<class T>
Vector<T>::Vector(int n){
    this->length = n;
    if(this->length != 0){
        this->p = new T[this->length];
    }
};

template<class T>
Vector<T>::~Vector(){
    delete[] this->p;
}

template<class T>
T &Vector<T>::operator[] (const int& index){
    static T t;
    if(index >= 0 && index < this->length){
        return *(this->p + index);
    }
    return t;
}

template<class T>
int Vector<T>::getLength(){
    return this->length;
}

template<class T>
void Vector<T>::push(const T& value){
    this->length++;
    if(this->length - 1 == 0){
        this->p = new T[this->length];
        this->p[this->length - 1] = value;
    }
    else{
        T *tmp = new T[this->length];
        for(int i = 0;i<this->length - 1;i++){
            tmp[i] = this->p[i];
        }
        delete[] this->p;
        this->p = new T[this->length];
        for(int i = 0;i<this->length;i++){
            this->p[i] = tmp[i];
        }
        this->p[length - 1] = value;
        delete[] tmp;
    }
}

template<class T>
void Vector<T>::show() const{
    for(int i = 0;i<this->length;i++){
        cout<<this->p[i]<<" ";
    }
}