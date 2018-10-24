
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <algorithm>
int lastIndex=0;
using namespace std;
class Transaction
{
    public: 
    int id;
    long sizebytes;
    double fee;
};
class Block
{
   
    int index;
    vector<Transaction> tr;
    double reward;
    size_t blockHash;
    Block *prevBlock;
    public :
    double CreateBlock(vector<Transaction> v);
    void printBlockTrans();
    
};

void printTransactions(vector<Transaction> trans)
{
    vector<Transaction>::iterator it;
     cout<<"ID\tSize(Bytes)\tFee(BTC)"<<endl;
    for(it=trans.begin();it!=trans.end();it++)
        cout<<it->id<<"\t"<<it->sizebytes<<"\t\t"<<it->fee<<endl;
}

bool compTransaction(Transaction left, Transaction right)
{
    return(left.fee>right.fee);
}
void Block::printBlockTrans()
{
    printTransactions(tr);
}
double Block::CreateBlock(vector<Transaction> v)
{
    long maxSize = 500000;
    long blksize=0;
    double maxReward = 12.5;
    Transaction tmptr;
    vector<Transaction>::iterator it;
    
    
    time_t t = std::time(0);
    long int now = static_cast<long int> (t);
    cout<< now<<endl;
    index = ++lastIndex;
    prevBlock=NULL;
    std::string str = to_string(lastIndex)+ to_string(now);
    //cout<<"String : "<<str<<endl;
    std::hash<std::string> str_hash;
    blockHash = str_hash(str);
    //cout<<"Hash : "<<blk->blockHash <<endl;
    
    for(it=v.begin();it!=v.end();it++)
    {
        if ((blksize+it->sizebytes)<maxSize)
        {
           // cout<<"block size :"<<blksize<<"\t reward : "<<maxReward<<endl;
            blksize+=it->sizebytes;
            tmptr.id = it->id;
            tmptr.sizebytes = it->sizebytes;
            tmptr.fee = it->fee;
            maxReward+=it->fee;
            tr.push_back(tmptr);
        }
        else
        {
            continue;
           
        }
    }
    return maxReward;
}
int main()
{
    //create transactions;
    
    vector<Transaction> trans;
    vector<Transaction>::iterator it;
    Transaction tmptr;
    
  	tmptr.id=10;	tmptr.sizebytes=143807;	tmptr.fee=0.266;
	trans.push_back(tmptr);
	
	tmptr.id=8;	tmptr.sizebytes=139603;	tmptr.fee=0.2541;
	trans.push_back(tmptr);
	
	tmptr.id=3;	tmptr.sizebytes=134928;	tmptr.fee=0.2307;
	trans.push_back(tmptr);
	
	tmptr.id=2;	tmptr.sizebytes=98732;	tmptr.fee=0.1856;
	trans.push_back(tmptr);             
	                                    
	tmptr.id=4;	tmptr.sizebytes=77275;	tmptr.fee=0.1522;
	trans.push_back(tmptr);             
	                                    
	tmptr.id=7;	tmptr.sizebytes=70820;	tmptr.fee=0.1409;
	trans.push_back(tmptr);             
	                                    

	tmptr.id=1;	tmptr.sizebytes=57247;	tmptr.fee=0.0887;
	trans.push_back(tmptr);             
	                                    
	tmptr.id=12;	tmptr.sizebytes=40572;	tmptr.fee=0.0686;
	trans.push_back(tmptr);             
	                                    
	tmptr.id=5;	tmptr.sizebytes=29240;	tmptr.fee=0.0532;
	trans.push_back(tmptr);             
	                                    
	tmptr.id=6;	tmptr.sizebytes=15440;	tmptr.fee=0.025;
	trans.push_back(tmptr);   
	
	tmptr.id=9;	tmptr.sizebytes=63718;	tmptr.fee=0.1147;
	trans.push_back(tmptr);             

    tmptr.id=11;	tmptr.sizebytes=190457;	tmptr.fee=0.2933;
	trans.push_back(tmptr);
    
    //sort transactions with descending order of fee
    sort(trans.begin(),trans.end(),compTransaction);
    
    //print transactions
    printTransactions(trans);
    
    //create a block
    vector<Transaction> it1;
    Block *blk =new Block();
    
    //returns the maximum award earned
    double maxReward = blk->CreateBlock(trans);    
    cout<<"Maximum Reward : "<<maxReward<<endl;
    
    //print transactions in a block
    blk->printBlockTrans();
   /* for(it=blk->tr.begin();it!=blk->tr.end();it++)
        cout<<it->id<<"\t"<<it->sizebytes<<"\t\t"<<it->fee<<endl;*/
        
   delete(blk);
    
    return 0;
}
