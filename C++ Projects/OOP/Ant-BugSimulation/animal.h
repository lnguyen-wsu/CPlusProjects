// Programmer Luan Nguyen
// Project: Ant-Bug simulation

#include <iostream>
#include "grid.h"
#ifndef ANIMAL_H
#define ANIMAL_H
class Animal {
    private:
        int starve;
        int step=0;
    public:
        // constructor
        Animal();
        Grid *grid;
        int x ;
        int y ; // location for each animal in the grid
        int get_Star (){return starve;}
        //member functions
       // virtual int move() = 0;
        //virtual void breed();
        //void animal_move(int x, int y);
};








#endif
