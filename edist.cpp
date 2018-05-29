#include"iostream"
#include"cmath"
#include"string"
#include"algorithm"
#include"vector"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string x,y;cin>>x>>y;
        int len1=x.length(),len2=y.length();
        int dp[len1+1][len2+2];
        for(int i=0;i<len2;i++)
        {
            dp[len1][i]=len2-i;
        }
        for(int i=0;i<len1;++i)
        {
            dp[i][len2]=len1-i;
        }
        dp[len1][len2]=0;
        for(int i=len1-1;i>=0;i--)
        {
            for(int j=len2-1;j>=0;j--)
            {
                if(x[i]==y[j])
                {
                    dp[i][j]=dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]=min(1+dp[i][j+1],1+dp[i+1][j]);
                    dp[i][j]=min(dp[i][j],1+dp[i+1][j+1]);
                }
            }
        }
        cout<<dp[0][0]<<endl;
    }
}
