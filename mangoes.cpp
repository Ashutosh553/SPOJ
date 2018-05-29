#include"iostream"
#include"vector"
#include"cmath"
#include"algorithm"
using namespace std;
typedef long long ll;
int main()
{
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll k=(n-2+1)/2;
        cout<<(k*k)%n<<endl;
    }
}
