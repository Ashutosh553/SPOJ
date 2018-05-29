#include <iostream>
#include<vector>
#include"cmath"
using namespace std;
typedef long long ll;
int main() {
	ll T;cin>>T;
	for(ll i=0;i<T;i++)
	{
		ll N,M;
		cin>>N>>M;
		ll A[N];
		for(ll j=0;j<N;j++)
		{
			cin>>A[j];
		}
		/*
		vector<ll>hap(n);
		for(ll k=0;k<N;i++)
		{
			ll c,d;
			for( c=k-1;c>=l-1;c--)
			if(A[c]<A[k])break;
			for(d=k+1;d<=r-1;d++)
			if(A[d]<A[k])break;
			happ[k]=(k-c)*(d-k);
			happ[k]+=happ[k-1];
		}
		*/
		cout<<"Case "<<i+1<<":"<<endl;
		for(ll j=0;j<M;j++)
		{
			ll l,r,sum=0;
			cin>>l>>r;
			for(ll k=l-1;k<r;k++)
			{
				ll c,d;
				for( c=k-1;c>=l-1;c--)
				if(A[c]<A[k])break;
				for(d=k+1;d<=r-1;d++)
				if(A[d]<A[k])break;
				sum+=(k-c)*(d-k);
			}//query
			cout<<sum<<endl;
			
		}//for M queries
		
		
		
	}//while T
	
	return 0;
}
