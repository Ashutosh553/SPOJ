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
ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        a=a%b;
        swap(a,b);
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll w,h;
    cin>>w>>h;
    while(w!=0)
    {
        ll gc=gcd(h,w);
        cout<<h*w/(gc*gc)<<'\n';
        cin>>w>>h;
    }
}
