#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;string x;cin>>n>>x;
    static int dp[5010][5010];
    dp[n][n]=0;
    for(int i=n-1;i>=0;--i)
    {
        for(int j=i;j<n;++j)
        {
            if(x[i]==x[j])
            {
                if(i==j)
                    dp[i][j]=0;
                else dp[i][j]=dp[i+1][j-1];
            }
            else dp[i][j]=1+min(dp[i][j-1],dp[i+1][j]);
        }
    }
    cout<<dp[0][n-1]<<'\n';
}
