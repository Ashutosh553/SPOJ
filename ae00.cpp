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
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(n/i>=(i-1))
            ans+=n/i-(i-1);
    }
    cout<<ans<<endl;
}
