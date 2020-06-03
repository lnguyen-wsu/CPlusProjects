//Programmer : Luan Nguyen
//Project : Class Library to control other class 
//as Book and Patrons
// file name : list_test.cpp
#include "library.h"
using std::cin;
using std::cout;
using std::endl;

int main (){
    cout << "Welcome to library WSU"<< endl;
    library one ("Wsu");
    // add Books to library
    cout << " This is list of Book "<< endl;
    Book a ("WSY1", "Robert Kioyaki","Rich Dad Poor Dad", "2012");
    Book b ("Y33P", "Luan Nguyen", "Joke", "Jan 1988");
    one.add_books(a);
    one.add_books(b);
    one.books_print();
    // add user to library
    cout << "This is list of students as Patrons"<< endl;
    Patron Jim ("Jim", "Ye22", 0 );
    Patron Harry ("Harry", "787", 20);
    one.add_users(Jim);
    one.add_users(Harry);
    one.users_print();
    //checkout BOOK and add to transaction
    //show the error if Patron still owned the money
    Transaction c;
    cout<< "Now come to checking Out book "<< endl;
    cout <<"....................."<< endl;
    std::string name = "Jim";
    std::string Isbn = "WSY1 ";
    cout << " Test to check random name if not match !! and then correct search"<< endl;
    one.book_check(a,Jim, name, Isbn );

    cout << "...................."<< endl;
    cout << " This is list of Book after checkout and list of users " << endl;
    one.books_print();
    one.users_print();
    cout << " ---------------------"<<endl;
    cout<< " This is transaction list"<< endl;  
    one.fee_paid (c,a,Jim,name, Isbn);
    one.trans_print(Jim);
    // checking on Patron about own_money
    cout << "----------------------"<< endl;
    cout << "List of owned money Patrons " << endl;
    // return vactor debt to show person owned money
    std::vector<std::string>debt;
    // display owned_name vector
    for ( auto i = debt.begin(); i != debt.end(); i++){
        cout << *i << endl;
    }
    one.owned_print();    

    return 0;
}
