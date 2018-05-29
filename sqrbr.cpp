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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        ll mask=0;
        for(int i=0;i<k;++i)
        {
            ll s;cin>>s;
            mask=mask|(1LL<<s);
        }
        ll dp[50][50];
        for(int j=1;j<50;++j)
        {
            dp[2*n+1][j]=0;
        }
        dp[2*n+1][0]=1;
        for(ll i=2*n;i>=1;--i)
        {
            for(ll j=0;j<=n;++j)
            {
                if(j==0)
                {
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(j==n)
                {
                    if(mask&(1LL<<i))
                        dp[i][j]=0;
                    else dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    if(mask&(1LL<<i))
                    {
                        dp[i][j]=dp[i+1][j+1];
                    }
                    else dp[i][j]=dp[i+1][j+1]+dp[i+1][j-1];
                }
            }
        }
        cout<<dp[1][0]<<'\n';
    }
}
