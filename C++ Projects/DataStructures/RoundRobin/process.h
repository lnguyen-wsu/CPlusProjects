// Programmer : LUAN NGUYEN - Y383P299
// HW: Round_Robin

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Process{
    private:
        string id;
        int arrival_time;
        int time_needed;
        int finished_time;
    public:
        Process();
        Process(string _id, int _arrival, int _time_needed);
        Process (const Process& temp);
        Process &operator = (const Process&that);
        // getter and setter functions
        int get_arrival () const ;
        int get_timeN () const  ;
        int get_finishedT() const ;
        string get_id() ;

        void set_arrival(int );
        void set_timeN(int );
        void set_finishedT(int);

};



