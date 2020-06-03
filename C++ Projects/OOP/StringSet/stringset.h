#include<iostream>
#include <vector>

#ifndef STRINGSET_H
#define STRINGSET_H
class StringSet{
    private:
        std::string items;
        int vec_size;
        int arr_size;
        std::string array1={};
        //vector String
        std::vector<std::string>set_str;

    public:
        // contructors
        StringSet() :vec_size(0){};
        StringSet(const std::string array1[],int size ); 
        StringSet(const std::vector<std::string>setTwo):set_str(setTwo){};
        //getter member unction
        std::string getItem (){return items;}
        int getVecSize (){return vec_size;}
        int getArrSIze() {return arr_size;}
        std::string getString (){return array1;}
        std::vector<std::string> getSet(){return set_str;}
        // member functions
        void add (const std::string & );
        void remove (const std::string &);
        void clear ();
        int getSize (); 
        void Union(StringSet &b);
        void intersect ( StringSet &);
        void print();
        void arr_print();
        void position_check (const std::string& );

};


#endif
