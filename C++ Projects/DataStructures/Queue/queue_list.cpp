
// lab : Luan Nguyen - Queue
#include<iostream>
#include<list>
using std::cout;
using std::cin;
using std::endl;
using std::list;
class Queue{
    private:
        list<int>li;
    public:
        Queue(){}
        void enqueue(int num);
        int dequeue();
        bool isFull();
        bool isEmpty();
        void print();

};
void Queue::enqueue(int num){
    li.push_back(num);
}
int Queue::dequeue(){
    if (isEmpty()){
        exit(1);
    }
    int temp = li.front();
    li.pop_front();
    return temp;
}
bool Queue::isFull(){
    return false;
}
bool Queue::isEmpty(){
    return li.empty();
}
void Queue::print(){
    for(auto v: li){
        cout << v <<endl;
    }
}

int main(){
    Queue Luan;
    Luan.enqueue(10);
    Luan.enqueue(20);
    Luan.print();
    cout << " this is after dequeue"<<endl;
    Luan.dequeue();
    //Luan.dequeue();
    Luan.print();
    return 0;
}
