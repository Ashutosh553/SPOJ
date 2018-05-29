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
const ll maxn=510;
ll dpy[maxn][maxn],dpb[maxn][maxn],ans[maxn][maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        int n,m;cin>>n>>m;
        if(n==0)break;
        memset(dpy,0,sizeof dpb);memset(dpb,0,sizeof dpy);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                cin>>dpy[i][j];
                dpy[i][j]+=dpy[i][j-1];
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                cin>>dpb[i][j];
                dpb[i][j]+=dpb[i-1][j];
            }
        }
        ll an=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                ans[i][j]=max(dpy[i][j]+ans[i-1][j],dpb[i][j]+ans[i][j-1]);
                an=max(an,ans[i][j]);
            }
        }
        cout<<an<<'\n';
    }
}
