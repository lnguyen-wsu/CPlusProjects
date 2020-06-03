//Project: write down class about rational number with member function of adding
        //sub, ... and factor number also
//Name:  Luan Nguyen
//Date : 03/25th / 2019

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Rational {
        // factor function => to simplified any given rational number
        void factor();
        // private member variables
        int numerator;
        int denominator;        
    public:    
        // set constructor
        Rational ():numerator(1), denominator(1){factor();} 
        Rational (int a, int b): numerator(a), denominator(b){factor();};
        Rational (int a) : numerator(a), denominator(1){factor();}
        // getter and setter
        int get_num () {factor();return numerator;}
        int get_deno(){factor();return denominator;}
        void set_num (int a){a= numerator;factor();}
        void set_deno(int b){b= denominator;factor();}
        // member functions for add/sub/mul/div/compare(less)
        Rational mul(const Rational& );
        Rational div(const Rational& );
        Rational add(const Rational& );
        Rational sub(const Rational& );
        Rational less(const Rational&);
        // each Print member functions  
        void print();
        void print_add();
        void print_sub ();
        void print_mul ();
        void print_div ();
        void print_com ();
    
};
//Rational operator* (const Rational&, const Rational&);  

int main(){
    cout << "Welcome to the Rational function !!"<< endl;
    cout << " This is 1st rational number " << endl;
    Rational num1 (8,16);
    cout << " The 1st original rational number is  "<< 8 << " / "
         << 16 << endl;
    num1.print();
    cout << " This is 2nd rational number " << endl;
    Rational num2 (50,120);
    cout << " The 2nd original rational number is "<< 50 << " / "
         << 120 << endl;
    num2.print();
//Test for mulplication
    Rational test1;
    test1=num1.mul(num2);
    test1.print_mul();
//Test for division
    Rational test2;
    test2= num1.div(num2);
    test2.print_div();
// Test for addition
    Rational test3;
    test3 = num1.add(num2);
    test3.print_add();
//Test for subtraction
    Rational test4;
    test4 = num1.sub(num2);
    test4.print_sub(); 
//Test for comparision by return object
    Rational test5;
    test5 = num1.less(num2);
    test5.print_com();
       
    return 0;
}
// Member function subtraction => return object
Rational Rational :: sub (const Rational& a){
    Rational result;
    result.numerator = (numerator* a.denominator) - (a.numerator*denominator);
    result.denominator = a.denominator * denominator;
    result.factor(); // simplified the result
    return result; 
}
// Member function Addition => return object
Rational Rational :: add(const Rational& a){
    Rational result;
    result.denominator= a.denominator*denominator;
    result.numerator= (a.numerator*denominator) + (numerator*a.denominator);
    result.factor(); // simplified result
    return result;
}
// Member function Division => return object 
Rational Rational ::div(const Rational& a){
    Rational result;
    result.numerator = numerator * a.denominator;
    result.denominator= denominator * a.numerator;
    result.factor(); // simolified result
    return result; 
}
// Member function for Multiplication => return object
Rational Rational::mul(const Rational& a){
    Rational result;
    result.numerator= a. numerator * numerator;
    result.denominator = a.denominator * denominator;
    result.factor(); // simplified result
    return result;
}
// Member function for compare => return object
Rational Rational ::less (const Rational& a){
    Rational result;
    double x,y;
    // convert numerator and denominator into double => get x,y double type after division
    x= static_cast<double>(numerator)/denominator;
    y= static_cast <double>(a.numerator)/a.denominator;
    // compare x{represent for Object}, y{represent for passing object}. Then assign greater value
    // to object temp => return object 
    if (x > y){
        result.numerator = numerator;
        result.denominator = denominator;
        cout<< " The 1st one has.... ";
        }
    else{
        result.numerator = a.numerator;
        result.denominator = a.denominator;
        cout<< "The 2nd one has ...";
        }
    return result;        
}
// Print member functions for each type
void Rational :: print_add (){
    cout<< "the result of Additionn is " << numerator                                      
        << " / " << denominator <<endl;   
}
void Rational :: print_sub (){
    cout<< "the result of Subtraction is " << numerator
        << " / " << denominator <<endl;   
}
void Rational :: print_mul (){
    cout<< "the result of Multiplication is " << numerator 
        << " / " << denominator <<endl;
}
void Rational :: print_div (){
    cout<< "the result of Division is " << numerator
          << " / " << denominator <<endl;
}
void Rational :: print_com(){
    cout << " Simplified value as: " << numerator << " / "<< denominator
        << " is the greater one "<< endl;
}
void Rational :: print (){
    cout <<  "Your simplified rational is "<< numerator
        << " / " << denominator << endl;
}
void Rational::factor (){
    // PLease read this::: I find common factor between 2 rational numbers.
    int c = (numerator < denominator) ? numerator: denominator; // c will be less value of numerator or denominator
    // build loop for find common so i start by 2, cuz it cant be 0, and 1.
    for (int i = 2 ; i <= c; ++i){
        if ((numerator % i == 0 ) && (denominator % i == 0)){  
            // when you find common, divide numerator and denominator by found common i
                numerator = numerator / i;
                denominator = denominator /i ;
                i= 2; // reassign value of i to start loop again
        }         
    }
    // the rational will be the simplified version after the loop.
}


