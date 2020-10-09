// Programmer : LUAN NGUYEN - Y383P299
// HW4 : EULER
// Purpose : add 50 digits number long to find sum by linked list

#include"Node.h"

void add_at_head(Node*& head, int num){
    Node* temp = new Node(num);             // create a new Node with assigned data
    temp->next = head;                      // new Node pointing to head of the current Node
    head = temp;                            // assign passing Node = new Node temp
}
void add_at_tail(Node*& tail , int num){
    if(tail == nullptr){                    // if tail is empty
        add_at_head(tail, num);             // call the add_at_head function since it is empty  
        return;
    }
    Node* curr= tail;                       // assigne the curr Node
    while(curr->next != nullptr){           // run the loop to get to the last Node
        curr= curr-> next;                  // now it is pointing to last Node
    }
    //initiatlize new Node
    Node*temp = new Node(num);
    curr->next = temp;                      // assgint pointer point to new Node

}
bool Search (Node*& list, int num){
    for (Node* i = list; i!= nullptr; i++){         // run loop of linked list
        if (i->data == num){                        // if found
            return true;
        }
    }
    return false;
}
void set(Node*& list, string line){    // this function is only for the first step to fill infos before addition operation
    // now put it into Node
    for (auto rit = line.crbegin();rit!=line.crend();rit++){
        int temp = *rit-'0';           // convert the char into int by subtract 0 as 48
        add_at_tail(list,temp);        // set the new value into the linked list
    }
}
void del(Node*& head, int num){
    if (head==nullptr){                 // if linkled list is empty 
        return;
    }
    if (head->data ==num){              // if head-> data is matching with earch data 
        Node* temp = head;              // create a temp Linked list
        head= head->next;               // move head pointer to next
        delete temp;                    // delete the node
        return;
    }
    Node* prev = nullptr;              // now we do the rest of cases as assign previous NOde
    Node* curr = head;                 // curr Node == head LL
    while(curr!=nullptr && curr->data!=num){      // do search with condition
        prev = curr;                         
        curr = curr->next;                        
    } 
    // after the loop, we might found or the curr NOde is empty
    if (curr ==nullptr){               // if empty => return
        return;
    }
    prev->next = curr->next;           // FOUND Node with the same value Seach  => we move Nodes to next
    delete curr;                       // delete Node
}
void traverse (Node*& list){
    cout << "Number as reverse way " <<endl;
    for (Node* i =list; i!= nullptr; i = i-> next){    // scan all Nodes to cout infos
        cout << i-> data << " ";
    }
    cout << endl;
}
void set_later(Node*& list, string line){
    int count = 49;                               // because 50 digits long from string
    int track_add = 0;                            // it is carry 1 of addition if sum >10              
    int tracking = 0;
    for (Node*i = list; i!= nullptr; i= i-> next) {      // run loop
        int temp = line[count - tracking]-'0';           // convert each digits into int by minus char by 0 as 48
        if ((count - tracking ) < 0){                    // if negate order in string => assing equal 0
            temp = 0;
        }
        i->data = temp + i->data + track_add;            // addition at each Nodes with the track_add
        if (i->data >= 10){                              // if sum >=10
            i-> data = i->data -10;                      // just get one digit
            track_add = 1;                               // passing the carry 1
            if (i->next == nullptr){                     // this one is important => if the sum of last digits greater than 10 
                add_at_tail(list,1);   // expand new Node as soon as number oversize => put 1 into new Node
                return;
            }
        }
        else{
            track_add =0;                                // carry = 0
        }
        tracking +=1;
    }
}
void add_routine(Node*& list){
    std::fstream file;                 // open file with fstream
    string filename;
    string line;
    filename = "nums.txt";
    file.open(filename.c_str());
    int tracking = 0;
    while(file >> line){
        if (tracking ==0){
            set(list,line);          // assigned each digits into Linked list
        }else{  
            set_later(list,line);    // do the addition for each Nodes -LL
        }
        tracking+=1;
    }
    file.close();                   // close file
}
void special_print(Node*& list, std::vector<int>&my_list){
    for(Node* i = list; i!= nullptr; i= i->next){
        my_list.push_back(i->data);                         // used vector as the stack to manipulate the order
    }
    cout << " this is user friendly print for all numbers " << endl;
    // now print as casual way
    while (!my_list.empty()){                               // run the loop of vector to print out
        cout << my_list.back()<< " ";                       // the last of stact will be popped
        my_list.pop_back(); 
    }
    cout << endl;
}
void ten_print(Node*& list, std::vector<int>&my_list){
    for(Node* i = list; i!= nullptr; i= i->next){
        my_list.push_back(i->data);
    }
    cout << " this is user friendly print for only 10 digits " << endl;
    // now print as casual way
    int count = 0;
    while (!my_list.empty() && count <10){                  // run loop to get only 10 digits
        cout << my_list.back()<< " ";                       // pop it out to show
        my_list.pop_back(); 
        count+=1;
    }
    cout << endl;
}

