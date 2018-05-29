#include"iostream"
#include"vector"
#include"algorithm"
#include"cmath"
using namespace std;
typedef long long ll;
void dp(vector<ll>&num,vector<vector<ll> >&table,int i,int s)
{
    int len=table.size()-1;
    if(i==len)
    {
        table[i][s]=1;
    }
    if(table[i][s]>=0)
    {
        return;
    }
    ll curr=0;
    table[i][s]=0;
    for(int j=i;j<len;++j)
    {
        curr+=num[j];
        if(curr>=s)
        {
            dp(num,table,j+1,curr);
            table[i][s]+=table[j+1][curr];
        }
    }
}
int main()
{
    string x;
    cin>>x;int cou=1;
    while(x!="bye")
    {
        ll len = x.length();
        vector<ll>num(len);
        for(int i=0;i<len;++i)
        {
            char ch=x[i];int ch1=ch;
            ch1-=48;num[i]=ch1;
        }
        vector<vector<ll> > table(len+1,vector<ll>(225,-1));
        dp(num,table,0,0);
        cout<<cou++<<". "<<table[0][0]<<endl;
        cin>>x;
    }
}
