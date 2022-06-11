//
// Created by luchdotcom on 10.06.22.
//

#ifndef STL_M_DLLIST_H
#define STL_M_DLLIST_H

template<typename T>
class m_DLList
{
private:
    struct Node
    {
        T elem;
        Node* next;
        Node* prev;
    };
public:
    class Iterator
    {};
public:
    m_DLList();
    m_DLList(const m_DLList& nl);
    ~m_DLList();
    m_DLList& operator=(const m_DLList& nl);

    int size() const { return n; }
    bool empty() const { return (n == 0);}
    Iterator begin() const {return Iterator(header->next); }
    Iterator end() const { return Iterator(trailer); }

    void insertFront(const T& e) { insert(begin(), e); }
    void insertBack(const T& e)  { insert(end(), e); }
    void insert(const Iterator& p, const T& e);

    void eraseFront() { erase(begin()); }
    void eraseBack() { erase(--end());}
    void erase(const Iterator& p);

    void print();
private:
    int n;
    Node* header;
    Node* trailer;
};


#endif //STL_M_DLLIST_H
