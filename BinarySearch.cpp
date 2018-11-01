#include<iostream>

using namespace std;

class Binarysearch
{
   int mid;
   int low;
   int high;
   public:
   int array[10];
   Binarysearch():mid(0),low(0),high(10){}
   int search(int data);
};
int Binarysearch::search(int data)
{
    int found=0;
    while(!found)
    {
        mid = low + (high-low)/2;
        if(array[mid]==data)
        {
            found=1;
            return mid;
        }
        else if(array[mid]<data)
        {
            //cout<<
            low = mid+1;
        }
        else 
        {
            high=mid-1;
        }
        if(low>high)
            return -1;
    }
    return -1;
}

int main()
{
    Binarysearch bs;
    int i=0;
    for(i = 0;i<10;i++)
        bs.array[i] = (i+1)*10;
        
    for(i = 0;i<10;i++)
        cout<<bs.array[i]<<endl;
    
    int index = bs.search(100);
    
    if(index>=0)
        cout<<"element found at index "<<index<<endl;
    else
        cout<<"element not found "<<endl;
        //cout<<"Queue is full"<<endl;
        
}
