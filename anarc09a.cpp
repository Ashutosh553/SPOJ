#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
const int maxn = 2050;
ll dp[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    int cas=1;
    while(s[0]!='-')
    {
        int len=s.length();
        for(int j=1;j<maxn;++j)
        {
            dp[len][j]=numeric_limits<ll>::max()/3;
        }
        dp[len][0]=0;
        for(int i=len-1;i>=0;i--)
        {
            for(int j=0;j<=len;++j)
            {
                if(j==0)
                {
                    if(s[i]=='}')
                    {
                        dp[i][j]=1+dp[i+1][j+1];
                    }
                    else dp[i][j]=dp[i+1][j+1];
                }
                else if(j==len)
                {
                    if(s[i]=='{')
                    {
                        dp[i][j]=1+dp[i+1][j-1];
                    }
                    else dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    if(s[i]=='{')
                    {
                        dp[i][j]=min(dp[i+1][j+1],1+dp[i+1][j-1]);
                    }
                    else
                    {
                        dp[i][j]=min(dp[i+1][j-1],1+dp[i+1][j+1]);
                    }
                }
            }
        }
        cout<<cas++<<". "<<dp[0][0]<<'\n';
        cin>>s;
    }
}
