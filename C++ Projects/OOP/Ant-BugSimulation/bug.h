// Programmer Luan Nguyen
// Project: Ant-Bug simulation
#include "animal.h"
#include<vector>
#ifndef BUG_H
#define BUG_H

class Bug:public Animal {
    private:
        int move_bug;
        int starve;
    public:
        char bbug = 'X';
        // constructors 
        Bug(int , int, Grid *); 
        // getter function
        int get_mov(){return move_bug;}
        int get_starve(){return starve;}
        // member function
        //void breed() override; --> same
        void eat();
        //void die();
        void eatMove();
        void bug_breed(std::vector<Bug*>&);
        // for monitor x, y;
        
     

};




#endif
