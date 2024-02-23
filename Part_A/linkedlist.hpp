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

        /**
         * @brief Deletes the current node from the list
         * 
         */
        void erase_element();

        /**
         * @brief returns the data from the node at index
         * 
         * @param index: index of node to get 
         * @return T 
         */
        T popNode(int index);

        /**
         * @brief Makes T value into a node and inserts at the end of the list
         * 
         * @param value: add a node to the end of the list with the data passed to the function 
         */
        void addLast(T value);

        /**
         * @brief Overloads the output stream to output one node at a time, each on a new line
         * 
         * @param out: output stream
         * @param list: list to output
         * @return ostream&
         */
        template <typename Y>
        friend ostream& operator<< (ostream& out, const LinkedList<Y>&);
    
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
void LinkedList<T>::erase_element()
{   
    //Check if the element to be erased is the head or tail of the linked list and assign the previous node and next node pointers accordingly
    if(curr == head)
    {
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

    //Iterate through the linked list until the index of the node to return is found
    for(int i = 1; i < index; i++)
    {
        curr = curr->next;
    }
    T tmp = (*curr).data;

    //Erase the node after temporarily storing it to be returned
    erase_element();
    return tmp;
}


template <typename T>
void LinkedList<T>::addLast(T value)
{   
    //Checks if there are any nodes in the linekd list and adds a new node accordingly
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