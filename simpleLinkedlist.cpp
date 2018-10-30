#include<iostream>

using namespace std;
struct Node 
{
	int data;
	Node *next;
};
class LinkedList
{
	struct Node *root;
	int listSize;
	public:
	LinkedList()
	{
		root=NULL;
		listSize=0;
	}
	~LinkedList()
	{
	  
	    while(root!=NULL)
	    {
	        cout<<"deleted"<<endl;
	         deleteBegin();
	    }
	}
	void insert(int item, int pos=0);
	void deleteBegin();
	void display();
	int search(int item);
	void deleteKey(int key);
	

};
/**************************************************************************************
* Description : Inserts an element in the Linked List.
* Parameter : pos - the index at which the element is to be added default value is 0
*	      pos = -1 : element is added at the front of the list
*	      pos = 0 : element is added at the end of the list
*	      pos > 0 : element is added at that index
*	      if the index is greater than the number of elemnts in the list, elemnt 
*	      is added at the end and if the list is empty the element becomes the root
* 	      irrespective of the index
**************************************************************************************/
void LinkedList::insert(int item, int pos)
{
	Node *tmpNode = root;
	Node *newNode = new Node();
	newNode->data=item;
	newNode->next =NULL;
	
	//if the list is empty set the newly created node as root 
	if(root==NULL)
	{
		root = newNode;
		
	}
	//add elemnt at the front 
	else if(pos==-1)
	{
	    newNode->next=root;
	    root = newNode;
	}
	//add element at a defined index
	else if(pos>0 && pos<=listSize)
	{
	    int curIndex=1;
	    Node *prev =NULL;
	    while(curIndex<pos && tmpNode->next!=NULL)
	    {
	        prev = tmpNode;
	        tmpNode = tmpNode->next;
	        curIndex++;
	    }
	    newNode->next = tmpNode;
	    prev->next = newNode;
	}
	// add elements at the end of the list
	else
	{
		while(tmpNode->next !=NULL)
		{
			tmpNode = tmpNode->next;
		}
		
		tmpNode->next = newNode;
	}
	listSize++;	
}
void LinkedList::deleteBegin()
{
	Node *tmpNode = root;
	root = root->next;
	delete tmpNode;
	listSize--;
}

void  LinkedList::display()
{
	Node *tmp = root;
	while(tmp!=NULL)
	{
		cout<<"data : "<<tmp->data<<endl;
		tmp = tmp->next;		
	}
}

//search the element and return its index, returns -1 if the elemnt not found in the list
int LinkedList::search(int item)
{
	Node *tmp = root;	
	int i=1;
	while(tmp!=NULL)
	{
		if(tmp->data == item)
		{
			return i;
			//break;
		}
		else
		{
			i++;
			tmp = tmp->next;
		}
	}
	if(i>listSize)
	    return -1;
		
}
void LinkedList::deleteKey(int key)
{
	Node *tmp = root;
	Node *prev;
	while(tmp!=NULL)
        {
                if(tmp->data == key)
                {
			if(tmp==root)
				deleteBegin();
			else
			{
				prev->next=tmp->next;
				delete tmp;
			}
			break;
		}
		else
		{
			prev=tmp;
			tmp = tmp->next;
		}
	}						
}
int main()
{
	LinkedList list1;
	//Driver program to test
	list1.insert(10);
	list1.insert(30);
	list1.insert(20);
	list1.insert(50);
	list1.insert(40);		
	list1.display();
	list1.insert(90,-1);
	list1.insert(80,2);
	list1.insert(60,20);
	cout<<"After:"<<endl;
	list1.display();
	int searchindex = list1.search(500);
	if(searchindex>0)
	    cout<<"element found at index : "<<searchindex<<endl;
	else
	    cout<<"element not found in the list"<<endl;
}
