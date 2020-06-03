#include "book.h"
using std::cout;
using std::endl;
using std::cin;
using std::ostream;

bool Book:: is_checkingout() {
    return available;
}
void Book::checking_out(){
    if (available ==true )
        available = false;
    else 
        cout<<" It is not available for checking out !!"
            <<"Book is not in the lib"<<endl;
}
void Book::checking_in(){
    if (available == false)
        available = true;
    else
        cout<<"It is not avaialble for checking in !!"
            << " Book is not in the lib now !! someOne is holding it"<<endl;
}
/*
ostream& operator<<(ostream& os, Book& b){
	return os << b.getTitle()  << endl 
				<< b.getAuthor() << endl
				<< b.getIsbn() << endl;
}*/

bool operator==( Book& b1,  Book& b2){
	return b1.getIsbn() == b2.getIsbn();
}

bool operator!=( Book& b1, Book& b2){
	return b1.getIsbn() != b2.getIsbn();
}
/*
int main(){
    Book a1 ("1134", "@@","%%","66","677");
    cout<< a1.getTitle() << endl;
    return 0;
}*/

            



