//library.h
#include <iostream>
#include "book.h"
#include "patron.h"
#include <vector>
struct Transaction{
    private: 
    double paid_fee;
    std:: string name;
    // getter function
    public:
   // Transaction (std::string person): name(name){} 
    double get_pfee() {return paid_fee;}
    std::string getName() {return name;}
};
class library {
    private:
        std::string name;        
    public:
        //contructor
        library (std::string temp): name(temp){};
        //getter
        std::string get_name(){return name;}
        // vector for Book, Patron and transactions, and debt list      
        std::vector<Book>list_books;
        std::vector<Patron>list_users;  
        std::vector<Transaction>list_trans; 
        std::vector<std::string>debt;
        //member function to add book,add Patron, checkout
        void add_books (const Book& a);
        void add_users (const Patron&a);
        bool book_checkOut (std::string ,std:: string );

        //bool feeOwn_check (const Patron& a);
        void book_check ( Book& ,Patron&, std::string, std::string );
        //member function for print out errors, book list, Patron list
        void err_print();
        void books_print ();
        void users_print (); 
        // member function for checking out
        // whether user still owned money
        void fee_check (Patron& a);
        void fee_paid ( Transaction&, Book&, Patron&,std:: string, std::string);
        // member function to print out transaction
        void trans_print(Patron&);
        // function return string type for name of who still own 
        // fee
        std::string ownFee_users();
        // vector return function for collect any owned money
        std::vector<std::string>f(library&);
        //member functiont to print out list of name 
        //still owned money
        void owned_print ();
         
};
