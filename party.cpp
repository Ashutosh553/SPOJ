#include<iostream>
#include"cmath"
#include"vector"
#include"algorithm"
using namespace std;
typedef long long ll;
int main()
{
    while(1)
    {

    ll s,n;cin>>s>>n;
    if(n==0)break;
    vector<ll>sz(n),value(n);
    for(int i=0;i<n;++i)
    {
        cin>>sz[i]>>value[i];
    }
    vector<vector<ll> >dp(n+1,vector<ll>(s+1,0));
    vector<vector<ll> >tab(n+1,vector<ll>(s+1,0));
    for(int i=n-1;i>=0;--i)
    {
        for(int j=s;j>=0;j--)
        {
            if(i==n-1)
            {
                if(sz[n-1]<=j)
                {
                    dp[i][j]=value[n-1];
                    if(value[n-1]!=0)
                        tab[i][j]=sz[i];
                }
                else
                {
                    dp[i][j]=0;
                    tab[i][j]=0;
                }
            }
            else
            {
                if(sz[i]<=j)
                    dp[i][j]=max(dp[i+1][j],value[i]+dp[i+1][j-sz[i]]);
                else dp[i][j]=dp[i+1][j];

                if(sz[i]<=j&&dp[i+1][j]==value[i]+dp[i+1][j-sz[i]])
                    tab[i][j]=min(tab[i+1][j],sz[i]+tab[i+1][j-sz[i]]);
                else if(sz[i]>j)
                    tab[i][j]=tab[i+1][j];
                else if(dp[i][j]==dp[i+1][j])
                    tab[i][j]=tab[i+1][j];
                else tab[i][j]=sz[i]+tab[i+1][j-sz[i]];
            }
        }
    }
    cout<<tab[0][s]<<' '<<dp[0][s]<<'\n';

    }
}
