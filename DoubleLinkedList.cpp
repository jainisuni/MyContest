#include<iostream>

using namespace std;
struct Node 
{
	int data;
	Node *next;
	Node *prev;
};
class DLinkedList
{
	struct Node *first;
	struct Node *last;
	
	int listSize;
	public:
	DLinkedList()
	{
		first=NULL;
		last=NULL;
		listSize=0;
	}
	~DLinkedList()
	{
	    while(first->next!=NULL)
	    {
	        cout<<"deleted"<<endl;
	        deleteBegin();
	    }
	    delete first;
	}
	void insert(int item);
	void insertLast(int item);
	void deleteBegin();
	void deleteLast();
	void deleteKey(int key);
	void displayForward();
	void displayBackward();
	
	
	

};

void DLinkedList::insert(int item)
{
	Node *newNode = new Node();
	newNode->data=item;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	//if the list is empty set the newly created node as root 
	if(first==NULL)
	{
		first = newNode;
		last = first;
    }
    else
    {
        newNode->next = first;
        first->prev=newNode;
        
        first = newNode;
        
    }
	listSize++;	
}

void DLinkedList::insertLast(int item)
{
	Node *newNode = new Node();
	newNode->data=item;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	//if the list is empty set the newly created node as root 
	if(last==NULL)
	{
		first = newNode;
		last = first;
    }
    else
    {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
        
    }
	listSize++;	
}
void DLinkedList::deleteBegin()
{
	Node *tmpNode = first;
	first = first->next;
	delete tmpNode;
	first->prev=NULL;
	listSize--;
}

void DLinkedList::deleteLast()
{
	Node *tmpNode = last;
	last = last->prev;
	last->next=NULL;
	delete tmpNode;
	listSize--;
}
void DLinkedList::deleteKey(int key)
{
	Node *tmp = first;
	
	while(tmp!=NULL)
    {
        if(tmp->data == key)
        {
			if(tmp==first)
				deleteBegin();
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				delete tmp;
			}
			break;
		}
		else
		{
			tmp = tmp->next;
		}
	}						
}
void DLinkedList::displayForward()
{
    cout<<"Forward display : "<<endl;
	Node *tmp = first;
	while(tmp!=NULL)
	{
		cout<<"data : "<<tmp->data<<endl;
		tmp = tmp->next;		
	}
}
void DLinkedList::displayBackward()
{
    cout<<"Backward display : "<<endl;
	Node *tmp = last;
	//if(last==N)
	while(tmp!=NULL)
	{
		cout<<"data : "<<tmp->data<<endl;
		tmp = tmp->prev;		
	}
}

int main()
{
    //Driver code to test
	DLinkedList list1;
	list1.insert(10);
	list1.insert(30);
	list1.insert(20);
	list1.insert(50);
	list1.insert(40);		
	list1.displayForward();
	list1.displayBackward();
	
	list1.deleteKey(30);
	list1.deleteLast();
  list1.insertLast(60);
	list1.displayBackward();
	list1.displayForward();


}
