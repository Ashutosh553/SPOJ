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
typedef long double ld;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
    ll n;cin>>n;
    if(n%2)
        cout<<((n-1)>>1);
    else
    {
        n/=2;--n;
        if(n%2)cout<<n;else cout<<n-1;
    }
    cout<<'\n';
    }
}
