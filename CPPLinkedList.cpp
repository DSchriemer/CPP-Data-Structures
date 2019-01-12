//  CPPLinkedList.cpp
//
//  Created by David Schriemer on 2019-01-10.
//  Copyright © 2019 David Schriemer. All rights reserved.
//
//  A simple implementation of a linked list with insert and delete functions.

#include <iostream>
#include <cstring> //Needed for C++ string variables

//Why to use class instead of struct:
//A class that allocates memory will deallocate it before being destroyed.
//Structs tend to be inconsistent with memory deallocation.

class Node {
public: //Public members are members of a struct or class that can be accessed from outside of the struct or class (default is private)
    int value;
    Node *next = NULL;
    Node *prev;
};

class LinkedList
{
public:
    int length;
    Node* head = NULL;
    Node* tail = NULL;
    
    void insert(int newdata)
    {
        Node *tmp = new Node;
        if (length == 0)
        {
            head = tmp;
            tail = tmp;
        }else{
            tail->next = tmp;
            tail = tmp;
        }
        length++;
        tmp->value = newdata;
    }
    
    int deleter(int deletedata)
    {
        if (length == 0)
        {
            return 1;
        }
        Node *ptr;
        Node *ptr2;
        ptr = head;
        if (ptr->value == deletedata && length == 1)
        {
            head = NULL;
            tail = NULL;
            std::cout << "ONE";
            return 0;
        }
        if (ptr->value == deletedata && length != 1)
        {
            head = head->next;
            std::cout << "Two";
            return 0;
        }
       while(ptr->next != NULL)
       {
           ptr2=ptr;
           ptr = ptr->next; //While loop tests condition at the beginning of segement, not continuously
           //std::cout<< ptr->value;
           if (ptr->value == deletedata)
           {
               ptr2->next = ptr->next;
               free(ptr);
               free(ptr2);
               return 0;
           }
       }
       
                return 0;
    }
    void print() {
        Node* ptr;
        ptr = head;
        while(ptr != NULL) {
            std::cout<< ptr->value <<" ";
            ptr = ptr->next;
        }
        free(ptr);
    }
    
};

int main()
{
    LinkedList list;
    list.print();
    list.insert(7);
    list.insert(8);
    list.insert(9);
    list.insert(10);
    list.deleter(8);
    list.print();
}
