#include"iostream"
#include"vector"
#include"cmath"
#include"algorithm"
using namespace std;
typedef long long ll;
ll solve(vector<ll>& rec,ll low,ll high)
{
    if(low>high)
        return 0;
    if(low==high)
    {
        if(rec[low]==47)
        {
            return 1;
        }
        else return 0;
    }
    ll mid=low+(high-low)/2;
    ll ans=solve(rec,low,mid)+solve(rec,mid+1,high);
}
int main()
{
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        vector<ll>rec(n);
        for(ll i=0;i<n;++i)
        {
            cin>>rec[i];
        }
        ll ans=solve(rec,0,n-1);
    }
}
