#include"iostream"
#include"string"
#include"cmath"
#include"vector"
#include"algorithm"
using namespace std;
typedef long long ll;
void tot(string x,ll i,vector<ll>& table,ll n)
{
	if(table[i]>0)
		return;
	if(i==n-1)
	{
		if(x[i]!='0')
			table[i]=1;
		else table[i]=0;
		return;
	}
	if(i==n)
	{
		table[i]=1;
		return;
	}
	char ch=x[i];
	if(ch=='0')
	{
		table[i]=0;
		return;
	}
	tot(x,i+1,table,n);
	table[i]+=table[i+1];
	char ch2=x[i+1];
	if(ch=='1'||(ch=='2'&&ch2<55))
    {
		tot(x,i+2,table,n);
        table[i]+=table[i+2];
	}


}
int main()
{
	string x;
	while(cin>>x)
	{
		if("0"==x)
			return 0;
		ll n=x.length();
		vector<ll>table(n+1,0);
		tot(x,0,table,n);
		cout<<table[0]<<endl;
	}
}
