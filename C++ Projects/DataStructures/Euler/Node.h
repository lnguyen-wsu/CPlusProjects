// Programmer : LUAN NGUYEN - Y383P299
// HW4 : EULER
// Purpose : add 50 digits number long to find sum by linked list

#include <iostream>
#include <string>
#include <sstream>   // this is for convert string to int
#include <bits/stdc++.h>  // this is for read file
#include <vector>
using std::string;
using std::cout;
using std::endl;
#ifndef NODE_H
#define NODE_H
struct Node {
    public:
        // these variable of LL will be used as tool to capture digits
        Node *next;
        int data;
        // constructor
        Node():next(nullptr), data(0){};
        // passing parameter Constructor
        Node(int num):next(nullptr),data(num){};
};
// member functions 
void add_at_head(Node*& head, int num);
void add_at_tail(Node*& tail, int num);
bool search (Node*& , int );
void set (Node*& , string);
void del (Node*& , int);
void traverse (Node*& );
// member funtions to user friendly print 
void special_print(Node*&, std::vector<int>& );
void ten_print (Node*& , std::vector<int>& );
// Sub member function
void set_later(Node*& , string);
void add_routine (Node*& );






#endif
