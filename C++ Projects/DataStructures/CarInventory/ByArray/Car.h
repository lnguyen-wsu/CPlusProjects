// Programmer : Luan Nguyen - Y383P299
// Course : Data Structure
// HW : Car and ArrayList

#include <iostream>
#include <vector>
using std::string;
using std::cout;
using std::endl; 

#ifndef CAR_H
#define CAR_H

class Car{
    private :
        int id;
        string make, model, color;
        

    public :
        // constructor
        Car();
        // passing Parameter Constructor
        Car(int , string ,string , string);
        // copy assignment operator 
        Car (const Car& );  
        Car& operator = (const Car&);
        // getter and setter function
        int  get_id() const {return id;}
        string get_make() const{ return make;}
        string get_model() const { return model;}
        string get_color() const { return color;}
        // member functions
    
};

#endif






