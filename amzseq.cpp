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
    int n=25;
    ll a[n],b[n],c[n];
    a[1]=1;b[1]=1;c[1]=1;
    for(int i=2;i<n;++i)
    {
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i]+c[i-1];
        c[i]=b[i]-a[i-1];
    }
    int k;cin>>k;
    cout<<a[k]+b[k]+c[k]<<'\n';
}
