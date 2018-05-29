#include"iomanip"
#include"iostream"
#include"limits"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"string"
#include"cstring"
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
int dp[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        int k;cin>>k;
        if(k==0)break;
        memset(dp,0,sizeof dp);
        string x,y;cin>>x>>y;
        int n1=x.length(),n2=y.length();
        if(n1<k||n2<k)
        {
            cout<<"0\n";
            continue;
        }
        memset(dp,0,sizeof dp);
        for(int i=n1-k;i>=0;--i)
        {
            for(int j=n2-k;j>=0;--j)
            {
                bool tr=true;
                for(int p=0;p<k;++p)
                {
                    if(x[i+p]!=y[j+p])
                    {
                        tr=false;break;
                    }
                }
                if(!tr)
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                    int p=k-1;
                    while(i+p<n1&&j+p<n2)
                    {
                        if(x[i+p]!=y[j+p])
                            break;
                        dp[i][j]=max(dp[i][j],p+1+dp[i+p+1][j+p+1]);
                        ++p;
                    }
                }

            }
        }
        cout<<dp[0][0]<<'\n';
    }
}
