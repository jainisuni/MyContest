#include <iostream>

using namespace std;
void swap(int & a , int &b)
{
    int tmp = a;
    a=b;
    b=tmp;
}
void selectionSort(int arr[], int n)
{
    int min =0;
    int j=0;
    int iter = 0;
    for(int i=0;i<n-1;i++)
    {
        min = i;
        j=i+1;
        while(j<n)
        {
             iter++;
                cout<<"iterations : "<<iter<<endl;
            if(arr[j]<arr[min])
            {
               
                min=j;
            }
            j++;
        }
        if(arr[i]!=arr[min])
            swap(arr[i],arr[min]);
    }
}
int main()
{
   
    int arr []={14,33,27,10,35,19,42,44};
    
    int i=0;
    int size = sizeof(arr)/sizeof(int);
    cout<<"original : "<<endl;
    for(;i<size;i++)
        cout<<arr[i]<<"\t";
    cout<<"\n";
    selectionSort(arr,size);
    cout<<"sorted : "<<endl;
    for(i=0;i<size;i++)
        cout<<arr[i]<<"\t";
    
    
    return 0;
}
