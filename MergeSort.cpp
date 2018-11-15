
#include <iostream>

using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int t;
     int tmp[10];
    int i = start;
    int j = mid+1;
    int k=0;
    
    //compare elemnents from 2 sub-array to be in sorted order
    while(i <= mid && j <= end)
    {
        if(arr[i]<arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    //if the no of elements in first half is more than the second half, copy remaining elemnts in the temp array
    while(i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    //if the no of elements in second half is more than the first half, copy remaining elemnts in the temp array
    while(j <= end)
    {
        tmp[k++] = arr[j++];
    }
  
    //copy sorted, merged sub-array into original
   for(i=end; i >= start; i--)
    {
        arr[i] = tmp[--k];  
    } 
}

void MergeSort(int arr[], int start,int end)
{
    if(start < end)
    {
        int mid = (start+end)/2;
        MergeSort(arr,start,mid);   //divide left sub-array
        MergeSort(arr,mid+1,end);   //divide right sub-array
        merge(arr,start,mid,end);
    }
    
}

int main()
{
    int arr []={6,5,12,10,9,1};
   
    for(int i=0;i<6;i++)
    cout<<arr[i]<<"\t";
    cout<<"\n";
    MergeSort(arr,0,5);
    cout<<"After sorting :"<<endl;
    for(int i=0;i<6;i++)
        cout<<arr[i]<<"\t";
    return 0;
}
