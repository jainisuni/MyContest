#include<iostream>

using namespace std;

class Queue
{
    int front;
    int rear;
    int maxSize=4;
    int arr[4];
    public:
    Queue():front(-1),rear(-1){}
    bool isFull();
    bool isEmpty();
    void peek();
    void enqueue(int data);
    void dequeue();
};

bool Queue::isFull()
{
    if(rear==maxSize-1)
        return 1;
    else
        return 0;
}
bool Queue::isEmpty()
{
    if(front==-1)
        return 1;
    else
        return 0;
}
void Queue::peek()
{
    if(!isEmpty()) 
        cout<<"element at the front : "<<arr[front]<<endl;    
    else
        cout<<"Queue is empty"<<endl;
}
void Queue::enqueue(int data)
{
    if(!isFull())
    {
        arr[++rear]=data;
        if(isEmpty())
            ++front;
    }
    else
        cout<<"Queue is full!!! Cannot add more elements."<<endl;
}
void Queue::dequeue()
{
    arr[front]=-1;
    if(!isEmpty())
        front++;
    else
        cout<<"Queue is Empty!! cannot remove element."<<endl;
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
    
}
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(20);
    q.enqueue(60);
    q.peek();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.peek();
    if(q.isFull())
        cout<<"Queue is full"<<endl;
        
}
