// 20190925_infix_2_postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::stack;
using std::vector;
bool is_number(const std::string& s); 
vector<string> split (const string &, char );           // split the input from string input
void intoPo ( string&);
void paren_case (vector <string> &,stack<string>&, string&,unsigned int);

// implementing function
std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
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
void intoPo(std:: string& result){
    stack<string>list_sign;
    list_sign.push("Luan");
    //string result;
	std::string expr;
	std::cout << "Enter infix expression: ";
	std::getline(std::cin, expr);
	std::vector<std::string> words = split(expr, ' ');
    int counter = 0;                 // tracking variable
    int first = 0;                   // tracking variable               
    for (unsigned int i = 0; i < words.size(); i++){
        // case : with number
        if (is_number(words[i])){
            if (first == 0){
                result = words[i];
                first++;
            }
            else{
                result += words[i];               
            }
        }
        // Operator case
        else{ 
            if(counter ==0){
                list_sign.push(words[i]);
                counter ++;
            }
            // case with  ( )
            else if (words[i] == "("){
                list_sign.push(words[i]);
                counter = 0;
            }
            else if (words[i] == ")"){
                while (list_sign.top() != "(" && list_sign.top()!="Luan" ){
                    result += list_sign.top();
                    list_sign.pop();
                }
                // now do with "("
                if (list_sign.top()=="("){
                    list_sign.pop();
                }
                if (list_sign.top() == "Luan"){
                    counter = 0;
                }
            }
            // Deal with Prcedent operators
            else if ((list_sign.top() == "+" || list_sign.top() == "-")
                    && (words[i]=="*" || words[i]=="/") ){               
                list_sign.push(words[i]);
            }
            else if ((list_sign.top() == "*" || list_sign.top() == "/")
                    && (words[i]=="+" || words[i]=="-") ){               
                result = result + " " +  list_sign.top();
                list_sign.pop();
                list_sign.push(words[i]);
            }
            else if ((list_sign.top() == "+" || list_sign.top() == "-")
                    && (words[i]=="+" || words[i]=="-") ){
                result = result + " " + list_sign.top();
                list_sign.pop();            
                list_sign.push(words[i]);
            }
            else if ((list_sign.top() == "*" || list_sign.top() == "/")
                    && (words[i]=="*" || words[i]=="/") ){
                result = result + " " + list_sign.top();
                list_sign.pop();            
                list_sign.push(words[i]);
            }
        }  
    }
    // Lastly, print all the left oprators in the stack
        while (list_sign.top()!="Luan"){
            result += list_sign.top();
            list_sign.pop();
        }
}
int main()
{
    string result;
    intoPo(result);
    cout <<result <<endl;  
    return 0;
}

