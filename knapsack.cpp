#include<iostream>
#include"cmath"
#include"vector"
#include"algorithm"
using namespace std;
typedef long long ll;
int main()
{
    ll s,n;cin>>s>>n;
    vector<ll>sz(n),value(n);
    for(int i=0;i<n;++i)
    {
        cin>>sz[i]>>value[i];
    }
    vector<vector<ll> >dp(n+1,vector<ll>(s+1,-1));
    for(int i=n-1;i>=0;--i)
    {
        for(int j=s;j>=0;j--)
        {
            if(i==n-1)
            {
                if(sz[n-1]<=j)
                {
                    dp[i][j]=value[n-1];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
            else
            {
                if(sz[i]<=j)
                    dp[i][j]=max(dp[i+1][j],value[i]+dp[i+1][j-sz[i]]);
                else dp[i][j]=dp[i+1][j];
            }
        }
    }
    cout<<dp[0][s]<<endl;
}
