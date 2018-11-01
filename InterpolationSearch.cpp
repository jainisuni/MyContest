/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
#define MAX 10

class InterpolationSearch
{
    int low,high,mid;
    public:
    int array[MAX];
    InterpolationSearch():low(0),high(9),mid(0){}
    int search(int data);
};

int InterpolationSearch::search(int data)
{
    bool found =0;
    while(!found)
    {
        mid = low + (double)((double)(high-low)/(array[high]-array[low]))*(data-array[low]);
        cout<<"mid : "<<mid<<endl;
        if(array[mid]==data)
        {
            found = 1;
            return mid;
        }
        else if(array[mid]<data)
            low = mid+1;
        else
            high = mid-1;
        if(low>=high)
            return -1;
    }
}
int main()
{
    InterpolationSearch is;
    int i=0;
    for(;i<MAX;i++)
        is.array[i] = (i+1)*10;
    for(i=0;i<MAX;i++)    
        cout<<"data : "<<is.array[i]<<endl;
    int index = is.search(110);
    
    if(index>=0)
        cout<<"Element foun at position "<<index<<endl;
    else
        cout<<"ELement not found"<<endl;
    return 0;
}
