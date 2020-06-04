// Programmer : Luan Nguyen
// Course : Data Structure 
// HW2

#include "Car.h"
#include <vector>
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
class ArrayList{
    private :
        int size ;
        int capacity = 50;     
        Car *pa;    // pointer to Car

    public:
        // defautl constrcutor
        ArrayList (){
            size = 0;
            pa = new Car[capacity];  // initialize Array of Cars
        }
        // Constructor passing parameter 
        ArrayList (int size1){
            size = size1;
            pa = new Car [capacity];
        }
        // Main member functions
        int get_size () const {return size;}
        bool id_Search (int id)  ;
        bool color_Search (string color);
        bool make_Search (string make) ;
        bool model_Search (string model) ;
        void add_Car (const Car);
        void del_Car (int);
        void print ( );
        void get_inputFile();
        void updateFile(const Car);
        void implementation();      // include menu interface
        
        // sub member functions for checking
        bool _isFull();
        void add_newMember (int, Car);    // add for new Car member
        Car ask_info ();                  // get infos for Car
        int loop_asking();          // suport the interface menu
        void case2 ();              // support implementation function
        void case1 ();              // support implementation function
        void case3 ();
        int get_inputId();          // support for inplementation function
        string get_inputStr();      // support for implementation function
        int get_idDel();            // support function for implementattion function
        // member function to support Search function
        void case11();              // help about Car ID search
        void case12();              // help about Car Maker Search
        void case13();              // help about Car Model Search
        void case14();              // help about Car color Search    
        
};  
#endif
