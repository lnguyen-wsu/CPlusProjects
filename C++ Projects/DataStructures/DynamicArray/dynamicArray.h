// Programmer: Luan Nguyen
// Project: Dynamic Array

#include <iostream>
using std::cout;
using std::cin;
using std::string;

class DynamicArray {
    private:
        int *dyArray;
        int size;

    public:
        // default contructor
        DynamicArray (){
            dyArray = new int[10];
            size = 10;
        }
        // parameterized contructor
        DynamicArray(int setSize){
            dyArray = new int[setSize];
            size = setSize;
        }
        // copy contructor => deep copy
        DynamicArray (const DynamicArray& X){
            dyArray = new int (*X.dyArray);// deep copy
            //dyArray = new int [X.size];
            //dyArray = X.dyArray; //=> this is shallow copy
            size = X.size;
        }
        // copy assignment operator
        DynamicArray & operator = (const DynamicArray& that){
            if (this != &that){
                delete [] dyArray;
                dyArray = new int [that.size];
                size = that.size;
            }
            return *this;
        }
        // destructor
        ~DynamicArray(){
            delete [] dyArray;
        }
        //member fucntions
        void fillArray();
        void print();
        void InsertSort();
        int getSize() const  {return size;};        
};
