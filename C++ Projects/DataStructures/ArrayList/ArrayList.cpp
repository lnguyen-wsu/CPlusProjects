//Programmer : Luan Nguyen
//Data Structure : CS400
// Lab 2 : Array List

#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;
class ArrayList {
    private :   
        int *p;
        int capacity ;
        int count;

    public:
        // Constructor
        //ArrayList():p(new int[count]),count(10), capacity(20){};
        ArrayList (){
            p = new int[count];
            count = 10;
            capacity = 10;
        }
        // copy constructor
        ArrayList (const ArrayList &b){
            this ->capacity = b.capacity;
            this ->count = b.count;
            p = new int [count]; // deep copy constructor
            // copy all the element
            for (int i = 0; i< count ; i++){
                p[i]= b.p[i];
            }
        }
        // destructor
        ~ArrayList(){delete [] p;}
        //getter
        int get_capacity () const {return capacity; }
        // demonstration member function
        void fillArray();
        void print();
        void push_back(int num);
        
};

int main (){
    
    // demonstrate ArrayList
    srand(time(NULL));
    ArrayList luan ;
    luan.fillArray();
    luan.print();
    cout << "-----------------------"<< endl;
    luan.push_back(76);
    luan.print();

    

}
void ArrayList::push_back(int num){
    //this->p[count]=num;
    p[count]= num;
    count =+ 1;
    capacity +=1;
}
void ArrayList::fillArray(){
    for (int i = 0; i < count ; i++){
        //this->p[i]= rand() % 50;
        p[i]= rand() %50;
    }
}
void ArrayList::print(){
    for (int i = 0; i<count; i++){
        //cout << this->p[i]<<endl;
        cout << p[i]<<endl;
    }
}
































































































































