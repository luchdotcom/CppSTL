//
// Created by luchdotcom on 04.06.22.
//

#ifndef STL_M_VECTOR_H
#define STL_M_VECTOR_H

#include <cstdlib>
#include <iostream>

using ull = long long;


template<typename T>
class m_Vector
{
public:
    explicit m_Vector(ull = 100);

    explicit m_Vector(ull *arr);

    ~m_Vector()
    {
        delete[] arr;
    }

    bool isEmpty();

    ull size();

    ull push_back(T);

    ull pop_back();

    void at(unsigned index);

    T front();

    T &operator[](ull);

    class iter
    {
        T *ptr;
    public:
        iter() : ptr(nullptr)
        {}

        bool operator==(const iter &rhs) const
        { return ptr == rhs.ptr; }

        bool operator!=(const iter &rhs) const
        { return *this != ptr; }

        T operator*() const
        { return *ptr; }

        iter &operator++()
        {
            ++ptr;
            return *this;
        }

        iter operator++(int)
        {
            iter tmp(*this);
            ++*this;
            return tmp;
        }
    };

    iter begin() const;

    iter end() const;

private:
    ull capacity;
    ull length;
    T *arr;
};

template<typename T>
m_Vector<T>::m_Vector(ull n) : capacity(n), arr(new T[n]), length(0)
{
}

template<typename T>
bool m_Vector<T>::isEmpty()
{
    return size() <= 0;
}

template<typename T>
ull m_Vector<T>::size()
{
    return length;
}

template<typename T>
ull m_Vector<T>::push_back(T itam)
{
    if (length == capacity) {
        T *oldCapacity = arr;
        arr = new T[capacity = capacity * 2];
        std::copy(oldCapacity, oldCapacity + length, arr);
        delete[] oldCapacity;
    }
    arr[length++] = itam;

    return length;
}

template<typename T>
ull m_Vector<T>::pop_back()
{
    if (isEmpty()) {
        return 0;
    }
    arr[length--];
}

template<typename T>
T &m_Vector<T>::operator[](ull index)
{
    if (index >= length) {
        std::cout << "Error: Array index ot of range";
        exit(0);
    }
    return *(index + arr);
}

template<typename T>
typename m_Vector<T>::iter m_Vector<T>::begin() const
{
    return iter(arr);
}

template<typename T>
typename m_Vector<T>::iter m_Vector<T>::end() const
{
    return m_Vector::iter(arr + length);
}

template<typename T>
void m_Vector<T>::at(unsigned int index)
{
    if (index >= size()) {
        std::cout << "ERROR: out of range index >= size()" << index, size();
    }
}

template<typename T>
T m_Vector<T>::front()
{
    return *arr;
}

template<typename T>
m_Vector<T>::m_Vector(ull *arr) : arr(new T[*arr]), capacity(capacity), length(0)
{

}


#endif //STL_M_VECTOR_H
