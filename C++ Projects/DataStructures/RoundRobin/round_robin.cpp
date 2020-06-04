// Programmer : LUAN NGUYEN - Y383P299
// HW: Round_Robin

#include "process.h"
#include <vector>
#include<sstream>
#include<fstream>
#include <queue>
using std::queue;
using std::vector ;
// global variable
const int time_frame = 4;
// member functions
void auto_run (Process [], int & , int & ,int&,queue<Process>&   );
void sub_pushing (Process [], int &size, int&,int&, queue<Process>&);
void calculation (Process [], int& , int &count,int&, queue<Process>&);
//bool auto_checking(Process [], )
void print(Process&, int &count);

// sub_member function 
Process get_info (string _id, int _arrival, int _finished);
void get_input(Process [], int size);
vector <string>split (const string &s , char delimiter);
int str_To_Int(const string s );
int Search(Process [], int& , Process);
void del (Process [], int&, Process );


int main(){
    Process Luan[5];
    get_input(Luan, 5);
    /*
    for (int i = 0; i <5 ; i++){
        cout << Luan[i].get_id()      << " " 
             << Luan[i].get_arrival() << " "
             << Luan[i].get_timeN()   << " " << endl;
                
    }*/
    
    queue<Process>que;
    int count =0;                                // count for second
    int size =5 ;                                // tracking the size of the list of process => which used to copy to the queue   
    int tracking =0;                             // for tracking the list of Process in the beginning
    sub_pushing(Luan, size, count,tracking,que );
    auto_run(Luan,size,count,tracking,que);

    return 0;
}

void auto_run(Process list[], int &size, int &count,int&tracking, queue<Process>&que){
        // 
        if (que.empty()){
            return;
        }
        //sub_pushing(list, size, count,que );
        calculation(list, size, count,tracking, que);
        
        // last check
        /*
        if (que.empty()){
            cout << " Processes has been finished"<<endl;
            exit(0);
        }*/
}
void sub_pushing(Process list[], int& size, int&count,int&tracking, queue<Process>&que){
    // have to synchronize the list and queue
    //....................
    //
    for (int i = tracking; i<size; i++){
        if (list[i].get_arrival() <= count && list[i].get_timeN() !=0 && tracking<5 ){
            //cout << list[i].get_timeN()<<"as the checking"<<endl;
            que.push(list[i]);
            tracking = i;
        }
    }   
}
void calculation (Process list [], int& size , int &count,int&tracking, queue<Process>&que){
    if (que.front().get_timeN() <= time_frame && 
                        que.front().get_timeN() > 0){
        que.front().set_timeN(que.front().get_timeN());
        count+=que.front().get_timeN();
        //note
        del (list,size,que.front());
        sub_pushing(list,size,count,tracking,que);
        //
        print(que.front(),count);
    }else if(que.front().get_timeN()>time_frame){
        que.front().set_timeN(time_frame);
        count+=time_frame;
        // note
        sub_pushing(list,size,count,tracking,que);
        //
        que.push(que.front());               // because this process is not finished yet => put it into the queue
    }
    que.pop();                           // remove the already processed one out of queue
    auto_run(list,size,count,tracking,que);       // call recursive function
}

void print( Process& temp, int &count){
    cout << " The process " << " " << temp.get_id()
         << " has finished the race at " << temp.get_timeN() << " as "
         << count << "second" <<endl;
    //cout << " the total required time is" 
    
}

void get_input( Process group[], int size){
    string line;
    std::ifstream myfile ("round_robin.txt");
    if (myfile.is_open()){
        int count = 0; // tracking variable
        while(getline(myfile,line)){
            // have to seperate each variable in the whole line
            vector<string>temp;
            temp = split(line,' '); 
            int temp1 = str_To_Int(temp[1]);
            int temp2 = str_To_Int(temp[2]);
            Process sample(temp[0], temp1, temp2);
            group[count] = sample;
            count++;
        }
        myfile.close();   // close when file is finished read
    }else{
        cout <<" it is unable to open"<<endl;
    }
}
vector <string>split(const string&s, char delimiter){
    vector<string>tokens;
    string token;
    std::istringstream tokenstream(s);
    while(getline(tokenstream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

int str_To_Int(const string s){
    std::stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}
// start from here
int Search (Process list[], int &size, Process target){
    for (int i = 0; i < size ; i++){
        if(list[i].get_id()==target.get_id()){
            return i;
        }
    }
    return -1;
}

void del (Process list[], int& size, Process target){
    if (Search(list,size,target)==-1){
        return;
    }
    int index = Search(list,size,target);
    for (int i = index+1; i < size ;i++ ){
        list[i-1] = list[i];            
    }
    size -=1;
}
