#include <iostream>
#include<cmath>
#include"vector"
using namespace std;
vector<long long> inverse(long long a,long long b)
{
vector<long long>v;
if(b==0)
{
v.push_back(a);v.push_back(1);v.push_back(0);
return v;
} 
v=inverse(b,a%b);
long long x=v[1];
v[1]=v[2];
v[2]=x-(a/b)*v[2];
return v;

}
int main() {
    long long t;cin>>t;
    while(t--)
    {
        long long m,n;cin>>m>>n;
        long long k=1000000007;
        long long x=1,y=m;
        long long inv=(inverse(m-1,k)[1]+k)%k;
        long long b=n;
        while(b!=0)
        {
		if(b%2==1)
		x=(x*y)%k;
                y=(y*y)%k;b/=2;
        }
	y=x;
 	x=((x-1)*inv+k)%k;
        cout<<x<<" "<<y<<endl;
        
    }
	return 0;
}

