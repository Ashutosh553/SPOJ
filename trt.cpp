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
    static int dp[2001][2001];
    int n,rec[2001];
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>rec[i];
        dp[i][i]=0;
    }
    for(int i=n-1;i>=0;--i)
    {
        for(int j=i;j<n;++j)
        {
            int age=(n+i-j);
            dp[i][j]=max(rec[i]*age+dp[i+1][j],rec[j]*age+dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<'\n';
}
