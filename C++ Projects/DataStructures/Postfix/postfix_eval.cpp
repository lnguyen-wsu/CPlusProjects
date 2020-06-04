// Programmer : Luan Nguyen - Y383P299
// HW 5 : Postfix 
// Detail : Postfix operation Evaluation  by stack
// NOte for myself : consider each operator "+ / - *" as function to activate to member function to
// do the operation after put numbers into the stack

#include <iostream>
#include <stdio.h>                         // get input  and stoi convert from string[i] to int  
#include <string>
#include <stack>
#include <sstream>                         // to use sstream
#include <vector>           
#include <locale>                          // used for isdigit()#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stack;
using std::vector;

// member function 
bool _isValid (const string );                          // check validity of the Postfix expression
int Postfix_Eval (const string);                        // get the answer for the valid Postfix expression
bool is_number(const std::string& s); 
vector<string> split (const string &, char );           // split the input from string input
void intoPo ( string&);
void paren_case (vector <string> &,stack<string>&, string&,unsigned int);
// sub member functions
void Sub_prepare(stack<string>,stack<string>& );        // sub member functions for get input string
int each_Case(const int , const int, const char );      // do the operations - each case +-/*
bool case_check (const int , const int , const char);   // check if any invalid operation
int each_Operation(stack<int>&, char a);                // if each case is valid, do the operation
bool check_Operand(stack<int>&, char );                 // check if stack or operation is valid or not ??
bool basic_Check(const string);                         // check with the two digit from string => it must be numbers to qualify the condition
int convert (string a);                                 // convert each string[i] into digit
string get_input();                                    // get input from the user
void interface();                                       // The implemention of whole code
void inter_support();                                   // member support for interface()

// main function
int main(){
    interface();                                // implementing the Postfix expression
    //convert part
    /*
	std::string expr;
	std::cout << "Enter infix expression: ";
    //cout << expr.length() <<endl;
	std::getline(std::cin, expr);
	std::vector<std::string> words = split(expr, ' ');
    cout << expr.length() <<endl;
    int count = 0;
	for (auto word : words) {
		std::cout << ": " << word << '\t' << "is_number: " << is_number(word) << std::endl;
        cout <<count <<endl; 
        count ++;
	}*/
   // string result;
    //intoPo(result);
    //cout<< " anwers"<<endl;
    //cout << result;
    return 0;
}

bool _isValid( const string a){
    if (!basic_Check(a)){                       // check if the fist 2 string[i] is number or not
        return false;
    }
    unsigned int index = 0;
    stack<int>st; 
    while (index < a.size() && index % 2 == 0 ){   // set the condition for loop running 
        if (isdigit(a[index])){
            int temp = a[index] - '0';             // convert each string[i]  into int
            st.push(temp);                        // add to stack
        }
        else{
            char sign = a[index];                 // now it is sign operator
            int temp = each_Operation(st,sign);   // apply to each case of operator
            st.push(temp);                       // push the result back to the stack
        } 
        index+=2;                               // increment 2 because as Input string will have space between each letter(or string[i]) as requested instruction
    }
    st.pop();                                   // this is the one store result => pop it out => size must equal 0 .if not, invalid Postfix
    if (st.size() > 0){
        return false;
    }
    return true;
}
// this below function algorithm will be the same with the previous bool, but it will return value
// as result 
int Postfix_Eval(const string a){
    if (!_isValid(a)){
        std::cerr << " It is invalid Postfix Evaluation "<<endl;
        exit(1);
    }
    stack<int>st;
    unsigned int index = 0;
    while (index < a.size() && index % 2 == 0 ){
        if (isdigit(a[index])){
            int temp = a[index] - '0';
            st.push(temp);
        }
        else{
            char sign = a[index];
            int temp = each_Operation(st,sign);
            st.push(temp);
        } 
        index+=2;      
    }
    cout << " The final answer is ::" <<endl;
    return st.top();                        
}
vector<string>split (const string& a, char delimiter ){         // split string function which professor recommended => But i did not use this function
    vector<string>tokens;
    string token;
    std::istringstream tokenStream(a);                          // used sstream
    while (std::getline(tokenStream, token, delimiter)){         // check each line condition 
        tokens.push_back(token);                                // split then add the vector  
    }
    return tokens;
}
bool is_number(const std::string& s)
{
	return !s.empty() 
		&& std::find_if(s.begin(), 
						s.end(), 
						[](char c) { return !std::isdigit(c); }) == s.end();
}

