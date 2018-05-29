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
ll m;
ll mu(ll a,ll b)
{
    if(b==0)
        return 0;
    else if(b%2==1)
    {
        return (a+mu(a,b-1))%m;
    }
    else return (2*mu(a,b/2))%m;
}
struct mat
{
    ll d,e,f,g;
    mat operator*(const mat & ob)
    {
        mat x;
        x.d=(mu(d,ob.d)%m+mu(e,ob.f)%m)%m;
        x.e=(mu(d,ob.e)%m+mu(e,ob.g)%m)%m;
        x.f=(mu(f,ob.d)%m+mu(g,ob.f)%m)%m;
        x.g=(mu(f,ob.e)%m+mu(g,ob.g)%m)%m;
        return x;
    }
};
mat solve(mat a,ll n)
{
    if(n==1)
        return a;
    if(n&1LL)
    {
        return a*solve(a,n-1);
    }
    else
    {
        return solve(a*a,n/2);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    ll n,k;
    scanf("%lld%lld%lld",&n,&k,&m);
    mat ob;
    ob.d=ob.e=k-1;ob.f=1;ob.g=0;
    ll ans=0;
    if(n==1)
    {
        printf("%lld\n",k%m);
        continue;
    }
    ob=solve(ob,n-1);
    ans=mu((ob.d+ob.f)%m,k-1)%m;
    printf("%lld\n",ans);
    }
}
