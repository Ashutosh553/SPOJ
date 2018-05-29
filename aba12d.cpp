#include "iostream"
#include"cmath"
#include"string"
#include"vector"
#include"algorithm"
using namespace std;
typedef long long ll;
int main()
{
	ll n=1e6+1;
	    bool a[n];
    for(ll i=0;i<n;i++)
    a[i]=true;
    ll p=2;
    while(p<n)
    {
        if(a[p])
        {
            
	    for(ll i=2;p*i<n;i++)
            {
                a[p*i]=false;
                
            }
        }
        p++;
    }
    vector<ll> b;
    b.push_back(2);
    ll i=3;
    while(i<n)
    {
    	if(a[i])
    	{
    		b.push_back(i);
    	}
    	i+=2;
    }
    vector<bool>special(1e6+1,false);
    for(ll i=2;i<=1e6;++i)
    {
        int j=0;cout<<"i sad "<<i<<endl;
        while(1)
        {
            ll p=b[j];
            if(i%p!=0)
            {
                ++j;
                continue;
            }
            else
            {
                ll temp=i;
                while(temp%p==0)
                {
                    temp/=p;
                }
                if(temp==1)
                {
                    special[i]=true;break;
                }
                break;
            }
        }
    }
    vector<ll>prefix(1e6+1,0);ll count=0;
    for(int i=0;i<1e6+1;++i)
    {
        if(special[i])
            count++;
        prefix[i]=count;
    }
    ll t;cin>>t;
    while(t--)
    {
        ll a,b;cin>>a>>b;cout<<"sad "<<a<<" "<<b<<endl;
        cout<<prefix[b]-prefix[a-1]<<endl;
    }
}











