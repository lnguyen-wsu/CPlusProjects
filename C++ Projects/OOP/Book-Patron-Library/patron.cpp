// patron.cpp
#include"patron.h"
using std::cout;
using std::cin;
using std::endl;
bool Patron::fee_testing (){
    if (own_fee>0)
        return true;
    return false;          
}
/*
int main(){
    Patron one ("Luan","HHG", 50.7);
    cout<<one.getName() << endl;
    return 0;

}*/
