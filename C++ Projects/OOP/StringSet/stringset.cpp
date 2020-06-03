#include "stringset.h"
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
//contructors for calling array
StringSet::StringSet (const std::string array1 [], int size){
    array1 = array1;
    arr_size = size;    
}
// add member function
void StringSet::add (const std::string & a ){
    set_str.push_back(a);
}
// remove function
void StringSet::remove(const std::string& a){
    std::vector <std::string>::iterator it;
    it = std::find(set_str.begin(), set_str.end(),a);
    // remove by find string in the vector and then locate its position 
    int count = 0; // use to track location of search string
    for (unsigned int i = 0; i < set_str.size(); i++ ){
        if (*it == set_str[i]){
            set_str.erase(set_str.begin() + count); // locate position and remove it
        }
        count+=1;
    }
}
// int return type size function
int StringSet::getSize(){
    return set_str.size();
}
// clear function
void StringSet::clear(){
    set_str.clear();
}
// Union function
void StringSet::Union(StringSet &b){
    int count = 0;
    // now copy all vector b into a 
    for (unsigned i = 0; i < b.getSet().size(); i++ ){
        set_str.push_back(b.getSet()[i]);
    }
    // remove all duplicale in calling object a to clean it
    std::string temp ;
    for (unsigned i = 0; i < set_str.size();i++ ){
        for(unsigned j = i+1 ; j <set_str.size() - i ;j++  ){
            if (set_str[i]== set_str[j]){
                set_str.erase(set_str.begin() + count);
            }
        }
        count ++;
    }
}
// interset function
void StringSet::intersect ( StringSet &b){
    // merge b into main Stringset firstS
    
    for (unsigned i = 0; i < b.getSet().size(); i++ ){
        set_str.push_back(b.getSet()[i]);
    }
    // remove non_duplicated ones
    std::vector <std::string> temp;// vector temp contain the duplicated ones
    for (unsigned i = 0; i< set_str.size(); i++){
        for (unsigned j = i + 1; j < set_str.size() - i ; j++ ){
            if (set_str[i] == set_str[j]){
                temp.push_back(set_str[i]);// add to vector temp
            }
        }
    }
    /*
    std::vector <std::string> temp;// vector temp contain the duplicated ones

    for (unsigned i = 0; i<set_str.size(); i++){
        for (unsigned j = 0; j < b.getSet().size();j++ ){
            if (set_str[i]== b.getSet()[j]){
                    temp.push_back(set_str[i]);
            }
        }
    }*/
    //copy from temp to original vector a again
    set_str.clear(); // clear calling object 
    for (unsigned i = 0; i < temp.size(); i++){
        set_str.push_back(temp[i]); // copy from temp to calling object
    }
}
// print member function
void StringSet::print(){
    for (auto i = set_str.begin(); i != set_str.end(); i++){
        cout << *i << " " ;
    }
    cout << "Vector has size of " << set_str.size() << endl;
    cout << endl;
}
void StringSet::arr_print(){
    for (int i = 0;i < arr_size; i ++){
        cout << array1[i]<< " ";
    }
    cout<<endl;
    cout << "array size is "<< arr_size << endl;
}
