/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
class StackArray
{
    int top;
    int maxSize;
    int arr[10];
    public:
        StackArray()
        {
            top=-1;
            maxSize=10;
        }
        bool isEmpty();
        bool isFull();
        void peek();
        void push(int);
        void pop();
};

bool StackArray::isEmpty()
{
    if(top<0)
        return 1;
    else
        return 0;
}
bool StackArray::isFull()
{
    if(top>=maxSize-1)
        return 1;
    else
        return 0;
        
}

void StackArray::peek()
{
    if(isEmpty())
        cout<<"Stack is Empty"<<endl;
    else 
        cout<<"Element at the top : "<<arr[top]<<endl;
}
void StackArray::push(int data)
{
    if(!isFull())
    {
        arr[++top] = data;
    }
    else
        cout<<"The Stack is Full!!!"<<endl;
}
void StackArray::pop()
{
    if(!isEmpty())
    {
        arr[top]=0;
        --top;
    }
    else
        cout<<"Stack is Empty!!!"<<endl;
}

int main()
{
    //cout<<"Hello World";
    StackArray st;
    
    st.push(10);
    st.push(30);
    st.push(20);
    st.peek();
    st.pop();
    
    st.peek();
    return 0;
}
