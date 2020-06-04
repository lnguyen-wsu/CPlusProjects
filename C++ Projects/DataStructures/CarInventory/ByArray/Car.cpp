# include "Car.h"
Car::Car(){
    id = id;
    make= make;
    color = color;
    model = model;
}
Car::Car(int id1, string make1, string model1, string color1){
    id = id1;
    make = make1;
    model = model1;
    color = color1;
}
Car::Car( const Car &b){
    id = b.id;
    make = b.make;
    model = b.model;
    color = b.color;
}
Car& Car :: operator = (const Car& b){
    id = b.id;
    make = b.make;
    model = b.model;
    color = b.color;
    return *this;     // return Object
}
// this below section just for testing Car.cpp and Car.h => void
/*
int main (){

    Car Luan (56, "Honda","Accord", "WHite");
    //std::vector <Car > mine;
    Car list[30] ;
    list[1] = Luan;
    list[2] = Luan;
    list[3] = Luan;
    for (int i = 0; i < 15 ;i++){
        //Car *pa = new Car  (57, "HH","KK","GG");
        //list[i]=pa;
        //list[i] = pa;
    }
    cout << list[1].get_id() <<endl;
    cout << list[2].get_id() <<endl;

    cout << Luan.get_id() <<endl;
    return 0;
}*/
