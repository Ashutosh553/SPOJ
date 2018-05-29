#include"iostream"
#include"string"
#include"cmath"
#include"vector"
#include"algorithm"
#include"unordered_set"
using namspace std;
typedef long long ll;
void solve(string x,vector<string>&words,int count)
{
    int len=x.length(),vlen=words.size();
    ll dp[len+1][count+1];
    for(int i=0;i<len;++i)
    {
        dp[i][count]=0;
    }
    for(int i=0;i<count;++i)
    {
        dp[len][i]=0;
    }
    dp[len][count]=1;
    for(int i=
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        if(n==0)break;
        unordered_set<string>myset;
        for(int i=0;i<n;i++)
        {
            string x;cin>>x;
            myset.insert(x);
        }
        string x="";cin>>x;
        while(x!="LAST")
        {
            string z;
            vector<string>words;
            cin>>z;int count=0
            while(z[0]>='a'&&z[0]<='z')
            {
                if(myset.find(z)!=myset.end())
                {
                    count+=z.length();
                    words.push_back(z);
                }
                cin>>z;
            }
            solve(x,y,count);
            x=z;
        }
        cin>>x;
    }
}
