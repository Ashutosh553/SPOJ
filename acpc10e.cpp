#include"iostream"
#include"cmath"
using namespace std;
typedef long long ll;
int main()
{
    ll g,t,a,d;cin>>g>>t>>a>>d;
    while(g!=-1)
    {
        ll x=g*t*(t-1)/2;
        ll low=g*a+d;
        ll n;
        for(n=0;;++n)
        {
            if(low<=(1LL<<n))
                break;
        }
        ll y=(1LL<<n)-low;
        x+=(1LL<<n)-1;
        cout<<g<<"*"<<a<<"/"<<t<<"+"<<d<<"="<<x<<"+"<<y<<endl;
        cin>>g>>t>>a>>d;
    }
}
