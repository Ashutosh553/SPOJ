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
		start<a1.start;
	}
};
/*
bool cmp(const activ& a,const activ& b)
{
	return a.start<b.start;
}
*/
int main()
{
	vector<activ> a;
	a.push_back(activ(4,10));
	a.push_back(activ(13,25));
	a.push_back(activ(13,25));
	a.push_back(activ(14,25));
	activ pseudo=activ(13,100);
	sort(a.begin(),a.end());
	cout<<a[0].start<<"  "<<a[0].end<<endl;
	vector<ll> b;
	b.push_back(1);	b.push_back(2);	b.push_back(3);	b.push_back(4);	b.push_back(5);
	sort(b.begin(),b.end());
	cout<<b[0]<<" "<<b[1]<<endl;
//	cout<<upper_bound(a.begin(),a.end(),pseudo,cmp)-a.begin()<<endl;
}
