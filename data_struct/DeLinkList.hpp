//
// Created by PC on 2025/5/27.
//

#ifndef DELINKLIST_H
#define DELINKLIST_H
#include <iostream>

template<typename T>
struct DeLinkNode {
    T data;
    DeLinkNode<T>* next;
    DeLinkNode<T>* prev;
};

template<typename T>
class DeLinkList {
    public:
    DeLinkList();
    ~DeLinkList();

    bool Insert(int i, const T& data);
    bool Delete(int i);

    void Display();
    void Reverse();

    private:
    DeLinkNode<T>* m_head;
    int m_length;
};

template<typename T>
DeLinkList<T>::DeLinkList() {
    m_head = new DeLinkNode<T>;
    m_head->next = m_head;
    m_head->prev = m_head;
    m_length = 0;
}

template<typename T>
DeLinkList<T>::~DeLinkList() {
    if (m_head->prev->next == m_head) {
        delete m_head;
        m_length = 0;
        return;
    }


    m_head->prev->next = nullptr;
    while (m_head) {
        auto temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
    m_length = 0;
}

template<typename T>
bool DeLinkList<T>::Insert(int i, const T& data) {
    if ( i < 0 || i > m_length ) {
        return false;
    }

    auto temp = m_head;
    for ( int j = 0; j < i; j++ ) {
        temp = temp->next;
    }

    auto node = new DeLinkNode<T>;
    node->data = data;
    node->next = temp->next;
    node->prev = temp;

    temp->next->prev = node;
    temp->next = node;
    m_length++;

    return true;
}

template<typename T>
bool DeLinkList<T>::Delete(int i) {
    if ( i < 0 || i > m_length ) {
        return false;
    }

    auto temp = m_head;
    for ( int j = 0; j < i; j++ ) {
        temp = temp->next;
    }

    auto next = temp->next;
    next->prev->next = next->next;
    next->next->prev = next->prev;

    delete next;
    m_length--;

    return true;
}

template<typename T>
void DeLinkList<T>::Display() {
    auto temp = m_head->next;
    while (temp != m_head) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
void DeLinkList<T>::Reverse() {
    auto prev = m_head;
    auto next = m_head->next;
    if (next == m_head) {
        return;
    }

    while (next != m_head) {
        auto temp = next->next;
        next ->next = prev;
        prev->prev = next;
        prev = next;
        next = temp;
    }

    m_head->next = prev;
    prev->prev = m_head;
}



#endif
