//
// Created by luchdotcom on 20.04.23.
//
#include "m_DLLis//
// Created by Lachezar on 13.11.2020 г..
//
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

template< typename T >
class DoubleList {
private:
    struct Node {
        T elem;
        Node *next;
        Node *prev;
    };
public:
    class iterator {
    public:
        Node *v;

        explicit iterator( Node *u ) { v = u; }

    public:
        T &operator*( ) { return v->elem; }

        bool operator==( const iterator &p ) const { return v == p.v; }

        bool operator!=( const iterator &rhs ) const { return v != rhs.v; }

        int operator+( const iterator &rhs ) {
            v = rhs.v;
            return *this;
        }

        iterator &operator++( ) {
            v = v->next;
            return *this;
        }

        iterator &operator--( ) {
            v = v->next;
            return *this;
        }

    };

private:
    int n;
    Node *header;
    Node *trailer;
public:
    DoubleList( );

    DoubleList( const DoubleList &rhs );//todo

    ~DoubleList( );//todo

    DoubleList &operator=( const DoubleList &rhs );//todo

    int size( ) const { return n; }

    bool isEmpty( ) const { return ( n == 0 ); }

    iterator begin( ) const { return iterator( header->next ); }

    iterator end( ) const { return iterator( trailer ); }

    void insertFrom( const T &e ) { insert( begin(), e ); }

    void insertBack( const T &e ) { insert( end(), e ); }

    void insert( const iterator &p, const T &e );

    void erase( const iterator &p );//todo

    void eraseBack( ) { erase( -- end()); }

    void eraseFrom( ) { erase( begin()); }

    T& at( int i ) const {
        Node *ptr = nullptr;
        return  ptr->elem;
    }

    void set( Node &i, const T &e ); //zamenq ell.//todo
    void print( ) const;

    void bubbleSort( );

};

template< typename T >
DoubleList< T >::DoubleList( ) {
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}

template< typename T >
DoubleList< T >::DoubleList( const DoubleList &rhs ) {
    n = rhs.size();
    header = new Node;//???
    trailer = new Node;///???
    header->next = trailer;
    trailer->prev = header;
    iterator itTmp = iterator( rhs.begin());
    int id = 0;
    while ( id < rhs.size()) {
        Node *node = itTmp.v;
        insertBack( node->elem );
        ++ itTmp;
        id ++;
    }

}

template< typename T >
DoubleList< T >::~DoubleList( ) {
    int id;
    iterator tmp = iterator( begin());
    while ( id < size()) {
        Node *node = tmp.v;
        id ++;
        ++ tmp;
    }
    delete &n;
    delete &header;
    delete &trailer;
}

template< typename T >
DoubleList< T > &DoubleList< T >::operator=( const DoubleList< T > &rhs ) {
    if ( this != &rhs ) {
        rhs = rhs.size();
        iterator iter = iterator( rhs.begin());
        -- iter; ////???
        header = iter.v;
        iter = iterator( rhs.end());
        trailer = iter.v;
    }
    return *this;
}

template< typename T >
void DoubleList< T >::insert( const DoubleList< T >::iterator &lhs, const T &rhs ) {
    Node *w = lhs.v;
    Node *p = w->prev;

    Node *u = new Node;
    u->elem = rhs;
    u->next = w;
    w->prev = u;
    u->prev = p;
    p->next = u;
    n ++;
}

template< typename T >
void DoubleList< T >::erase( const DoubleList::iterator &rhs ) {
    Node *v = rhs.v;
    Node *w = v->next;
    Node u = v->prev;

    u->nex = w;
    w->prev = u;
    delete v;
    n --;
}


template< typename T >
void DoubleList< T >::set( DoubleList::Node &i, const T &e ) {
    Node *v = iterator(i);
    v->elem = e;
}

template< typename T >
void DoubleList< T >::print( ) const {
    iterator iter = begin();
    int id = 0;
    while ( id < size()) {
        Node *node = iter.v;
        std::cout << node->elem << " ";
        ++ iter;
        id ++;
    }
    std::cout << std::endl;
}

template< typename T >
void DoubleList< T >::bubbleSort( ) {
    Node *current = header;
    if ( current == nullptr ) { return; }
    if ( current->next == nullptr ) { return; }
    //bool flag= true;
    current = header;
    while ( ! isEmpry()) {
        // flag = false;
        while ( current != nullptr ) {
            if ( current->elem < current->next->elem ) {
                swap( current->elem, current->next->elem );
            }
            current = current->next;
        }
    }
}


/*
void sort(auto *start){
    bool flag=true;
  iterator ptr =  begin();
   struct Node*ptr1= nullptr;
    if (start == nullptr){return;}

    do {
        flag=false;
        ptr = start;
        while (ptr->next!=ptr1){
            if (ptr->elem> ptr->next->elem){
                swap(ptr->next,ptr->next->elem);
                flag=true;
            }
            ptr=ptr->next;
        }
        ptr1=ptr;
    }while (flag);

}
 */
void createList( int n, DoubleList< int > *&L ) {
    for ( int i = 0; i < n; ++ i ) {
        int p;
        cin >> p;
        L->insertBack( p );
    }
}

void sum( auto &L, int s ) {

    for ( int i = 0; i < L->size();  i++ ) {
        int n= L->at( i ) + L->at( i+1 );
        if ( n == s ) {
            cout << i<<" "<<i+1<<endl;
        }
    }
}

int main( ) {

    auto *L4 = new DoubleList< int >();
    int n;
    cout << ( L4->isEmpry() ? "yes" : "No" );
    cin >> n;
    createList( n, L4 );
    cout << "L4 =";
    L4->print();
    cout << ( L4->isEmpry() ? "yes \n" : "No\n" );
    // L4->bubbleSort();
    // cout << "sort = ";
    //L4->print();
    int s;
    cin>>s;
    sum(L4,s);

    return 0;
}t.h"