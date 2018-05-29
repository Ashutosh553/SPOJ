#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;int count=1;
    while(n!=0)
    {
        vector<vector<int> >rec(n,vector<int>(3));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<3;++j)
                cin>>rec[i][j];
        }
        vector<vector<ll> >dp(n,vector<ll>(3));
        dp[n-1][1]=rec[n-1][1];
        dp[n-1][0]=rec[n-1][0]+dp[n-1][1];
        dp[n-1][2]=1e12;
        for(int i=n-2;i>=0;--i)
        {
                    dp[i][2]=rec[i][2]+min(dp[i+1][1],dp[i+1][2]);



                    dp[i][1]=dp[i][2];
                    for(int k=0;k<3;++k)
                        dp[i][1]=min(dp[i][1],dp[i+1][k]);
                    dp[i][1]+=rec[i][1];



                    dp[i][0]=dp[i][1];
                    for(int k=0;k<2;++k)
                        dp[i][0]=min(dp[i][0],dp[i+1][k]);
                    dp[i][0]+=rec[i][0];
        }
        cout<<count++<<". "<<dp[0][1]<<endl;
        cin>>n;
    }
}
