// Programmer : Luan Nguyen
// Course : Data Structure 
// Project: Car inventory
#include"ArrayList.h"
#include "Car.h"
#include <bits/stdc++.h>    // this for read file library
#include <sstream>          // this is stringstream to convert string to int
#include <fstream>          // this is for I/O file
using std::fstream;         // this is for I/O file 
using std::stringstream;    // convert string into int
bool ArrayList::id_Search(int id){
    // searching infos
    for (unsigned int i = 0; i < garage.size(); i++){
        if (garage[i].get_id()==id){
            cout << id << " has been found at  " 
                 << garage[i].get_make() << " " 
                 << garage[i].get_model()<< " "
                 << garage[i].get_color()<< " "
                 << endl;
            return true;
        }
    }
    return false;
}
bool ArrayList::color_Search (string color){ 
    // searching infos
    for (unsigned int i = 0; i < garage.size(); i++){
        if (garage[i].get_color()==color){
            cout << color << " has been found at  " 
                 << garage[i].get_make() << " " 
                 << garage[i].get_model()<< " "
                 << garage[i].get_id()<< " "
                 << endl;
            return true;
        }
    }
    return false;
}
bool ArrayList::make_Search (string make){ 
    // searching infos
    for (unsigned int i = 0; i < garage.size(); i++){
        if (garage[i].get_make()==make){
            cout << make << " has been found at  " 
                 << garage[i].get_id() << " " 
                 << garage[i].get_model()<< " "
                 << garage[i].get_color()<< " "
                 << endl;
            return true;
        }
    }
    return false;
}
bool ArrayList::model_Search (string model){ 
    // searching infos
    for (unsigned int i = 0; i < garage.size(); i++){
        if (garage[i].get_model()==model){
            cout << model << " has been found at" 
                 << garage[i].get_make() << " " 
                 << garage[i].get_id()<< " "
                 << garage[i].get_color()<< " "
                 << endl;
            return true;
        }
    }
    return false;
}
void ArrayList::add_Car (const Car b){
        //pa[size] = b;  // add new Car to the array
        garage.push_back(b);
        size +=1;      // keep tracking of the size
        updateFile(b); // update back the file 
}
void ArrayList::del_Car(int id_del){
    int index =0;  
    // Find the Id for Car delete=> locate its index and then push the left from it
    for (unsigned int i = 0; i < garage.size() ; i++){
        if (garage[i].get_id() == id_del){    // compare array in the list
         // we have the index of the Id Car need to delete as i
            index = i;
        }
    }
   /* 
    // push Car to the left and start from the index + 1 postion
        for (unsigned int i = index + 1 ; i < garage.size(); i++){
            garage[i-1] = garage[i];      // assign the swapping value 
        }*/
    garage.erase(garage.begin()+ index);
    size -=1; // size will be decremented
}
void ArrayList::print(){
        cout << " the list is "<<endl;
        /*
    for (int i = 0; i < size; i++){
        cout << pa[i].get_id()    << "  "   // show car infos
             << pa[i].get_make()  << "  "
             << pa[i].get_model() << "  "
             << pa[i].get_color() << "  " <<endl;
    }*/
    for (int i = 0 ; i  <size ; i++){
        cout << garage[i].get_id()    << "  "   // show car infos
             << garage[i].get_make()  << "  "
             << garage[i].get_model() << "  "
             << garage[i].get_color() << "  " <<endl;
    }
}
void ArrayList::get_inputFile(){
    // get input from files word by word
    fstream file;
    string word, filename;
    filename = "cars.data";
    file.open(filename.c_str());  //open file
    // all the below data used for tracking and save infos of Car
    int count = 0; // tracking loop to get infos
    string temp0,temp1, temp2, temp3;
    int track = 0; // tracking for build new Car object
    int id = 0; 
    int count_loop = 0; // tracking loop time of loop
    while (file >> word){
        string temp;
        temp = word;
        if (count == 0 ){
            temp0  = temp;
            stringstream geeks (temp0); // use Stringstream to convert string into int
            geeks >> id;   // assign it into int id
            count +=1;   // keep adding to it will come to next Car infos
            count_loop +=1;
        } else if (count == 1){
            temp1 = temp;
            count +=1;
            count_loop +=1;
        } else if (count == 2){
            temp2 = temp;
            count +=1;
            count_loop +=1;
        } else if (count ==3){
            temp3 = temp;
            if (track > capacity){ // limit size must smaller than capacity
                cout << " OVER "    << endl;
                exit(1);
            }else{
                Car temp_car (id, temp1, temp2, temp3);// creater new Car object
                //add_newMember(track, temp_car);   // add new car to the the list of CARS
                garage.push_back(temp_car);
                size+=1;
                track+=1;
            }
            count =0;
        }       
    }
    file.close(); 
}
void ArrayList::updateFile(const Car b){
    std::ofstream Output("cars.data",std::ios_base::app);  // this is used to append cars.data ==> will add more infos 
    //Output.open("cars.data");
    string temp1 = b.get_make();
    string temp2 = b.get_model();
    string temp3 = b.get_color();
    string temp0 = std::to_string (b.get_id());   // convert int into string
    string result = temp0 + "       " + temp1 +"        " +
       "        " + temp2 +"        "+ temp3;  // add all new Car infos into one line
    Output << endl; //  this will run to the end of file
    Output << result << endl; // add new line of car
    Output.close();
    return;    
}
// interfact function
void ArrayList::implementation(){
    cout << " Welcome to Luan garage !!  " << endl;
    cout << "Note: option by number only (NO character) -THANKS " <<endl;
    cout << " Please pick the option : "   << endl;
    cout << " 1. Search car based on Infos. " << endl;
    cout << " 2. Add new CAR (will be update to Luan garage and inventory list " << endl;
    cout << " 3. Delete Car " << endl;
    cout << " Other. exit "     << endl;
    int choice;
    std::cin >> choice;
    switch(choice){
        case 1:
            case1();
        case 2:
            case2();
        case 3:
            case3();
        default:
            cout << "Thanks for your time "<< endl;
            exit(1);        
    }    
}

