#include"iostream"
#include"cmath"
using namespace std;
void cuberoot(double x)
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
int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		long r,h;
		cin>>r>>h;
		long double p=6*sqrt(r*r+h*h)*h*h/r;
		if(36*(r*r+h*h)>h*h*r*r)
		cout<<h<<"."<<"000000";
		else 
		cuberoot(p);
		if(n>0)
		cout<<endl;
	}
}
