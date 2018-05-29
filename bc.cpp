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
ll solve(ll n)
{
    ll ans=1,count=0,vol=n;
    while(ans<vol)
    {
        ans<<=1;
        count++;
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    int c=1;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        cout<<"Case #"<<c++<<": "<<n*m*k-1<<" "<<solve(n)+solve(m)+solve(k)<<'\n';
    }
}