void ArrayList::case2(){
    Car temp = ask_info();
    add_Car(temp);
    cout << " New list Car is :::: " << endl;
    cout << " It also is added to my inventory listing also "<< endl;
    cout << " new Car is " << temp.get_id() <<endl;
    print();
    cout << " Thanks for your action !!"<<endl;
    implementation();  // return main menu
}
void ArrayList::case1 (){
    cout << " You are in Search section :::" <<endl;
    cout << " please pick your choice :::"   <<endl;
    cout << "1. Search by Id "               <<endl;
    cout << "2. Search by Maker "            <<endl;
    cout << "3. Search by Model "            <<endl;
    cout << "4. Search by Color "               <<endl;
    cout << "Other. Return "                 <<endl;
    int choice;
    std::cin >> choice;
    
    switch(choice){
        case 1:
            case11();
        case 2:
            case12();
        case 3:
            case13();
        case 4:
            case14();
        default :
            implementation();            // return main menu
    }   
}
void ArrayList::case3(){
    int temp = get_idDel();
    del_Car(temp);       // delete car at index
    cout << temp << " has been delete from your car inventory" <<endl;
    cout << " New list Car is :::: " << endl;
    print();
    cout << " Thanks for your action !!"<<endl;
    implementation();   // return main menu
}
int ArrayList:: get_inputId(){
    cout << " PLease input your Search id " << endl;
    cout << " Note::: PLease number only  " << endl; 
    int choice;
    std::cin >>choice;
    try{
        if (choice <= 0){
            throw choice;
        } else {
            return choice; 
        }
     }   
     catch(int x){    // catch the wrong type id
        cout << " It is invalid input as" << x <<endl;
        cout << " PLease enter again ::::" << endl;
        get_inputId();       // use recursive function
     }
  return choice;   
} 

string ArrayList::get_inputStr(){
    cout << " PLease input your Search string with lower case " << endl;
    string choice;
    std::cin >>choice;
    return choice;   
} 
int ArrayList::get_idDel(){
    cout << " PLease input your delete id car in the array " << endl;
    cout << " Note number only PLease !! "<<endl;
    int choice;
    std::cin >>choice;
    while (!id_Search(choice)){   // looping until get the valid id
        cout << " It is invalid index as" << choice << endl;
        cout << " PLease enter again ::::" << endl;
        std::cin >> choice;
    }
    return choice;
}
void ArrayList::case11(){
    int temp = get_inputId(); // just get input
    if(id_Search(temp)){
        cout << temp << " has been found"<<endl;
    }else{
        cout << "sorry it does not match "<<endl;
    }
    case1();
}
void ArrayList::case12(){
    cout << "Car Maker Search mode " <<endl;
    string temp = get_inputStr();    // just get input
    if(make_Search(temp)){
        cout << temp<< " has been found"<<endl;
    } else{
        cout << "sorry it does not match "<<endl;
    }
    case1();
}
void ArrayList::case13(){
    cout << " Car Model _ Search mode "<<endl; 
    string temp = get_inputStr();    // just get input
    if(model_Search(temp)){
        cout << temp << " has been found"<<endl;
    } else{
        cout << "sorry it does not match "<<endl;
    }
    case1();
}
void ArrayList::case14(){
    cout << "Car Color Search Mode " <<endl;
    string temp = get_inputStr();   // just get input
    if(color_Search(temp)){
        cout << temp<< " has been found"<<endl;
    } else{
        cout << "sorry it does not match "<<endl;
    }
    case1();
}
// submember functions
bool ArrayList::_isFull(){
    return size == capacity;   // return when it is full
} 
void ArrayList::add_newMember(unsigned int index, Car temp){ 
    // Check the index valid or not
    if (index > garage.size() || index < 0){
        cout << index <<endl;
        std::cerr << " It is invalid index "<<endl;
        exit(1);
    }else{
        //pa[index] = temp;    // add new Car member
        garage.push_back(temp);
        size +=1;            // update size
    }
}
Car ArrayList::ask_info(){
    string temp1, temp2, temp3;
    int id ;
    // asking to get input Car informations
    cout << " Please input the id Car :: ";
    id = loop_asking();    // get the new Car a valid index
    cout << " PLease input the maker  :: ";
    std::cin >> temp1;
    cout << " PLease input the model  :: ";
    std::cin >> temp2;
    cout << " PLease input the color  :: ";
    std::cin >> temp3;
    Car temp(id, temp1, temp2, temp3);    // creat the object Car temp
    return temp;
}
// this below funtion to get new Car valid id 
int ArrayList :: loop_asking(){
    int id;
    cout << " please enter only number (interger) !! Thanks !!"<<endl;
    cout << " PLease enter your id car you want to add ::  ";
    std::cin >> id;
    while(id_Search(id)){            // if invalid id=>> keep looping to find the valid one
        cout << " It is invalid index !! PLease try again !!" <<endl;
        std::cin >> id;
    }
    return id;
}

int main (){
    ArrayList Luan = ArrayList();   // initialize the Luan ArrayList
    Luan.get_inputFile();           // update from the file to Luan
    Luan.print();
    // test

    // run the interface
    Luan.implementation();
    return 0;
}
