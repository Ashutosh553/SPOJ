#include"iostream" 
#include"cmath"
 using namespace std;int main(){int t;cin>>t; while(t--) { long long a;cin>>a;long long b,up=a*a+1,min1=1e14;for(b=1;b<=a;++b) { if(up%b==0) min1=min(min1,b+up/b); } cout<<2*a+min1<<'\n'; } }
