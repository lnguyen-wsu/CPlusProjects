// Programmer : Luan Nguyen - Y383P299  
// Course : Data Structure
// Hw: Huffman

#include<iostream>
#include "node.h"
#include <vector>
#include <bits/stdc++.h>            // used to find min_element
using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace std;

// some of the below functions are useless but still be kept because for future references
void insert(Nodeptr &head, int val, char letter){
    if (!head){
        head = new Node(val, letter);
        return;
    } 
    if (head->freq < val)
        insert(head->right, val,letter);
    else if (head-> freq > val)
        insert(head->left, val, letter);
}
void insert_help(Nodeptr &head, vector<Node>whole){
    for (unsigned int i = 0; i < whole.size(); i++){
        insert(head,whole[i].freq, whole[i].letter);
    }
}
// Huffman tree build function 
void tree_build(Nodeptr& head,vector<Nodeptr>list_nodes){
    // build the priority queue to store the Objects => get the min object out each time
    std::priority_queue < Nodeptr, vector <Nodeptr>, Get_min > my_list;
    for(unsigned int i = 0; i < list_nodes.size(); i++){
        my_list.push(new Node (list_nodes[i]->freq, list_nodes[i]->letter));
    }
    while(my_list.size()!=1){
        Nodeptr left = my_list.top();
        my_list.pop();
        Nodeptr right = my_list.top();
        my_list.pop();

        head = new Node(left->freq + right->freq , '$');
        head->right = right;
        head->left = left;
        my_list.push(head);
    }
}
// these below function are just helper functions
Node smallest (vector<Node> &list){
    Node temp;
    temp = list[0];
    for(unsigned int i = 0; i < list.size() ; i++){
        if(temp.freq>list[i].freq){
            temp = list[i];
        }
    }
    return temp;
}
int find_smallest(vector<Node>&list){
    unsigned int temp = 0;
    for(unsigned int i = 0; i < list.size() ; i++){
        if(list[temp].freq>list[i].freq){
            temp = i;
        }
    }
    return temp;
}
bool compare(Node head, Node that){
    if (head.freq == that.freq && head.letter == that.letter)
        return true;
    return false;
}

void in_order(Nodeptr root){
    if(root){
        in_order(root->left);
        cout<<root->right->letter << " ";
        in_order(root->right);
    }
}
void arrange(vector<Node>&whole){
    for (unsigned int i = 1; i < whole.size(); i++){
        for(unsigned int j = i; j > 0 && whole[j].freq>whole[j-1].freq;--j){
            swap(whole[j],whole[j-1]);
        }
    }
}
void swap(Node&a , Node&b){
    Node temp;
    temp = a;
    a = b;
    b = temp;
}
// Print function of the huffman code
void print(Nodeptr head, string output, vector<Nodeptr>&list){
    if (!head){
        return;
    }
    if (head->letter !='$'){
        char a = head->letter;
        Nodeptr temp = new Node(a, output);
        list.push_back(temp);
    }
    print(head->left, output + "0", list);              // assign 0 on the left node
    print(head->right, output + "1", list);             // assign 1 on the right node
}
void fill_out(vector<Node*>& list, Nodeptr a){
    list.push_back(a);
}

// This section for testing purposed => void
/*
int main(){
    // trial
    vector<char>list1 = {'a','b','c','d' , 'e' ,'f'};
    vector<int>freq = { 29 ,9 , 50 ,13, 16 ,19};
    // build the vector of Nodes objects+
    vector <Node*> list_nodes;
    for (unsigned int i = 0; i < list1.size();i++){
        Nodeptr temp= new Node (freq[i],list1[i]);
        list_nodes.push_back(temp);
    }
    for (unsigned int i = 0; i < list1.size();i++){
        cout << list_nodes[i]->letter << "  " << list_nodes[i]->freq <<endl;
    }
    Nodeptr head = nullptr;
    vector<Nodeptr>result;
    //vector<Node>whole;
    //first_tree(head,list_nodes);
    //tree_build(head,list_nodes);
    tree_build(head,list_nodes);
    //arrange(whole);
    //insert_help(head, whole);
    //print(head, "", result);
    // try
    
    string output ="";
    print(head,output,result);
    for(unsigned int i = 0; i<result.size(); i++){
        cout << result[i]->letter << ":"<<result[i]->code <<endl;
    }
    return 0;
}*/
