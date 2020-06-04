// Programmer : LUAN NGUYEN - Y383P299
// HW: Round_Robin

#include"process.h"

Process::Process(){
    time_needed = 0;
}
Process::Process(string _id, int _arrival, int _time_needed){
    id = _id;
    arrival_time = _arrival;
    time_needed = _time_needed;
}
Process::Process(const Process& temp){
    id = temp.id;
    arrival_time = temp.arrival_time;
    time_needed = temp.time_needed;
    finished_time = temp.finished_time;
}
Process &Process::operator= (const Process &temp){
    
    this->id = temp.id;
    this->arrival_time = temp.arrival_time;
    this->time_needed = temp.time_needed;
    this->finished_time = temp.finished_time;
    return *this;
}


int Process::get_arrival()const { 
    return arrival_time;
}

int Process::get_timeN() const {
    return time_needed;
}

int Process::get_finishedT () const {
    return finished_time;
}

string Process::get_id () {
    return id;
}
void Process:: set_arrival(int temp){
    arrival_time-=temp;
 }
void Process::set_timeN(int temp){
    time_needed -= temp;
} 


/*
int main(){
    Process Luan ("id",1,20);


    return 0;
}*/
