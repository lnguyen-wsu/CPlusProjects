// Programmer : Luan Nguyen - Y383P299  
// Course : Data Structure
// Hw: Huffman

#include <iostream>
#include <vector>
#include <fstream>      // this is for get input file
#include <string>
#include <map>          // this is for dictionary
#include <fstream>
#include"node.h"
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
// Part1 : GetInput part
// member function
void get_input(vector<char>&,vector<int>& );
void each_line(const string,vector<char>&, vector<int>&);
// sub functions for mainly encode the files
bool check (char, vector <char>);
int get_index(char, vector<char>);
// this below code use to pring the huffman code
void main_encode (vector<Node*>list, vector<Nodeptr>&last_list);  
// output the file
void file_output (vector<Nodeptr>);
string encode_process(vector<Nodeptr>, string);
string mapping(vector<Nodeptr>, char);

void save_scheme(vector<Nodeptr>list);              // huff.sch   (the encoding part after the tree .ex: e000 as letter a has 000)

int main(){
    cout << " This is HW7 Part "<<endl;
    vector<char>alphabet;
    vector<int> frequency;
    get_input(alphabet,frequency);
    // count the letter from the "alice.txt" about frequency of each character
    cout << " This is Beginning of counting frequency and letter of input file alice.txt :: " <<endl;
    for(unsigned int i = 0; i < alphabet.size(); i++){
        cout << alphabet[i] 
             << " ----->>>   "<< frequency[i] <<endl;
    }
    // these vector to store objects 
    vector <Nodeptr> list_nodes;                        // used to store before huffman
    vector <Nodeptr>last_list;                          // used to store after huffman
    for (unsigned int i = 0; i < alphabet.size();i++){
        Nodeptr temp= new Node (frequency[i],alphabet[i]);
        list_nodes.push_back(temp);
    }
    // now cope with the translation
    main_encode(list_nodes,last_list);
    // encode the file and output the new file 
    file_output(last_list);
    cout<< endl;



    save_scheme(last_list);                             // get the huff.sch 

    //...........................................................
    return 0;
}
// read file from alice.txt function
void get_input(vector<char>&chars, vector<int>&freq){
    // get the input file line by line
    string line;
    std::ifstream myfile("alice.txt");
    if (myfile.is_open()){
        while(getline(myfile,line)){
                each_line(line,chars,freq);
        }
        myfile.close();
    }
}
// Information collecting function 
void each_line(const string line, vector<char>&chars,vector<int>&freq){
    int size = line.length();
    for (int i = 0; i < size -1 ; i++){
        if(check(line[i],chars)){                       // if char exist in the vector or not
            chars.push_back(line[i]);
            freq.push_back(1);
        }
        else{                                           // if yes, add the frequency value
            freq[get_index(line[i],chars)]+=1;
        }
    }
    
}
bool check(char target, vector <char>list){
    for(unsigned int i = 0; i < list.size(); i++){
        if (list[i]==target)
            return false;
    }
    return true;
}
int get_index(char target,vector<char>list){ 
    for(unsigned int i = 0; i < list.size(); i++){
        if (list[i]==target)
            return i;
    }
    return -1;
}
// buidling the huffman tree
void main_encode (vector<Node*>list, vector<Nodeptr>&last){
    Nodeptr head = nullptr;
    tree_build(head, list);                                 // huffman tree build
    print(head,"",last);
    cout << " After HUFFMAN Encoding Process we have  :::  " << endl; 
    for(unsigned int i = 0; i<last.size(); i++){
        cout << last[i]->letter << "  -------- >>>>>>>>>>>  "<<last[i]->code <<endl;
    }
        
}

// these functions are supported to output the file alice.huff
void file_output(vector<Nodeptr>list){
    string line;
    std::ofstream my_file("alice.huff");
    std::ifstream input_file("alice.txt");
    if(input_file.is_open() && my_file.is_open()){
        while(getline(input_file, line)){
            string temp;
            temp = encode_process(list,line);
            my_file<<temp;
        }
        input_file.close();
        my_file.close();
    }
}
string encode_process(vector<Nodeptr>list, string line){
    string temp = "";
    for(unsigned int i = 0; i< line.length();i++){
        temp = temp + mapping(list,line[i]);
    }
    temp = temp + "\n";
    return temp;
}

string mapping(vector<Nodeptr>list, char line){
    string temp;
    for (unsigned int i = 0; i < list.size(); i++){
        if(list[i]->letter == line){
            temp = list[i]->code;
        }
    }
    return temp;
}


void save_scheme(vector<Nodeptr>list){
    std::ofstream my_file("huff.sch");
    if(my_file.is_open()){
        for(unsigned int i = 0; i < list.size(); i++){
            string line = "";
            char temp1 = ' ';
            string temp2="";
            temp1 = list[i]->letter;
            temp2 = list[i]->code;
            line  = temp1+temp2 + "\n";
            //cout << line <<endl;
            my_file<<line; 
        }
        my_file.close();
    }
    
} 
