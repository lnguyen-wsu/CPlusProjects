// Programmer :: Luan Nguyen - y383p299
// Course : Data Structure CS400
// Assignment 1st : QuadraticPrime 

#include <iostream>
#include <string>
#include <vector>
#include <cmath>  // to use absolute value of integer
using std::cout;
using std::cin;
using std::endl;
using std::vector;

//member functions
bool check_Prime (int); // functiont to check prime for any value integer
void forty_primes ();   // function to get 40 consecutive prime numbers
void eighty_primes();   // function to get 80 consecutive prime numbers
void find_Values (int& , int& , int& );  // find value of a, b and n to get the longest 
                                         //number of prime numbers for consecutive n values by passing reference parameter
void print (vector<int>);
int main (){
    // print 40 prime numbers by function
    cout << " this is 40 prime numbers "<< endl;
    forty_primes ();
    cout << " ______________________________" <<endl;
    cout << "This is 80 prime numbers "<<endl;
    eighty_primes();
    // find the value a and b
    cout << " Now to find value of a, b to get  the longest consecutive prime numbers " << endl;
    cout << " Please waiting for computer to compute value of a,b and n ..............." <<endl;
    int a,b,n =0;
    find_Values(a,b,n);
    cout << a << " is value of a "  << endl; 
    cout << b << " is value of b "  << endl;
    cout << n << " is value of consecutive n "  << endl;
    cout << n+1 << " is length of consecutive value of  n as [0,n]" << endl;
    cout << " list of prime number is " << endl;
    for (int i = 0; i <= 70 ; i++){
        int result = i*i + a*i + b;
        cout << result << "  ";
    }
    cout << endl;
    return 0;
}
// print function
void print (vector <int> list){
    cout << " list is " << endl;
    for (auto &i :list){
        cout << i <<endl;
    }
}
// check_Prime function
bool check_Prime (int number){
    if (number == 0 || number == 1)
        return false;
    if (number ==2)
        return true;
    else {
        for (int i = 2 ; i <abs (number); i++){  // absolute value integer was used by abs to check whether
                                                // negative or positive is prime of not
            if (abs(number) % i == 0)
                return false;
        }
    }
    return true;
}
// 40 prime numbers function
void forty_primes (){
    for (int i = 0 ; i <=39; i++){
        int prime = i*i + i + 41;
        if (check_Prime(prime))
            cout << prime << " " ;
    }
    cout << endl;
    cout << " is the prime numbers "<<endl;

}
// 80 prime numbers functions
void eighty_primes (){
    for (int i = 0 ; i <=79; i++){
        int prime = (i*i) - 79*i + 1601;
        if (check_Prime(prime)){
            if (prime >= 0)
                cout << prime << " " ;            
        }
    }
    cout << endl;
    cout << " is the prime numbers "<<endl;
}
void find_Values (int &a, int &b, int &n){        // we try to find the longest value of n and value a,b will be saved also.
    // loop to find each elements a,b and n
    int max_n  = 0; // assume value n = 0 before looping
    int result = 0; // assume value of function as n*n + an + b is equal 0 in beginning  
    for (int i = -999; i <= 999; i++){   // this is loop for value a
        for (int j = -1000; j <= 1000; j++){  // this is loop for value b
            for (int k = 0 ; ; k++){         // this is loop for consecutive of value n
                result = k*k + i*k + j;      // given function in the question
                if (check_Prime(result)){     // check function result
                    max_n = k;}
                if (check_Prime(result) && max_n > n){  // if max_n is greater than n ==> assign n = max_n
                    n = max_n;
                    a = i;                    // save value of a when we got value of n
                    b = j;                    // save value of b when we got value of n
                }
                else if (!check_Prime(result)){   // if any breaking point of n make result function is not prime 
                    max_n = 0;                    // assign again value of max_n and result
                    result = 0;
                    break;
                }                
            }
        }
    }
}









