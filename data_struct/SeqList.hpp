//
// Created by PC on 2025/5/25.
//

#ifndef SEQLIST_H
#define SEQLIST_H

#include <algorithm>
#include <format>
#include <iostream>
#include <stdexcept>

#define INIT_SIZE 10
#define INCREMENT 10

template<typename T>
class SeqList
{
public:
    explicit SeqList(int maxsize = INIT_SIZE);
    ~SeqList();

    // Add an element to the end of the list
    void Add(const T& element);
    // Insert an element at the specified index
    void Insert(int index, const T& element);
    // Remove an element from the list
    void Remove(int index);
    // Get the element at the specified index
    bool Get(int index, T& e) const;
    // located a element
    int Locate(const T& element) const;
    // Get the current length of the list
    int Length() const;
    // Check if the list is empty
    bool IsEmpty() const;
    // Clear the list
    void Clear();
    // reverse the list
    void Reverse();
    // display the list
    void Display() const;


private:
    T* m_data;        // Pointer to the array of elements
    int m_maxsize;    // Maximum size of the list
    int m_length; // Current number of elements in the list
};

template<typename T>
SeqList<T>::SeqList(int maxsize)
    : m_maxsize(maxsize), m_length(0) {
    m_data = new T[m_maxsize];
}

template<typename T>
SeqList<T>::~SeqList() {
    delete[] m_data;
}

template<typename T>
void SeqList<T>::Add(const T& element) {
    if (m_length >= m_maxsize) {
        // Resize the array if necessary
        T* new_data = new T[m_maxsize + INCREMENT];
        for (int i = 0; i < m_length; ++i) {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_maxsize += INCREMENT;
    }
    m_data[m_length++] = element;
}

template<typename T>
void SeqList<T>::Insert(int index, const T& element) {
    if (index < 0 || index > m_length) {
        throw std::out_of_range("Index out of range");
    }
    if (m_length >= m_maxsize) {
        // Resize the array if necessary
        T* new_data = new T[m_maxsize + INCREMENT];
        for (int i = 0; i < m_length; ++i) {
            new_data[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_data;
        m_maxsize += INCREMENT;
    }
    for (int i = m_length; i > index; --i) {
        m_data[i] = m_data[i - 1];
    }
    m_data[index] = element;
    ++m_length;
}

template<typename T>
void SeqList<T>::Remove(int index) {
    if (index < 0 || index >= m_length) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < m_length - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }
    --m_length;
}

template<typename T>
bool SeqList<T>::Get(int index, T&e ) const {
    if (index < 0 || index >= m_length) {
        return false;
    }

    e = m_data[index];
    return true;
}

template<typename T>
int SeqList<T>::Locate(const T &element) const {
    for (int i = 0; i < m_length; ++i) {
        if (m_data[i] == element) {
            return i;
        }
    }
    return -1;
}


template<typename T>
int SeqList<T>::Length() const {
    return m_length;
}

template<typename T>
bool SeqList<T>::IsEmpty() const {
    return m_length == 0;
}

template<typename T>
void SeqList<T>::Clear() {
    m_length = 0; // Reset the length to 0
    // Optionally, you could also reset the array if needed
    // delete[] m_data;
    // m_data = new T[m_maxsize];
}

template<typename T>
void SeqList<T>::Reverse() {
    if (m_length <= 1) {
        return;
    }

    for (int i = 0; i < m_length / 2; ++i) {
        T temp = m_data[i];
        m_data[i] = m_data[m_length - 1];
        m_data[m_length - 1] = temp;
    }
}

template<typename T>
void SeqList<T>::Display()const {
    std::for_each(m_data, m_data + m_length, [](T& element) {
        std::cout << element << " ";
    });

    std::cout << std::endl;
}


#endif //SEQLIST_H
