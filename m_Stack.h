//
// Created by luchdotcom on 05.06.22.
//

#ifndef STL_M_STACK_H
#define STL_M_STACK_H

#include <iostream>

#define MAX_CAPACITY

template<typename T>
class m_Stack
{
public:
    m_Stack();
    int pop();
    bool isEmpty();
    bool push(T item);
private:
    T top;
     int arr[MAX_CAPACITY];
};

template<typename T>
m_Stack<T>::m_Stack() : top(top -1 ){}

template<typename T>
int m_Stack<T>::pop()
{
    if (top < 0){
        std::cout << "Stack is underflow";
        return 0;
    }
    else{
        return arr[top];
    }
}

template<typename T>
bool m_Stack<T>::isEmpty()
{
    return top < 0;
}

template<typename T>
bool m_Stack<T>::push(T item)
{
    if (top >= arr[MAX_CAPACITY -1])
    {
        std::cout << "Stack is Overflow";
        return false;
    }
    else{
        arr[++top]= item;
        return true; 
    }
    return false;
}

#endif //STL_M_STACK_H
