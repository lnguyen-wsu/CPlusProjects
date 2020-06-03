//Programmer: Luan Nguyen
//Object:: BUG_ANT simulation
//date: 04/28/19

#include "sim.h"
#include<stdio.h>
#include<termios.h>
#include<stdio.h>
using std::cout;
using std::cin;
using std::endl;

int main(){
    // Initialize vectors for bugs and ants  
    std::vector<Bug*>bugs_fam;
    std::vector<Ant*>ants_fam;
    srand(time(NULL));
    cout<<"Welcome to Mini Garden"<< endl;    
    // generate field
    Grid *grid = new Grid();
    emptyField(grid);
    start_garden(grid,ants_fam, bugs_fam );// initialize simulation
    grid->print();
    cout<<" ......................."<<endl;
    //next step --> real game to run simulation
    cout<< "Simulation starts  "<<endl;
    // simulation 
    while (true){
    oneGame(bugs_fam, ants_fam,grid);
    grid->print();
    getchar();
    cout<<"--------++++++++++-------+++++="<<endl;
    }
    return 0;
}
// helper function for initialize just for random numbers in the grid and moving
int rdom (){
    int temp = rand()%20;
    return temp;
}
int rdom_move(){
    int temp = rand()%4;
    return temp;
}
// clean up the field for simulation
void emptyField(Grid *a){
    for (short i =0; i<=19; i++){
        for (short j =0; j<=19; j++){
            a->setAnimal(i,j, '.');
        }
        cout<< endl;
    }
}
// member function for generate 100 ants and 5 bugs
void start_garden(Grid *a, std::vector<Ant*>&ants_fam, std::vector<Bug*>&bugs_fam){
    int count_ant = 0;
    int count_bug = 0; 
    while(count_ant <100){
        int comp1 = rdom();
        int comp2 = rdom();
        if (a->isAval(comp1,comp2)){
                Ant *temp = new Ant(comp1, comp2, a);
                ants_fam.push_back(temp);
                count_ant++;
        }
    }
//    std::cout << "ant(s) initialized." << std:: endl; 
    while (count_bug < 5){   
        int comp3 = rdom();
        int comp4 = rdom();
        if (a->isAval(comp3,comp4)){
                Bug *temp = new Bug(comp3, comp4, a);
                bugs_fam.push_back(temp);
                count_bug++;
        }
  //  std::cout << "Bug(s) initialized. " << std::endl;
                   
    }
}
// member funtion for bug eat and move
void bugEatMove(std::vector<Bug*>&a){
    for (unsigned i = 0; i <a.size(); i++  ){   // this is significant we have to start                                             // at 5 cuz before all is trash
                     a[i]->eatMove();
    }    
}
//member function for dying BUGS
void bugStarve(std::vector<Bug*>&a){     
    for (auto it = a.begin(); it != a.end(); ){      
            if ((*it)->get_starve()==3){
                (*it)->grid->setAnimal((*it)->x,(*it)->y,'.' );
                delete (*it); //free the memory
                it = a.erase(it);
            }
            else
            {
                ++it;
            }
    }    
}
//member function for bugs breeding
void bugBreed(std::vector<Bug*>&a){
    for (auto &i: a){
        i->bug_breed(a);
    }
}
// member function for Ant moving
void antMove(std::vector<Ant*>&a){
    for (auto &i : a){
            i->ant_move();
    }   
}    
//member function for Ant Breeding
void antBreed(std::vector<Ant*>&a, Grid*b){
    for (auto &i :a){
        i->ant_breed(a);        
    }   
}
//simulation for entire simulation
void oneGame(std::vector<Bug*>&a, std::vector<Ant*>&b, Grid*c){
    // simulation step by steps
    bugEatMove(a); // moving function for entire bugs
    antMove(b);  // moving for ants
    bugBreed(a);  // mating bugs season
    antBreed(b,c);//breeding ant
    ant_clear(b);  // clean up the died ants*/
    bugStarve(a) ; // killing hungry- bug
}
void ant_clear(std::vector<Ant*>&list){
    for (auto it = list.begin();it!=list.end();){
        if (!((*it)->grid->isAnt((*it)->x, (*it)->y))){
            delete (*it);
            it = list.erase(it);
        }
        else{
            ++it;
        }
    }
}

