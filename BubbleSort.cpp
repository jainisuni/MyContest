
#include <iostream>

using namespace std;
void swap(int &x,int &y)
{
    int t;
    t=x;
    x=y;
    y=t;
    
    
}
void BubbleSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        swap(arr[j],arr[j+1]);
    }
}
int main()
{
    //cout<<"Hello World";
    int arr []={4,1,5,6,3,2};
    BubbleSort(arr,6);
    for(int i=0;i<6;i++)
    cout<<arr[i]<<"\t";
    return 0;
}
