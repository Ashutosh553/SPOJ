#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
const int maxn=1e7;
int a[maxn+5];
ll res[maxn+5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
    for(ll i=0;i<=maxn;i++)
    a[i]=true;
    */
    int p=2;
    while(p<3180)
    {
        if(!a[p])
        {
            
	    for(ll i=1;p*i<maxn+1;i++)
            {
                if(!a[p*i])
                    a[p*i]=p;
            }
        }
        p++;
    }

    for(int i=2;i<=maxn;++i)
    {
        res[i]=res[i-1]+a[i];
        if(!a[i])
            res[i]+=i;
    }
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        cout<<res[n]<<'\n';
    }
}
