//Progammer: Luan Nguyen
//Project : String set
#include "stringset.h"
using std::cout;
using std::endl;
int main (){
    // Test constructors 
    std::string arrayTest[3] = {"1","2", "3"};
    StringSet array1 (arrayTest,3); // array object
    array1.arr_print();
    StringSet empty(); // empty object
    
    // test for real object and demonstrate how they works  

    StringSet a({"1","2", "3", "4","a"});
    cout << "This is original object a "<<endl;
    a.print();  // test print function
    cout << "Demonstrate add function by add '99'"<< endl;
    a.add("99"); // add function
    cout<<"New object a"<<endl;
    a.print();
    cout << "Demonstrate remove string '99' and 'a' from StringSet object by remove '99' and 'a' " << endl;
    a.remove("99"); // test remove function
    a.remove ("a"); 
    a.print();
    // int size was put inside print function
    StringSet b ({"4","5", "6", "7"});
    cout << "This is 2nd stringset object b "<<endl;
    b.print();

    cout << "Let summarize object a and b has :: "<<endl;

    cout << "vector of a "<< endl;
    a.print();
    cout << "vector of b"<< endl;
    b.print();
    cout << " union of a and b"<< endl;
    a.Union(b); // union function
    a.print();
    cout<< "interset of a and b " << endl;
    a.intersect(b); // intersection function
    a.print();

    cout << "Demonstate how to clear StringSet" << endl;
    a.clear(); // test clear function
    b.clear();
    cout<< "vector a : " << endl;
    a.print();
    cout<< "vector b : "<<endl;
    b.print();
    return 0;
}
