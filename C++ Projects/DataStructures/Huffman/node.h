// Programmer : Luan Nguyen - Y383P299  
// Course : Data Structure
// Hw: Huffman
#include<iostream>
#include <vector>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::vector;
#ifndef NODE_H
#define NODE_H

struct Node{
    char letter;
    int freq;
    string code;
    Node* left;
    Node* right;
    // Constructor
    Node (){
        letter = ' ';
        freq = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    // this constructor use to store before encode
    Node (int num, char character){
        freq= num;
        letter=character;
        this->left=nullptr;
        this->right = nullptr;
    }
    // this constructor use to store after encode
    Node (char name, string temp){
        letter = name;
        code = temp;
    }
    // member functions
    Node& operator = (const Node&that){
        this->letter = that.letter;
        this -> freq = that.freq;
        this-> right = nullptr;
        this->left = nullptr;
        return *this;
    }
};
using Nodeptr = Node*;
// this struct are built to use for priority queue
struct Get_min {
    bool operator () (Nodeptr l, Nodeptr r){
        return (r->freq < l->freq);
    }
};
// member functions to build the huffman code
void insert(Nodeptr &head, int val, char);
void insert(Nodeptr &head, Node, Node);
void insert_help(Nodeptr &head, vector<Node>);
void first_tree(Nodeptr&head, vector<Node>&, vector<Node>&);
void tree_build(Nodeptr& head, vector<Node>&, vector<Node>&);
void tree_build(Nodeptr& head, vector<Nodeptr>);
Node smallest(vector<Node>&);
int find_smallest(vector<Node>&);
bool compare(Node head, Node that);
void arrange(vector<Node>&);
void swap(Node&, Node&);
void print(Nodeptr head, string, vector<Nodeptr>&);
void fill_out(vector<Node*>&, Nodeptr);
#endif
