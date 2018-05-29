#include "iostream"
#include"vector"
#include"algorithm"
using namespace std;
typedef long long ll;
ll findpos(vector<ll>&b,ll m)
{
	ll low=0,high=b.size(),mid=(low+high)/2;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(b[mid]<m)
			low=mid+1;
		else if(b[mid]>m)
			high=mid-1;
		else return mid;
	}
	mid=mid-4;
	if(mid<0)
		mid=0;
	while(b[mid]<m)
		mid++;
	return mid;
}
int main() {
	ll n=1000000050;
	//ll n=100000;
	    vector<bool> a(n,false);
    for(ll i=2;i<n;i++)
    a[i]=true;
    int p=2;
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
    cout<<b[50]<<endl;
    return 0;
    int t;
	cin>>t;
	while(t--)
	{
		ll m,n;cin>>m>>n;
		ll pos=findpos(b,m);
		for(ll i=pos;;i++)
		{
			ll prime=b[i];
			if(prime>n)
				break;
			cout<<prime<<endl;
		}
		cout<<endl;
	}
	return 0;
}
