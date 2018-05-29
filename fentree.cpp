#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int n;
ll bit[maxn],arr[maxn];
void upd(int x,int chan)
{
		for(int i=x;i<=n;i+=(i&(-i)))
				bit[i]+=chan;
}
ll quer(int x)
{
		ll sum=0;
		for(int i=x;i>0;i-=(i&(-i)))
				sum+=bit[i];
		return sum;
}
int main()
{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
				ll x;
				cin>>x;
				arr[i]=x;
				upd(i,x);
		}
		int q;
		cin>>q;
		while(q--)
		{
				char ch;
				int x,y;
				cin>>ch>>x>>y;
				if(ch=='q')
						cout<<quer(y)-quer(x-1)<<'\n';
				else
				{
						upd(x,y);
						arr[x]=y;
				}
		}
}
