#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;


bool compFunctor( pair<string,int> elem1, pair<string,int> elem2)
{
        return elem2.second < elem1.second;
}

int main()
{
        ifstream myfile;
        string line;
        map<string,int>  dictionary;
        map<string,int>::iterator it;
        vector<pair<string,int> > freqSort;
        vector<pair<string,int> >::iterator itv;
        myfile.open("wordlist",ios::in);
        if(myfile.is_open())
        {
                while(getline(myfile,line))
                {
                        istringstream ss(line);
                        for(string word; ss >> word;)
                        {
                                it = dictionary.find(word);
                                if(it!=dictionary.end())
                                        it->second++;
                                else
                                        dictionary.insert(pair<string,int>(word,1));
                                //cout<<line<<endl;
                        }
                }
                myfile.close();
                int i=0;
                for(it=dictionary.begin();it!=dictionary.end();it++)
                {
                        freqSort.push_back(make_pair(it->first,it->second));
                }

                sort(freqSort.begin(),freqSort.end(),compFunctor);
                for(itv=freqSort.begin();i<=9;itv++)
                {
                        cout<<itv->first<<" : "<<itv->second<<endl;
                        i++;
                }
        }
        else
                cout<<"Could not open file"<<endl;
}

