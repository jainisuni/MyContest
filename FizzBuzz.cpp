#include<iostream>

using namespace std;

int main()
{
        string output;
        for(int i=0;i<=100;++i)
        {
                if(i%3 ==0)
                output="Fizz";
                if(i%5 ==0)
                output+="Buzz";
                if(output!="")
                        cout<<output<<endl;
                else
                        cout<<i<<endl;
                output="";
        }
}
