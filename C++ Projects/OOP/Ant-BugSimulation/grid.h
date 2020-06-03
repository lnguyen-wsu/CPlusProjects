// Programmer Luan Nguyen
// Project: Ant-Bug simulation

#ifndef GRID_H
#define GRID_H
class Grid{
    private:
        char field [20][20];
    public:
        //constructor
        Grid();
        // member function for Grid 
        bool isAval(int x, int y ) const; // availabe spot
        bool isAnt (int x, int y) const;  // Check if Ant is there
        bool _isInGrid(int x, int y) const;  // check if within Grid or not
        void setAnimal (int x, int  y, char ch); // set BUg or ANt to Grid
        void print() const; 


        // testing
        void test (char field);
        void ready ();
};




#endif
