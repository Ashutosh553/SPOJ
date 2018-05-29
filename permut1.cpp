#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
int dp[20][100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        for(int i=0;i<=98;++i)
        {
            dp[1][i]=0;
        }
        dp[1][0]=1;
        for(int i=2;i<=15;++i)
        {
            for(int j=0;j<=99;++j)
            {
                dp[i][j]=0;
                for(int p=j;p>=max(0,j-(i-1));p--)
                {
                    dp[i][j]+=dp[i-1][p];
                }
            }
        }
        int t;cin>>t;
        while(t--)
        {
            int n,k;cin>>n>>k;
            cout<<dp[n][k]<<'\n';
        }
}
