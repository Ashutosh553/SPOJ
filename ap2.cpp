#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        ll x1,x2,s;cin>>x1>>x2>>s;
        ll n=2*s/(x1+x2);
        ll d=(x2-x1)/(n-5);
        ll a=x1-2*d;
        cout<<n<<'\n';
        for(int i=0;i<n-1;++i)
        {
            cout<<a+i*d<<" ";
        }
        cout<<a+(n-1)*d<<'\n';
    }
}
