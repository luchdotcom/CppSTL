//
// Created by luchdotcom on 04.06.22.
//

#ifndef STL_M_VECTOR_H
#define STL_M_VECTOR_H

using lon = long long;


template<typename T>
class m_Vector
{
public:
    bool isEmpty();

    lon size();

    lon push_back(T);

    lon pop_back();

    T &operator[](lon);

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
    lon capacity;
    lon length;
    T *arr;
};


#endif //STL_M_VECTOR_H
