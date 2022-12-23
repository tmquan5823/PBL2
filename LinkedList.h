#pragma once
#include<iostream>
using namespace std;

template <class T>
class Node{
    public:
        T data;
        Node<T>* next;
        Node(){
            this->data = NULL;
            this->next = NULL;
        }
        Node(const T& data){
            this->data = data;
            this->next = NULL;
        }
        const T& operator = (const Node<T>& n){
            this->data = n.data;
        }
};   

template<class T>
class LinkedList{
        Node<T>* head;
        int length;
    public:
        LinkedList();
        ~LinkedList();
        void erase();
        Node<T>  *getHead();
        T getData(const int&) const;
        int getLength() const;
        int getIndex(const T&);
        void push(const T&);
        void deleteLastNode();
        void deleteNode(const int&);
        void show();
        LinkedList<T>& operator = (const LinkedList<T>&);
};
