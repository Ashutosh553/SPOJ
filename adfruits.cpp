#include"iostream"
#include"cmath"
#include"string"
#include"algorithm"
#include"vector"
using namespace std;
typedef long long ll;
void slcs(string x,string y,ll i,ll j,ll l1,ll l2,vector<vector<string> >& table)
{

	if(table[i][j]!="")
		return;
	if(j==l2)
	{
		table[i][j]=x.substr(i);
		return;
	}
	if(i==l1)
	{
		table[i][j]=y.substr(j);
		return;
	}
	if(x[i]==y[j])
	{
		string temp="";temp.push_back(x[i]);
		slcs(x,y,i+1,j+1,l1,l2,table);
		table[i][j]= temp+table[i+1][j+1];
		return;
	}
	slcs(x,y,i+1,j,l1,l2,table);
	slcs(x,y,i,j+1,l1,l2,table);
	if(table[i+1][j].length()<table[i][j+1].length())
	{
		string temp="";temp.push_back(x[i]);
		table[i][j]= temp+table[i+1][j];
		return;
	}
	else 
	{
		string temp="";temp.push_back(y[j]);
		table[i][j]=temp+table[i][j+1];
		return;
	}
}
int main()
{
	string x,y;
	while(cin>>x)
	{
		cin>>y;
		ll l1=x.length(),l2=y.length();
		vector<string> ab(l2+1,"");
		vector<vector<string> > table(l1+1,ab);
		slcs(x,y,0,0,l1,l2,table);
		cout<<table[0][0]<<endl;
	}
}
