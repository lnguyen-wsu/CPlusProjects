// Book_Header  
#include <iostream>
#ifndef BOOK_H
#define BOOK_H
class Book {
    public:
        enum Genre {
            fiction = 1,nonfiction, periodical, biography,children
        };

        Book (std::string isbn, std::string au, std:: string titl, std::string _date ):
            ISBN(isbn), author(au), title(titl),date(_date), available(false){};
        //getter function
        std::string getIsbn(){return ISBN;}
        std::string getAuthor(){return author;}
        std::string getTitle(){return title;}
        bool changeAvailable () {return available= true;}
       // std::string getDate(){return date;}
       // std::string getType(){return type;}
        Genre getType(){return type;}
        // member funtion
        bool is_checkingout();
        void checking_out();
        void checking_in();
        //Book get_info();
    private:
        Book::Genre type;
        std::string ISBN, author, title, date;
        bool available;
};


#endif
