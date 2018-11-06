
#include <iostream>

using namespace std;

void InsertionSort(int arr[],int n)
{
    int it=0;
    int j=0;
    int tmp;
    for(int i=1;i<n;i++)
    {
        j=i-1;
        tmp=arr[i];
    while(tmp<arr[j] && j>=0)
    {
    
        arr[j+1]=arr[j];
        --j;
        it++;
    }
    arr[j+1]=tmp;
    }
    cout<<it<<endl;
}
int main()
{
    //cout<<"Hello World";
    int arr []={4,1,5,6,3,2};
    InsertionSort(arr,6);
    for(int i=0;i<6;i++)
    cout<<arr[i]<<"\t";
    return 0;
}
