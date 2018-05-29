#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
ll mo=1e7+7;
ll modexp(ll a,ll b)
{
    if(b==0)
        return 1;
    ll ans=modexp((a*a)%mo,b/2);
    if(b%2==1)
        ans=(a*ans)%mo;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    while(n!=0)
    {
        ll ans=modexp(n-1,k)*2+modexp(n,k)+modexp(n-1,n-1)*2+modexp(n,n);
        ans=(ans+mo)%mo;
        cout<<ans<<"\n";
        cin>>n>>k;
    }
}






