#include "library.h"
#include <ostream>
using std::cout;
using std::endl;
using std::ostream;
void library::add_books (const Book& a){
    list_books.push_back(a);
}
void library::add_users (const Patron& a){
    list_users.push_back(a);
}
// Non overloading operator to print the list of Books and Patrons
ostream& operator<<(ostream& os , Book&a){
    return os<< a.getIsbn() << endl
        << a.getTitle() << endl;
}
// Non Overloading opwerator to print the list of Transaction
ostream& operator<<(ostream&os, Transaction& a){
    return os<<a.get_pfee() << endl
            << a.getName() << endl;
}
// Non oerloading operator to print name in list_Patrons still
ostream& operator<<(ostream& os , Patron&a){
    return os<< a.getName() << endl
        << a.getCard() << endl;
}
// member function for print of Books and Patrons
void library::books_print(){
    for (auto i = list_books.begin(); i!= list_books.end(); i++ ) {
        cout << *i << endl;
    }
}
void library::users_print(){
    for (auto i = list_users.begin(); i != list_users.end(); i++) {
        cout << *i << endl ;
    }
}
// member to check out in the library by compare Card number of Patron 
// and Book ISBN
bool library::book_checkOut(std::string a, std::string b){
    std::string bookCheck, userCheck;
    for (unsigned int i = 0; i < list_books.size(); i++){
           for (unsigned int j = 0; j< list_users.size(); j++){
               bookCheck = list_books[i].getIsbn();
               userCheck = list_users[j].getCard();
               if (bookCheck== a && userCheck == b){
                   return true;
               }
           } 
    }
    return false;
}
// member function for book_check out and check any one still
// own money and send error if they do
void library::book_check (Book &a,Patron&b, std::string c, std::string d){
   if(book_checkOut(c,d)){
        a.changeAvailable();
        exit(3);   
   }else{
        err_print();
        cout << " This is real search for checking out " << endl;
        ownFee_users();
   }
}
// member function for checking Patron fee
void library::fee_check(Patron&a){
   if(a.getFee() > 0){
       cout<< "Sorry, this Patron still own the money !!"<<endl;
   } 
}
// error print function
void library::err_print(){
    cout<< " Sorry, infos are not match !!"<< endl;
    cout << " It  is testing for errors window "<< endl;

}
// Member function for tracking fee_paid for Transaction and then update 
// to the list of transaction
void library::fee_paid (Transaction &a, Book&b, Patron&c, std::string d, std::string e){
    if(book_checkOut(d,e)) {
            a.getName()= d;
            list_trans.push_back(a);
    }
}
// list of print out transaction
void library::trans_print(Patron &a){
    for (auto i = list_trans.begin(); i != list_trans.end(); i++){
        cout << *i << endl;
    }
    cout<<a.getName() << endl;
}
// member function for checking if any one still owned f
// fee
std::string library :: ownFee_users(){
    std::string name;
    double fee=0;
    for (unsigned i =0; i < list_users.size(); i ++){
        fee= list_users[i].getFee();
        name = list_users[i].getName();
        if (fee > 0 ){
            cout << name << endl;
            return name;
        }
    }
    return " ";
    
}
// return vector for any one still owned money
std::vector<std::string>f(library &a){
    std::string name1;
    std::vector<std::string> owned_name;
    while (true){
        name1=a.ownFee_users();
        owned_name.push_back(name1);
    }
    
    return owned_name;
}
// Mmeber print out owned money;
void library::owned_print(){
    double fee = 0;
    std::string name;
    for (unsigned i = 0; i < list_users.size(); i++){
        fee = list_users[i].getFee();
        name = list_users[i].getName();
        if (fee > 0){
        cout << name << endl;
        }
    }
}
