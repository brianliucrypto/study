//
// Created by PC on 2025/5/26.
//

#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
class LinkList {
    public:
    LinkList();
    ~LinkList();

    bool Insert(int i, const T& data);
    bool Delete(int i,  T& data);

    bool GetAt(int i, const T& data);
    int Locate(const T& data);

    int Length()const;
    bool IsEmpty()const;

    void Display()const;

    void Reverse();

    private:
    Node<T>* m_head;
    int m_length;
};

template<typename T>
LinkList<T>::LinkList() {
    m_head = new Node<T>;
    m_length = 0;
    m_head -> next = nullptr;
}

template<typename T>
LinkList<T>::~LinkList() {
    while (m_head -> next != nullptr) {
        Node<T>* temp = m_head -> next;
        delete m_head;
        m_head = temp;
    }
}

template<typename T>
bool LinkList<T>::Insert(int i, const T &data) {
    if ( i < 0 || i > Length() ) {
        return false;
    }

    Node<T>* temp = m_head;

    for (int j = 0; j < i; j++) {
        temp = temp -> next;
    }

    auto newNode = new Node<T>;
    newNode -> data = data;
    newNode -> next = temp -> next;
    temp -> next = newNode;
    m_length++;

    return true;
}

template<typename T>
bool LinkList<T>::Delete(int i,  T &data) {
    if ( i < 0 || i > Length() ) {
        return false;
    }

    Node<T>* temp = m_head;

    for (int j = 0; j < i; j++) {
        temp = temp -> next;
    }

   auto next = temp->next;
    temp -> next = next -> next;
    data = next -> data;
    delete next;
    m_length--;

    return true;
}

template<typename T>
bool LinkList<T>::GetAt(int i, const T &data) {
    if ( i < 0 || i > Length() ) {
        return false;
    }

    Node<T>* temp = m_head;

    for (int j = 0; j < i; j++) {
        temp = temp -> next;
    }

    auto next = temp->next;
    data = next -> data;
    return true;
}

template<typename T>
int LinkList<T>::Locate( const T &data) {
    Node<T>* temp = m_head->next;

    int i = -1;
   while (temp != NULL) {
       if (temp -> data == data) {
           return i+1;
       }
       i++;
   }

    return i;
}

template<typename T>
int LinkList<T>::Length()const {
    return m_length;
}

template<typename T>
bool LinkList<T>::IsEmpty()const {
    return m_length <= 0;
}

template<typename T>
void LinkList<T>::Display()const {
    auto temp = m_head->next;
    while (temp != NULL) {
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout << std::endl;
}

template<typename T>
void LinkList<T>::Reverse() {
    auto temp = m_head->next;
    auto pre = m_head;
    while (temp != NULL) {
        auto next = temp -> next;

        if (pre == m_head) {
            temp -> next = nullptr;
        }else {
            temp -> next = pre;
        }

        pre = temp;
        temp = next;
    }

    m_head->next = pre;
}




#endif