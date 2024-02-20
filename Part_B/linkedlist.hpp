#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <cstddef>
#include "node.hpp"

using namespace std;

template <typename T>
class LinkedList
{
    public:
        
        LinkedList();
        ~LinkedList();

        /**
         * @brief Makes T value into a node and inserts after the curr node
         * 
         * @param value 
         */
        void insert_after(T value);

        /**
         * @brief Deletes the current node from the list
         * 
         */
        void erase_element();

        /**
         * @brief returns the data from the node at index
         * 
         * @param index 
         * @return T 
         */
        T popNode(int index);

        /**
         * @brief Makes T value into a node and inserts at the end of the list
         * 
         * @param value 
         */
        void addLast(T value);

        template <typename Y>
        friend ostream& operator<< (ostream& out, const LinkedList<Y>&);

        Node<T> *getHead() {return head;}
        void setHead(Node<T> *newHead) {head = newHead;}
    
    private:

        Node<T> *curr;
        Node<T> *head;
        Node<T> *tail;

};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    curr = nullptr;
};

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *delCard = head;
    while (delCard != NULL)
    {
        head = head->next;
        delete delCard;
        delCard = head;
    }
    head = nullptr;
}

template <typename T>
void LinkedList<T>::insert_after(T value)
{
    if (head == nullptr)
    {
        head = new Node<T>();
        head->data = value;
        tail = head;
        curr = head;
    }
    else
    {
        Node<T> *tmp = new Node<T>();
        tmp->data = value;
        tmp->prev = curr;
        tmp->next = curr->next;
        if (curr->next != nullptr)
        {
            curr->next->prev = tmp;
        }
        curr->next = tmp;
        curr = tmp;
        if(curr->next == nullptr)
        {
            tail = curr;
        }

    }
};


template <typename T>
void LinkedList<T>::erase_element()
{   
    if(curr == head)
    {
        // cout << "curr == head" << endl;
        if (curr->next != nullptr)
        {
            head = curr->next;
            head->prev = nullptr;
        }
        else
        {
            head = nullptr;
            tail = nullptr;
        }
        delete curr;
    }
    else if(curr == tail)
    {
        // cout << "curr == tail" << endl;
        tail = curr->prev;
        tail->next = nullptr;
        delete curr;
    }
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }
    curr = head;
    
};

template <typename Y>
ostream& operator<< (ostream& out, const LinkedList<Y>& list)
{
    Node<Y>* current = list.head;

    while (current != nullptr){
        out << *current << endl;
        current = current->next;
    }
    return out;
}


template <typename T>
T LinkedList<T>::popNode(int index)
{
    curr = head;
    for(int i = 1; i < index; i++)
    {
        // cout << i << ":   " << *curr << endl;
        curr = curr->next;
    }
    T tmp = (*curr).data;

    erase_element();
    return tmp;
}


template <typename T>
void LinkedList<T>::addLast(T value)
{   
    if (head == nullptr)
    {
        head = new Node<T>();
        head->data = value;
        tail = head;
    }
    else
    {
        Node<T> *tmp = new Node<T>();
        tmp->data = value;
        tail->next = tmp;
        tmp->prev = tail;
        tmp->next = nullptr;
        tail = tmp;
    }
}

#endif