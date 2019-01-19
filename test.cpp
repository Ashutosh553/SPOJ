#include"bits/stdc++.h"
using namespace std;

const int maxn=1e5+10;


int re[maxn];
int main()
{
    string x:
    cin>>x;
    int n=x.size();
    for(int i=n-1;i>=0;--i)
    {
        re[i]=re[i+1];
        int aa=x[i]-'0';
        if(aa%2==0)
        {
            re[i]++;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(i)cout<<' ';
        cout<<re[i];
    }
    cout<<'\n';
}
