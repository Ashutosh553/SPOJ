#include<iostream>
using namespace std;
int main()
{	
	
	long double x;

	while(cin>>x)
	{
		x*=1000;
		long double y=x/2;
		int i=40;
		while(i--)
		{
			y=2*y/3.0+x/3/(y*y);
		}
		y*=100000;
		int k=y;
		cout<<k/1000000<<"."<<k%1000000;
	}
}
