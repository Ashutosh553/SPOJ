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
const int maxn=1e3;
const ll mo=2;
ll ans[maxn][maxn];
ll solve(ll n,ll m)
{
    if(n==0&&m==0)return 1LL;
    if(n==0||m==0)return 0LL;
    if(ans[n][m]==-1)
    {
        ans[n][m]=(        (m*solve(n-1,m)+solve(n-1,m-1))%mo          +mo)%mo;
        return ans[n][m];
    }
    else return ans[n][m];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    memset(ans,-1,sizeof ans);
    for(int i=1;i<=n;++i)
    {
        cout<<"S("<<n<<","<<i<<") = "<<solve(n,i)<<'\n';
    }
}
