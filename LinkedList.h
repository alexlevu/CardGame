//
// Created by Alex on 11/25/2021.
//

#ifndef SFML_PROJECT_LINKEDLIST_H
#define SFML_PROJECT_LINKEDLIST_H
#include "Node.h"
#include <iostream>

template<class T>
class LinkedList {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    void addFirstNode(T item);
    Node<T> *createNode(T item);
public:

    void push_front(T item);
    void push_back(T item);
    void insertBefore(T item, T find);
    void insertAfter(T item, T item2);
    void operator +=(const T& item);
    int size();
    void empty();
    bool top();
    void pop();

    template<class S>
    friend std::ostream& operator <<(std::ostream& out, const LinkedList<S>& list);


};

#include "LinkedList.cpp"
#endif //SFML_PROJECT_LINKEDLIST_H
