
// lab : Luan Nguyen - Queue
#include<iostream>
#include<list>
#include<stack>
using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::stack;
class Queue{
    private:
        stack<int>in;
        stack<int>out;
    public:
        Queue(){}
        void enqueue(int num);
        int dequeue();
        bool isFull();
        bool isEmpty();
        void print();

};
void Queue::enqueue(int num){
    in.push(num);
}
int Queue::dequeue(){
    if (out.empty()){
        while(!in.empty()){
            int temp = in.top();
            out.push(temp);
            in.pop();
        }
    }
    int temp = out.top();
    out.pop();
    return temp;

}
bool Queue::isFull(){
    return false;
}
bool Queue::isEmpty(){
    return in.empty()&&out.empty();
}
/*
void Queue::print(){
    for(auto v: li){
        cout << v <<endl;
    }
}*/

int main(){
    Queue Luan;
    cout << "add 10"<<endl;
    Luan.enqueue(10);
    cout <<"add 20" <<endl;
    Luan.enqueue(20);
    //Luan.print();
    cout << " this is after dequeue"<<endl;
    cout<<Luan.dequeue() <<"has been removed"<< endl;
    //Luan.dequeue();
    //Luan.print();
    return 0;
}
