// Programmer Luan Nguyen
// Project: Ant-Bug simulation
#include"animal.h"
#include"bug.h"
#include"ant.h"
#include"grid.h"
#include<vector>
#include<stdlib.h>
#include<time.h>

#ifndef SIM_H
#define SIM_H
//member function for empty grid
void emptyField(Grid *a);
// member function to initialize the random numbers
int rdom();
int rdom_move();
void start_garden (Grid *grid, std::vector<Ant*>&, std::vector<Bug*>&);
//helper function to clean up the trash in the vector BUGS and ANTs
void checking (std::vector<Bug*>&, std::vector<Ant*>&, Grid*);
// member function use for simulation one game
void bugEatMove(std::vector<Bug*>&);
void bugStarve(std::vector<Bug*>&);
void bugBreed (std::vector<Bug*>&);
void antMove(std::vector<Ant*>&);
void antBreed(std::vector<Ant*>&, Grid*);
void ant_clear(std::vector<Ant*>&);
// simulation function
void oneGame(std::vector<Bug*>&, std::vector<Ant*>&, Grid *);




#endif
