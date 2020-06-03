//Programmer: Luan Nguyen -Y383p299
//Project:Template testing

#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
struct item {
    private:
        int size1;
    public:
        std::vector<string>name = {"hulk", "teddy", "bear"};
        std::vector<string>Id = {"102h", "1234","ab13"};
        std::vector<int>ages = {10,20,30};
};
template<class T>
T checking(const std::vector<T>&,const T);
template<class T>
T check_type (const std::vector<T> &, const T);
int main(){
    cout<<"This is only for testing purpose ::: "<<endl;
    item trial; // build object from struct item
    // testing time 
    // checking hulk name ==>> yes it is found
    string check ="hulk";
    cout<< check<< "has in the list or not ??" << endl;
    
    cout<<"The answer is "
        << checking(trial.name,check) <<endl;
    if (checking(trial.name, check)==check){
        cout<<"Yes, it is the list"<<endl;
    }else{
        cout<<"sorry, it is not there"<<endl;
    }
    // testing with not found result=> no it is not found
    string check1 = "salina";
    cout<< check1 << "has in the list or not ??"<<endl;
    cout << "The answer is "
        << checking(trial.name, check1)<<endl;
    string answer ="-1";
    if (checking(trial.name, check1)==answer){
        cout<<"sorry this one is not on the list"<<endl;
    }
    // testing with integer ==> yes case
    int number = 10;
    cout<< number << " has in the list or not ??"<<endl;
    cout << "The answer is ";
    if (check_type(trial.ages, number) == number){
        cout<<"Yes, and it is "
            <<check_type(trial.ages, number)<<endl;
    }
    // testing with interger ==> no case
    int number2 = 55;
    cout<< number2 << " has in the list or not ??"<<endl;
    cout << "The answer is " << check_type(trial.ages, number2)<<endl;
    if (check_type(trial.ages,number2) == number2){
        cout<<"Yes, and it is "
            <<check_type(trial.ages, number)<<endl;
    }else {
        cout<< " SORRY,IT IS NOT THERE " <<endl;
    }
    

    return 0;
}
// member function for testing template 
template<class T>
T checking(const std::vector<T>&list,const T variable ){
    T temp = "-1"; // return -1 if not found
    T none = "."; 
    for  (auto &i :list ) {
        if (i == variable){
            return i;
        }
        
        else{
            return temp;
        }
    }
    return none;
}
// just another version for template testing 
template<class T>
T check_type( const std::vector<T> &list,const T variable ){
    signed temp = -1;// return -1 if not found
    int none = 0;
    for  (auto &i :list ) {
        if (i == variable){
            return i;
        }
        else{
            return temp;
        }
    }
    return none;
}

