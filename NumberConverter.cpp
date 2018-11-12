/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    int num = 2147483647;
    string strnum="";
    int comma_pos=0;
    int style =1 ; // 0 : Indian style ; 1: US style
    while(num >0)
    {
        cout<<"comma_pos : "<<comma_pos<<"\t mod : "<<comma_pos%3<<endl;
        if(style)
        {
            if(comma_pos!=0 && comma_pos%3 ==0)
            {
                strnum+=",";
                cout<< " if pos : "<<comma_pos<<endl;
            }
        }
        else
        {
            if(comma_pos==3)
                strnum+=",";
            else if(comma_pos!=0 && comma_pos%3 ==0)
            
            
        }
        strnum+=(char)(num%10+'0');
        comma_pos++;
        num/=10;
       // cout<<"num : "<<num<<endl;
    }
    //reverse(strnum.begin(),strnum.end());
    
    
    cout<<" string : "<< strnum.c_str()<<endl;
    
   
    return 0;
}
