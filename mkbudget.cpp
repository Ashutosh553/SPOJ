#include"iomanip"
#include"iostream"
#include"limits"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"queue"
#include"stack"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
#include"cstring"
using namespace std;
typedef long long ll;
ll dp[50][1000];
ll inf=1e8;
void et()
{
    for(int i=0;i<29;++i)
        for(int j=0;j<301;++j)
            dp[i][j]=inf;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cas=1;
    while(1)
    {
        int n;cin>>n;
        if(n==0)break;
        int hir,sal,sev;cin>>hir>>sal>>sev;
        et();
        vector<ll>rec(n+1); 
        for(int i=1;i<=n;++i)
        {
            cin>>rec[i];
        }
        for(int i=rec[1];i<300;++i)
        {
            dp[1][i]=(hir+sal)*i;
        }
        for(int i=2;i<=n;++i)
        {
            for(int w=rec[i];w<300;++w)
            {
                dp[i][w]=1e8;;
                for(int pr=0;pr<=w;++pr)
                {
                    dp[i][w]=min(dp[i][w],hir*(w-pr)+sal*w+dp[i-1][pr]);
                }
                for(int pr=w+1;pr<300;++pr)
                {
                    dp[i][w]=min(dp[i][w],sev*(pr-w)+sal*w+dp[i-1][pr]);
                }
            }
        }
        ll ans=1e8;
        for(int i=rec[n];i<300;++i)
        {
            ans=min(ans,dp[n][i]);
        }
        cout<<"Case "<<cas++<<", cost = $"<<ans<<'\n';
    }
}
