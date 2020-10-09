// Programmer : LUAN NGUYEN - Y383P299
// HW4 : EULER
// Purpose : add 50 digits number long to find sum by linked list

# include "Node.h"
int main(){
    Node *List = nullptr ;          // initialize the Node
    std::vector<int> Luan_list;     // use to rearrange the order
    add_routine(List);
     
    traverse(List);                 // this is orginal print as reverse way
    special_print(List, Luan_list); // User friendly print
    ten_print(List, Luan_list);     // ten digit user friendly print
    return 0;
}
