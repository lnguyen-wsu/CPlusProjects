// Programmer: Luan Nguyen
// Project: Ant-Bug SImulation

#include "ant.h"
#include<vector>
Ant::Ant(int po1, int po2, Grid *c){
    move_ant = 0;
    x= po1;
    y= po2;
    grid = c;
    grid->setAnimal (x,y,'O');
}
/*
void Ant::animal_move(int x, int y){
    move_ant++;
}*/
//member function for moving ant
void Ant::ant_move(){                                                                       
switch(rand()%4){                                                                   
    case 0: if (grid->isAval(x+1,y)){ 
                grid->setAnimal(x,y,'.');                
                grid->setAnimal(x+1,y,aant);
                x++;                
                move_ant ++;                
            } else{
                move_ant ++;                                                            
            }
            break;            
                                                                                 
    case 1: if (grid->isAval(x-1,y)){                                         
                grid->setAnimal(x,y,'.');                
                grid->setAnimal(x-1,y,aant);
                x--;                
                move_ant ++;               
            }else{
                move_ant ++;                
            }
            break;            
    case 2: if (grid->isAval(x,y+1)){                                                                          
                grid->setAnimal(x,y,'.');                
                grid->setAnimal(x,y+1,aant);
                y++;                
                move_ant ++;               
                                                                         
            }else{
                move_ant ++;                
            }
            break;            
    case 3: if (grid->isAval(x,y-1)){                                         
                grid->setAnimal(x,y,'.');                
                grid->setAnimal(x,y-1,aant);
                y--;                
                move_ant ++;                
            }else{
                move_ant ++;                
            }
            break;                    
    }
}
void Ant::ant_breed(std::vector<Ant*>&a){
    if (move_ant ==3){
         if (grid->isAval(x+1, y)){
            Ant*temp= new Ant (x+1, y, grid);
            a.push_back(temp);                        
         }
         else if (grid->isAval(x-1, y)){
            Ant*temp= new Ant (x-1, y, grid);
            a.push_back(temp);                        
         }
         else if (grid->isAval(x, y+1)){
            Ant*temp= new Ant (x, y+1, grid);
            a.push_back(temp);                        
         }
         else if (grid->isAval(x, y-1)){
            Ant*temp= new Ant (x, y-1, grid);
            a.push_back(temp);                        
         }else{
             move_ant=0;
         }
    }
}
/*
int main(){
    Grid *c = new Grid ();
    std::vector<Ant*>list_ants;
    
    int count = 0;
    int comp1 = rand()%20;
    int comp2 = rand()%20;
    while(count <100){
            Ant* temp = new Ant(comp1, comp2, c);
            list_ants.push_back(temp);
    }
    c->print();
    
    Ant *a = new Ant (1,1,c);
    Ant *b = new Ant (2,2,c);
    list_ants.push_back (a);
    list_ants.push_back(b);
    c->print();
    while(true){
    a->ant_move();
    b->ant_move();
    b->ant_breed(list_ants);
    c->print();
    getchar();
    }
    return 0;
}*/
