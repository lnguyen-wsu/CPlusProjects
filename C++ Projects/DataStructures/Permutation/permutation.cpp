// Programmer : Luan Nguyen - Y383P299
// Course : Data Structure
// HW : Permutation and backtracing

#include <iostream>

using std::cout;
using std::endl;
// member functions
bool isConsistent (int a[], int );               // check the condition for backtracking
//void swap (int&,int&);
void printPermutation (int a[], int);            // print function
void enumerate (int);                            // base backing funtion
void enumerate (int a[], int);                   // extended condition
int count = 1;                                   // global variable to keep track number of (1,2,3,4,5)
int main(){
    int a[5]={0};
    enumerate(a,0);
    return 0;
}
bool isConsistent(int a[], int size){
    for (int i = 0; i < size; i++){              // check the condition until the current size
            if (a[i]==a[size]){            
                return false; 
        }
    }
    return true;
}
void swap(int & a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void printPermutation(int a[], int size){       // print function
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
/*
void enumerate(int a ){
    int list[a]={0};                            // initialize the base case
    enumerate(list,0);                          // extend case start with k = 0 
}*/
void enumerate ( int a[], int k){
    int n = 5;                                  // max size of the array
    if (k==n){                                  // if backtracking has full array
        cout << "P#" << count++<< " ";
        printPermutation(a,k);                  // print
    }else{
        for (int i = 0; i < n ; i++){           // run loop
            a[k] = i+1;                         // assign the k index value
            if (isConsistent(a,k)){             // check the consistence
                enumerate(a,k+1);               // if yes, go to higher step with k+!
            }
        }
    }
}







// the area just for personal 
/*
void enumerate(){
    int list[5] ={1,2,3,4,5};
    enumerate(list,0,5);
}
void enumerate(int list[], int k, int size ){
    if(k==size){
        printPermutation(list, k);
    } else{
        for (int i = 0; i < size; i++){
            swap(list[k], list[size]);
            enumerate(list,k+1,5);
            swap(list[k], list[size]);
        }    
    }

}*/

