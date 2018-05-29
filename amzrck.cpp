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
    int n=100;
    ll dp[n][2];
    dp[1][1]=2;
    dp[1][0]=1;
    for(int i=2;i<n;i++)
    {
        dp[i][1]=dp[i-1][1]+dp[i-1][0];
        dp[i][0]=dp[i-1][1];
    }
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        cout<<dp[n][1]<<'\n';
    }
}
