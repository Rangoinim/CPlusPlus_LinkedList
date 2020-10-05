/***********************************************************
Name: Cory Munselle
Assignment: 03
Purpose: contains all of the prototypes for the LinkedList class
Notes:
***********************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>

using std::cout;
using std::endl;

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    
    bool addNode(int, string);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool idExists(int);
    
private:
    Node *head;
    void addHead(Node*);
    void addMiddle(Node*, Node*);
    void addTail(Node*, Node*);
    void delHead(Node*);
    void delMiddle(Node*);
    void delTail(Node*);
    bool isDuplicate(int);
    bool findId(int, Node**);
};
#endif /* LINKEDLIST_H */