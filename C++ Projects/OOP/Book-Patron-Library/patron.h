#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Patron {
    private:
        std::string name;
        std::string card_num;
        double own_fee;
    public:
        Patron (std::string a,std::
                string b, int c): name(a), card_num(b), own_fee (c) {};
        bool fee_testing ();
        // getter and setter
        std::string getName () const {return name;}
        std::string getCard () const {return card_num;}
        double getFee() {return own_fee;}
        void setName (std::string a) {name = a;}
        void setCard (std::string b) {card_num = b;}
         

};

