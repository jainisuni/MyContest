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
class CircularList
{
    Node *first;
    public:
        CircularList()
        {
            first=NULL;
        }
        void insert(int item);
        void deleteLast();
        void display();
};
void CircularList::insert(int item)
{
    Node *newNode = new Node();
    Node *tmp = first;
    newNode->data=item;
    newNode->next = NULL;
    
    if(first==NULL)
    {
        first = newNode;
        first->next = newNode;
    }
    else
    {
        while(tmp->next!=first)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->next = first;
    }
}

void CircularList::display()
{
    Node *tmp = first;
    if(first->next == first)
        cout<<"single self loop list , data : "<<first->data<<endl;
    else
    {
        
        while(tmp->next!=first)
        {
            cout<<"data : "<<tmp->data<<endl;
            tmp=tmp->next;
        }
        cout<<"data : "<<tmp->data<<endl;
        cout<<"first : "<<tmp->next->data<<endl;
    }    
   
}

void CircularList::deleteLast()
{
    Node *tmp = first;
    Node *prev =NULL;
    while(tmp->next!=first)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next =first;
    delete tmp;
    
}
int main()
{
    //cout<<"Hello World";
    CircularList list;
    list.insert(10);
    list.insert(20);
    list.insert(40);
    list.insert(30); 
    list.display();
    list.deleteLast();
    list.display();
    return 0;
}
