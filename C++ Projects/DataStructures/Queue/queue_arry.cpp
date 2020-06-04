// lab : Luan Nguyen - Queue
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
class Queue{
    private:
        int array[10];
        int tail;
        int head;
    public:
        Queue():tail(0),head(0){}
        void enqueue(int num);
        int dequeue();
        bool isFull();
        bool isEmpty();
        void print();

};
void Queue::enqueue(int num){
    if (isFull()){
        return;
    }
    array[tail]=num;
    tail =(tail + 1)%10;
}
int Queue::dequeue(){
    if (isEmpty()){
        exit(1);
    }
    int temp = array[head];
    head = (head+1)% 10;
    return temp;
}
bool Queue::isFull(){
    return (tail+1)%10 == head;
}
bool Queue::isEmpty(){
    return head==tail;
}
void Queue::print(){
    for(int i =head ; i < tail; i = (i+1)%10 ){
        cout << array[i]<<endl;
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
