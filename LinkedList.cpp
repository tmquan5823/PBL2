#include"LinkedList.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

template<class T>
LinkedList<T>::~LinkedList(){
    this->head = NULL;
}

template<class T>
void LinkedList<T>::erase(){
    this->head = NULL;
}

template <class T>
Node<T> *LinkedList<T>::getHead(){
    return this->head;
}

template<class T>
T LinkedList<T>::getData(const int& index) const{
    Node<T>* tmp = this->head;
    int i = 0;
    while (tmp!=NULL)
    {
        if(i == index) return tmp->data;
        else {
            i++;
            tmp = tmp->next; 
        }
    }
}

template <class T>
void LinkedList<T>::push(const T& value){
    Node<T>* newNode = new Node<T>(value);
    if(this->head == NULL){
        this->head = newNode;
        this->length++;
        return;
    }
    Node<T>* tmp = this->head;
    while ((tmp->next != NULL))
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    this->length++;
}

template<class T>
int LinkedList<T>::getLength() const{
    return this->length;
}

template<class T>
int LinkedList<T>::getIndex(const T& t){
    Node<T>* tmp = this->head;
    int i = 0;
    while(tmp != NULL){
        if(tmp->data == t) return i;
        i++;
        tmp = tmp->next;
    }
    return -1;
}

template <class T>
void LinkedList<T>::deleteNode(const int& index){
    if(this->head == NULL) return;
    int i = 0;
    Node<T> *n = this->head;
    if(index == 0){
        this->head = this->head->next;
    }
    else if(index == this->length - 1){
        this->deleteLastNode();
    }
    else{
        while (i != index - 1)
        {
            if(n->next != NULL){
                n = n->next;
                i++;
            }
        }
        n->next = n->next->next;
    }
}

template <class T>
void LinkedList<T>::deleteLastNode(){
    Node<T> *n = this->head;
    while (n->next->next != NULL)
    {
        n = n->next;
    }
    n->next = NULL;
}

template <class T>
void LinkedList<T>::show(){     
    Node<T>* tmp = this->head;
    if (this->head == NULL) {
        cout << "Danh sach trong!" << endl;
        return;
    }
    int i = 1;
    while (tmp!=NULL)
    {
        cout<<i<<". ";
        cout<<tmp->data<<endl;
        tmp = tmp->next;
        i++;
    }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& list){
    this->length = list.length;
    if(list.head == NULL){
        this->erase();
        return *(this);
    }
    Node<T>* tmp = list.head;
    this->erase();
    while (tmp != NULL)
    {
        this->push(tmp->data);
    }
    return *(this);
}