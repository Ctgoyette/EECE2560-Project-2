#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

using namespace std;

template <typename T>
class Node
{
    public:
        T data;
        struct Node* next = nullptr;
        struct Node* prev = nullptr;
        template <typename Z>
        friend ostream& operator<< (ostream& out, const Node<Z>& node) {out << node.data; return out;}
};

#endif