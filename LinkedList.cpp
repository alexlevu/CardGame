//
// Created by Alex on 11/25/2021.
//
#ifndef NODES_LINKEDLIST_CPP
#define NODES_LINKEDLIST_CPP

#include "LinkedList.h"
template<class T>
void LinkedList<T>::push_front(T item)
{
    if(head == nullptr)
    {
        addFirstNode(item);
    }
    else
    {
        Node<T>* n = createNode(item);
        n->next = head;
        head = n;
    }
}

template <class T>
Node<T>* LinkedList<T>::createNode(T item)
{
    Node<T>* n = new Node<T>;
    n->data = item;
    n->next = nullptr;
    return n;
}

template<class T>
std::ostream& operator <<(std::ostream& out, const LinkedList<T>& list)
{
    Node<T>* temp = list.head;
    while(temp != nullptr)
    {
        out << temp->data;
        temp = temp->next;
    }
    return out;
}


template <class T>
void LinkedList<T>::addFirstNode(T item)
{
    Node<T>* n = createNode(item);
    n->data = item;
    n->next = nullptr;

    head = n;
    tail = n;
}

template<class T>
void LinkedList<T>::push_back(T item)
{
    if(head == nullptr)
    {
        addFirstNode(item);
    }
    else
    {
        Node<T>* n = createNode(item);
        n->next = nullptr;
        tail->next = n;
        tail = n;
    }
}
template<class T>
void LinkedList<T>::operator +=(const T& item)
{
    push_back(item);
}

template<class T>
void LinkedList<T>::insertBefore(T item, T find)
{
    Node<T>* n = createNode(item);
    Node<T>* temp = head;

    while(temp->next->data == find)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

template<class T>
void LinkedList<T>::insertAfter(T item, T item2)
{
    Node<T>* n = createNode(item);
    Node<T>* temp = head;

    while(temp->data != item2)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}
template<class T>
int LinkedList<T>::size() {

    Node<T>* temp = head;
    int count = 0;

    while(temp != nullptr)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

template<class T>
void LinkedList<T>::empty() {
    Node<T>* temp = head;
    int count = 0;

    while(temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    if(count > 0)
    {
        std::cout << "Not Empty" << std::endl;
    }
    else
    {
        std::cout << "Empty" << std::endl;
    }

}

template<class T>
bool LinkedList<T>::top()
{
    Node<T>* temp = head;

    if(temp != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
void LinkedList<T>::pop()
{
    if(head != nullptr)
    {
        head = head->next;
    }
}

#endif
#include "LinkedList.h"