void intoPo( string& result){
    stack<string>list_sign;
    //string result;
	std::string expr;
	std::cout << "Enter infix expression: ";
	std::getline(std::cin, expr);
	std::vector<std::string> words = split(expr, ' ');
    int count = 0;
    
	for (auto word : words) {
		std::cout << ": " << word << '\t' << "is_number: " << is_number(word) << std::endl; 
        cout << count <<endl;
	}
    //cout << words.size();
    int counter = 0;
    int first = 0;
    for (unsigned int i = 0; i < words.size(); i++){
        if (is_number(words[i])){
            if (first == 0){
                result = words[i];
                first++;
            }
            else{
                result = result + " " + words[i];
                // check the stack size
                if (list_sign.size() == 2){
                    while (list_sign.size()!=0){
                        result = result + " " + list_sign.top();
                        list_sign.pop();
                    }
                } 
                //first = first + 1;
            }
        
        }
        /*
        else{
            if (words[i]!="(" && counter == 0){
                //result = result + " " + list_sign.top();
                list_sign.push(words[i]);
                counter = 1;
            }else if ((words[i]!="("&& counter ==1) && words[i] == "*"){
                result = result + " " + list_sign.top();
                list_sign.pop();
                list_sign.push(words[i]);
                counter = 0;
            }//else {
                //paren_case(words,list_sign, expr, i);
            //}
        }*/
        else{
            if (words[i]!="(" && counter == 0){
                //result = result + " " + list_sign.top();
                list_sign.push(words[i]);
                counter = 1;
                cout << " check stack3" <<endl;
                for (unsigned int i = 0 ; i < list_sign.size() ;i ++ ){
                    cout << list_sign.top() << " ";
                    list_sign.pop();
                }
                cout << " end " <<endl;
            }
            
            else if ((list_sign.top()== "+" || list_sign.top()=="-") 
                    && (words[i]=="*" || words[i] == "/") ){
                list_sign.push(words[i]);
                cout << " check stack" <<endl;
                for (unsigned int i = 0 ; i < list_sign.size() ;i ++ ){
                    cout << list_sign.top() << " ";
                    list_sign.pop();
                }
                cout << " end " <<endl;
            } 
            else if ((list_sign.top()== "*" || list_sign.top()=="/ ") 
                    && (words[i]=="+" || words[i] == "-") ){
                result = result + " " + list_sign.top();
                list_sign.pop();
                list_sign.push(words[i]);
                cout << " start 2" <<endl;
                for (unsigned int i = 0 ; i < list_sign.size() ;i ++ ){
                    cout << list_sign.top() << " ";
                    list_sign.pop();
                }
                cout << " end " <<endl;
            } 
        }
    }
    
}

void paren_case (vector<string>&expr,stack<string>&a, string& b, unsigned int index){
    //int size = b.length();
    for (unsigned int i = index + 1 ; i < expr.size(); i++ ){
        if (!is_number(expr[i]) && expr[i]!= ")"){
            a.push(expr[i]);
        }else if (is_number(expr[i])){
            b = b + " " + expr[i];
        }else{
            while(i!= index){
                b = b + " " + a.top();
                a.pop();
                i = i - 1;
            }
            break;
        }
    }    
}

int each_Case(const int a, const int b , const char c){
    if (!case_check(a,b,c)){
        std::cerr<< " it is invalid operand as denomiator as 0 with /" <<endl;
        exit(1);                                      // end program immediately
    }
    if (c == '+'){
        return a+b;
    }
    else if (c=='-'){
        return a-b;
    }
    else if (c == '*'){
        return a*b;
    }else if (c == '/' && b !=0){
        float temp ;
        temp = static_cast<float>(a);
        temp = temp/b;
        return temp;
    }    
    std::cerr<< " It is invalid PostFix Expression !!! " <<endl;            // other cases beside these above cases will be invalid
    exit(1);
    return -1;                              // this is wrong or error for operands and it will be never called out
}
bool case_check(const int a, const int b, const char c){                    // check each signed operators
    if ((b == 0 && c == '/')|| c != '+' || c!='*' || c != '-' ) {
        return true;                         
    }
    return false;
}

int each_Operation(stack<int>&st , char a){                             // Do each operation 
    if (st.size() < 2){
        std::cerr << " Invalid Postfix order " << endl;         
        exit(1);
    }
    int temp1 = st.top();                                               // get value from top of stack 
    st.pop();                                                           // remove it
    int temp2 = st.top();                                               // keep doing it
    st.pop();                                                           // remove it
    //cout <<st.size() <<endl;
    int result = each_Case(temp2, temp1, a);              // this order is important in the postfix as temp2  +/-* temp1
    return result;
}
bool check_Operand(stack <int>&st , char a){
    if (st.size() < 2){                                                 // this is important, to be able do operators => must have at least 2 numbers in the stack
        return false;
    }
    return true;
}
bool basic_Check(const string a){
    return (isdigit(a[0]) && isdigit(a[2]));                            // the first 2 string[i] must is number to be legal
}
int convert (string a){
    int temp = stoi(a);                                                 // convert from string to int
    return temp;    
}
string get_input(){
    string input;                               
    string result;
    vector<string>store;
    cout << " Note: input will have space between each number/sign" << endl;
    cout << " Please input your Postfix evaluation :::: " ;
    std::getline(cin,input);                                            // get the whole string from the line
    cout << "input is::" <<input <<endl;
    return input;
}
void interface(){
    cout << "Welcome to Postfix evaluation " <<endl;
    int choice;
    cout << " Do you want to do Evaluation ?? (1 as yes, other is no) :::::     " ;
    cin >> choice;
    while (choice ==1){
        switch(choice){
            case 1:
                cin.ignore();                                           // this is important to clear buffer between cin and getline () => no conflict in shared data
                inter_support();                                        // do the algorithm to find the value
                break;
            default:
                cout << "Thanks for your time"<<endl;
                exit(0); 
        }
        cout << " Do you want again ( 1 to do -Other is exit) " <<endl;
        cin >>choice;
    }
}
void inter_support(){                                                   // Sub member to help implementation function
    string temp;
    temp = get_input();
    cout<<Postfix_Eval(temp) << endl;

}


















