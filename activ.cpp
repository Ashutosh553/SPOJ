#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"string"
using namespace std;
typedef long long ll;
ll mo=1e8;
struct activ
{
	ll start,end;
	activ(){;}
	activ(ll x,ll y)
	{
		start=x;end=y;
	}
	bool operator<(const activ& a1)
	{
			return start<a1.start;
	}
};
bool cmp(const activ& a,const activ& b)
{
	return a.start<b.start;
}
void maxset(vector<activ>& act,vector<ll>& table,ll i,ll n)
{
	if(table[i]>0)
		return;
	ll aiend=act[i].end;
	ll aistart=act[i].start;
	if(i==n-1)
	{
		table[i]=1;
		return;
	}
	
	activ pseudo=activ(aiend,23);
	vector<activ>::iterator pt=act.begin()+(i+1),it=upper_bound(pt,act.end(),pseudo,cmp);
	if(it==act.end())
		it--;
	while((*it).start>=aiend&&it!=pt)
		it--;
	while((*it).start<aiend&&it!=act.end())
	{
		it++;
	}
	if(it==act.end())
	{	table[i]=1;
		maxset(act,table,i+1,n);
		table[i]=(table[i]+table[i+1])%mo;
		return;
	}
	ll pos=it-act.begin();
	if(pos<n)
	{
		if(table[pos]>0)
			{
				table[i]=(1+table[pos])%mo;
			}
		else
		{
			maxset(act,table,pos,n);
			table[i]=(1+table[pos])%mo;
		}
	}
	
	if(pos==n)
		table[i]=1;
	maxset(act,table,i+1,n);
	table[i]=(table[i]+table[i+1])%mo;
}
int main()
{
	ll n;
	while(cin>>n)
	{
		if(n!=-1)
		{
			vector<activ> act(n);
			for(int i=0;i<n;i++)
			{
				ll s1,e1;cin>>s1>>e1;
				act[i].start=s1;
				act[i].end=e1;
			}
			sort(act.begin(),act.end());
			vector<ll>table(n,0);
			maxset(act,table,0,n);
			ll ans=table[0];
			if(ans>=1e8)
			{
				cout<<ans%mo;
			}
			else
			{
				string x="";
				while(ans!=0)
				{
					int dig=ans%10;char ch=dig+48;string y="";y.push_back(ch);
					x=y+x;ans/=10;
				}
				for(int i=0;i<8-x.length();i++)
				{
					cout<<0;
				}
				cout<<x<<endl;
			}
		}
		else return 0;
	}
}
