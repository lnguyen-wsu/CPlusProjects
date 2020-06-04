// Programmer: Luan Nguyen
// Project: Dynamic Array


#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;

#ifndef DYNAMICARRAY_H
#include "dynamicArray.h"
#endif
void swap (int& x, int& y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}


void DynamicArray::fillArray(){
    for (int i = 0 ; i < size; i++){
        dyArray[i]= rand() % 50;
    }
}
void DynamicArray ::print (){
    cout << "List of array is ::  " << endl; 
    for (int i = 0; i <size ; i++){
        cout << dyArray[i]<<endl; // not sure this syntax in here
    }
}
void DynamicArray::InsertSort(){
    for (int i = 1; i < size ; i++){
        for (int j = i ; j > 0 && dyArray[j-1]>dyArray[j]; j--){
            swap(dyArray[j-1], dyArray[j]);
        }
    }
}
int main (){
    srand(time(NULL));
    DynamicArray Luan;
    Luan.fillArray();
    DynamicArray Wsu = Luan;
    Wsu.fillArray();
    //checK depp COPY constructor
    cout <<"Array of WSU "<< endl;
    Wsu.InsertSort();
    Wsu.print();
    //commpare
    cout <<"Orginal array "<<endl;
    Luan.InsertSort();
    Luan.print();
    return 0;
}
    
