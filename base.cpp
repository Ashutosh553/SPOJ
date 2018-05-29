#include"iomanip"
#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
using namespace std;
typedef long long ll;
map<char,int>my;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<10;++i)
    {
        my[i+48]=i;
    }
    for(int i=0;i<6;++i)
    {
        my[i+65]=i+10;
    }
    int c=0;
    while(!cin.eof())
    {
        string s;int b1,b2;
        cin>>s>>b1>>b2;
        ll ans=0;ll po=1;
        for(int i=s.length()-1;i>=0;--i)
        {
            ans=ans+po*my[s[i]];
            po*=b1;
        }
        string res="";
        while(ans!=0)
        {
            int dig=ans%b2;
            ans/=b2;char ch;
            if(dig<10)
            {
                ch=(dig+48);
            }
            else ch=(dig+65-10);
            string temp="";temp.push_back(ch);
            res=temp+res;
        }
        if(res.length()>7)
            res="ERROR";
        while(res.length()<7)
        {
            res=" "+res;
        }
        cout<<res<<'\n';
    }
}
