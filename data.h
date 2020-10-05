/***********************************************************
Name: Cory Munselle
Assignment: 03
Purpose: has the two structs we work with in linkedlist.cpp/linkedlist.h
Notes: All credit goes to Prof. Katrompas
***********************************************************/

/* 
 * File: data.h
 * Author: Alex Katrompas
 * 
 * DO NOT MODIFY THIS FILE
 * LEAVE THIS COMMENT HEADER HERE
 */

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *forward;
    Node *back;
};

#endif /* DATA_H */

