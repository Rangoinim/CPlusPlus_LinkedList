/***********************************************************
Name: Cory Munselle
Assignment: 03
Purpose: Works with the linked list in various different ways
Notes: There's a comment above clearList that mentions Diego's help. I was trying to do it
with just current and I was bashing my head against the wall, so he helped me out and showed me his clearList
method. It was easier than just working with current, so I stopped being stubborn and tried it. I wanted to
make sure that he gets credit! If this is an issue, let me know and I can fix it.
***********************************************************/

#include "linkedlist.h"

//constructor and destructor
LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    clearList();
}

//public member methods
bool LinkedList::addNode(int id, string str)
{
    bool success = false;
    Node *current = head;
    Node *temp = new Node;
    temp->data.data = str;
    temp->data.id = id;
    temp->forward = NULL;
    temp->back = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else if (current->data.id > id && id != -1)
    {
        addHead(temp);
    }
    else if (current->data.id < id && isDuplicate(id) == false)
    {
        while (current->data.id < id && current->forward != NULL)
        {
            current = current->forward;
            if (current->data.id > id && current->back->data.id != id)
            {
                addMiddle(current, temp);
            }
        }
        if (current->data.id < id)
        {
            addTail(current, temp);
        }
    }
    else
    {
        return false;
    }        
    return true;
}

bool LinkedList::deleteNode(int id)
{
    bool success = true;
    Node *current = head;
    if (findId(id, &current) == true)
    {
        if (current->forward == NULL && current->back == NULL)
        {
            delete head;
            head = NULL;
        }
        else if (current == head && current->data.id == id)
        {
            delHead(current);
        }
        else if (current->forward == NULL)
        {
            delTail(current);
        }
        else if (current->back->data.id < id && current->forward->data.id > id)
        {
            delMiddle(current);
        }
    }
    else
    {
       success = false; 
    }
    return success;
}

bool LinkedList::getNode(int id, Data* tempData)
{
    Node *current = head;
    if (findId(id, &current) == true)
    {
        tempData->id = current->data.id;
        tempData->data = current->data.data;
        return true;
    }
    else
    {
        return false;
    }
}

void LinkedList::printList(bool direction)
{
    Node *current = head;
    int count = 0;
    if (direction == false)
    {
        while (current != NULL)
        {
            cout << current->data.id << ": " << current->data.data << endl;
            current = current->forward;
        }
    }
    else
    {
        while (current->forward != NULL)
        {
            current = current->forward;
            count++;
        }
        for (int i=0; i <= count; i++)
        {
            cout << current->data.id << ": " << current->data.data << endl;
            current = current->back;
        }
    }
}

int LinkedList::getCount()
{
    Node *current = head;
    int count = 0;
    if (current != NULL)
    {
        count = 1;
        while (current->forward != NULL)
        {
            current = current->forward;
            count++;
        }
    }
    return count;
}

// Want to say thanks to Diego for help with this. Was struggling a lot and he showed me his code and how it worked, which is why it looks so similar.
bool LinkedList::clearList()
{
    bool success = false;
    Node *current = head;
    if (current != NULL)
    {
        while (current->forward != NULL)
        {
            Node *next = current->forward;
            delete current;
            current = next;
        }
        head = NULL;
        success = true;
    }
    return success;
}

bool LinkedList::idExists(int id)
{
    Node *current = head;
    if (findId(id, &current) == true)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

//private member functions
void LinkedList::addHead(Node* temp)
{
    head->back = temp;
    temp->forward = head;
    head = temp;
}

void LinkedList::addMiddle(Node* current, Node* temp)
{
    temp->forward = current;
    temp->back = current->back;
    current->back = temp;
    temp->back->forward = temp;
}

void LinkedList::addTail(Node* current, Node* temp)
{
    current->forward = temp;
    temp->back = current;
}

void LinkedList::delHead(Node *current)
{
    current->forward->back = NULL;
    head = current->forward;
    delete current;
}

void LinkedList::delMiddle(Node *current)
{
    current->forward->back = current->back;
    current->back->forward = current->forward;
    delete current;
}

void LinkedList::delTail(Node *current)
{
    current->back->forward = NULL;
    delete current;
}

bool LinkedList::isDuplicate(int id)
{
    Node *current = head;
    while (current->forward != NULL)
    {
        if (current->forward->data.id == id)
        {
            return true;
        }
        current = current->forward;
    }
    return false;
}

bool LinkedList::findId(int id, Node **current)
{
    while (*current != NULL)
    {
        if (id == (*current)->data.id)
        {
            return true;
        }
        else
        {
            *current = (*current)->forward;
        }
    }    
    return false;
}
