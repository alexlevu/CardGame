//
// Created by Alex on 11/25/2021.
//

#ifndef SFML_PROJECT_NODE_H
#define SFML_PROJECT_NODE_H
template<class T>
struct Node
{
public:
    T data;
    Node<T>* next = nullptr;

};
#endif //SFML_PROJECT_NODE_H
