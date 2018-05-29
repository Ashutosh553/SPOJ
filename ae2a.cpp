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
    static double dp[601][3601];
    for(int j=0;j<600;++j)
        dp[j][0]=0;
    for(int j=1;j<=3600;++j)
        dp[600][j]=0;
    dp[600][0]=1;
    for(int i=599;i>=0;--i)
        for(int j=3599;j>=0;j--)
        {
            dp[i][j]=0;
            for(int k=1;k<=6&&j-k>=0;++k)
            {
                dp[i][j]+=dp[i+1][j-k]/6.0;
            }
        }
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        if(n>600||k>3600)
        {
            cout<<0<<endl;
        }
        else cout<<floor(dp[600-n][k]*100)<<endl;
    }
}
