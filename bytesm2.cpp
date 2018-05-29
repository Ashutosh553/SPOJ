#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
int table[100][100],dp[100][100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int h,w;cin>>h>>w;
        for(int i=0;i<h;++i)
            for(int j=0;j<w;++j)
                cin>>table[i][j];
        for(int j=0;j<w;++j)
            dp[h-1][j]=table[h-1][j];
        for(int i=h-2;i>=0;--i)
        {
            if(w!=1)
            {
            dp[i][0]=table[i][0]+max(dp[i+1][0],dp[i+1][1]);
            dp[i][w-1]=table[i][w-1]+max(dp[i+1][w-1],dp[i+1][w-2]);
            }
            else
            {
            dp[i][0]=table[i][0]+dp[i+1][0];
            }
            for(int j=1;j<w-1;++j)
            {
                dp[i][j]=table[i][j]+max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]));
            }
        }
        int max1=0;
        for(int j=0;j<w;++j)
            max1=max(max1,dp[0][j]);
        cout<<max1<<'\n';
    }
}
