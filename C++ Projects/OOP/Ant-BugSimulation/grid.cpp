// Programmer : Luan Nguyen
// Project : Ant- Bug Simulations
#include<iostream>
#include"grid.h"
using std::cout;
using std::endl;
 
// COnstructor
Grid::Grid (){
    for (short i = 0;i <=19;i++ ){
       for (short j =0; j<=19; j++){
           field[i][j]='.';
       } 
    }
}
//Member function for GRid
bool Grid::isAval(int x, int y) const {
    if (field[x][y]=='.' && _isInGrid(x,y)){
        return true;
    }   
    return false;
}
bool Grid::isAnt (int x, int y)const {
    if (field[x][y]=='O' && _isInGrid(x,y)){
        return true;
    }
    return false;
}
bool Grid::_isInGrid(int x, int y) const {
    if (x>=0 && x<=19 && y>=0 && y<=19){
        return true;
    }
    return false;
}
void Grid::print() const {
    cout<<"   A B C D E F G H I J K L M N O P Q R S T "<<endl;
    for (short i = 0; i<=19 ; i++){
        cout<< i% 10  << "  ";
        for (short j =0 ; j<=19 ;j++ ){
            cout<<field[i][j] << " "; 
        }
        cout<< endl;
    }

    int bugs =0;
    int ants = 0;
    for (short i =0; i<=19; i++){
        for (short j = 0; j<=19; j++){
            if (field[i][j] == 'X'){
                bugs++;
            }else if (field[i][j] =='O'){
                ants++;
            }
        }
    }
    cout<< "Total Bugs  "<< bugs << endl;
    cout<< "Total Ants  "<< ants <<endl;   

}
void Grid::setAnimal(int x,int y, char ch){
    if (_isInGrid(x,y)){
        field[x][y]=ch;
    }
return;    
}

// only for testing each class of Object
void Grid::ready (){ 
    for (short i = 0; i<=19 ; i++){
        for (short j =0 ; j<=19 ;j++ ){
            field[i][j]='.';
            cout<<field[i][j] << " "; 
        }
        cout<< endl;    
    }   
}
/*
int main (){
    Grid *grid = new Grid ();
    grid->ready();
    if (grid->_isInGrid(5,6))
        grid->setAnimal(5,6,'X');

    grid->print();
    return 0;
}*/
