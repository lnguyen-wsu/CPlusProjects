// Programmer Luan Nguyen
// Project: Ant-Bug simulation
#include"animal.h"
#include<vector>
#ifndef ANT_H
#define ANT_H
class Ant:public Animal{
    private:
        int move_ant;
        bool alive= true;
    public:
        char aant = 'O';
        //constructor
        Ant(int po1, int po2, Grid *);
        //getter function
        int get_mov(){return move_ant;}
        void baby (){move_ant = 0;}
        //member functions
        //int move() override;
        //void animal_move (int x, int y);
        //member function for Ant
        void ant_move ();
        void ant_breed(std::vector<Ant*>&);
};




#endif
