#include"iostream"
#include"cmath"
using namespace std;
typedef long long ll;
int main()
{
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll sum=0;
        for(int k=1;k<=n;++k)
        {
            ll a;cin>>a;
            sum+=a*(2*k-1-n);
        }
        cout<<sum<<endl;
    }
}
