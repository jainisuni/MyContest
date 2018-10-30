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
	void insert(int item, int pos=0);
	void deleteBegin();
	void display();
	int search(int item);
	void deleteKey(int key);
	

};

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
	list1.insert(10);
	list1.insert(30);
	list1.insert(20);
	list1.insert(50);
	list1.insert(40);		
	list1.display();
	int searchindex = list1.search(500);
	if(searchindex>0)
	    cout<<"element found at index : "<<searchindex<<endl;
	else
	    cout<<"element not found in the list"<<endl;
}
