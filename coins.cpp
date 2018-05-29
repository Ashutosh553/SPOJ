#include<iostream>
#include "cmath"
#include"vector"
#include"unordered_map"
using namespace std;
typedef long long ll;
unordered_map<int,ll>mymap;
ll f(int n)
{
    if(mymap.find(n)!=mymap.end())
        return mymap[n];
    if(n>=1&&n<12)
    {
        mymap[n]=n;
        return n;
    }
    else
    {
        mymap[n]=f(n/2)+f(n/3)+f(n/4);
        return mymap[n];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;int c=0;
    while(!cin.eof())
    {
        cin>>n;
        cout<<f(n)<<'\n';
        if(++c==10)
            break;
    }
}
