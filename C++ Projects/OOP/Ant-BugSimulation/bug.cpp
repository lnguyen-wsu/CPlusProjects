// Programmer : Luan Nguyen
// Project: Ant-Bug Simulation
#include "bug.h"
// constructor
Bug::Bug(int po1, int po2, Grid *b){
    starve   = 0;
    move_bug = 0;
    grid=b;
    x= po1;
    y= po2;
    grid->setAnimal(x,y,'X');
}
// member function for eat function
void Bug::eat(){
    starve=0;
}
//member function fro each BUG move - eat
void Bug::eatMove(){
    if(grid->isAnt(x+1,y)) {
        grid->setAnimal(x,y,'.');
        grid->setAnimal(x+1, y, bbug);
        x++;
        move_bug++;
        eat();
    }    
    else if (grid->isAnt(x-1,y)){
        grid->setAnimal(x,y,'.');
        grid->setAnimal(x-1, y, bbug);
        x--;
        move_bug++;
        eat();
    }
    else if (grid->isAnt(x,y+1)){
        grid->setAnimal(x,y,'.');
        grid->setAnimal(x, y+1,bbug);
        y++;
        move_bug++;
        eat();
    }
    else if (grid->isAnt(x,y-1)){
        grid->setAnimal(x,y,'.');
        grid->setAnimal(x, y-1, bbug);
        y--;
        move_bug++;
        eat();
    }
    else {
        switch (rand()%4){
            case 0: 
                if (grid->isAval (x+1, y)){
                    grid->setAnimal(x+1, y, bbug);
                    grid->setAnimal(x, y, '.');
                    x++;                   
                }
                break;
            case 1: 
                if (grid->isAval (x-1, y)){
                    grid->setAnimal(x-1, y, bbug);
                    grid->setAnimal(x, y, '.');
                    x--;                    
                }
                break;
            case 2: 
                if (grid->isAval (x, y+1)){
                    grid->setAnimal(x, y+1, bbug);
                    grid->setAnimal(x, y, '.');
                    y++;                    
                }
                break;
            case 3: 
                if (grid->isAval (x, y-1)){
                    grid->setAnimal(x, y-1, bbug);
                    grid->setAnimal(x, y, '.');
                    y--;                    
                }
                break;
         }
        move_bug ++;
        starve++;
    }
}
void Bug::bug_breed(std::vector<Bug*>&a){
    if (move_bug == 7){//=> cuz start by O
        if (grid->isAval(x+1, y)){
            Bug*temp= new Bug(x+1, y, grid);
            a.push_back(temp);
        }
        else if (grid->isAval(x-1, y)){
            Bug*temp= new Bug(x-1, y, grid);
            a.push_back(temp);
        }
        else if (grid->isAval(x, y+1)){
            Bug*temp= new Bug(x, y+1, grid);
            a.push_back(temp);
        } 
        else if (grid->isAval(x, y-1)){
            Bug*temp= new Bug(x, y-1, grid);
            a.push_back(temp);
        } 
        else{
            move_bug = 0;
        }
    }
}
/*
int main(){
    Grid* b = new Grid();
    Bug *a =  new Bug(3,4,b);
    while(true){
    a->eatMove();
    a->grid->print();
    getchar();
    }
   
    if (a->check(3,4))
        std::cout <<"Yeah"<<std::endl;
    else
        std::cout<<"No"<<std::endl;
        
    return 0;
}*/
