#include<iostream>
using namespace std;
int main()
{
int T,trail=0,x;cin>>T;
int A[T];
for(int i=0;i<T;i++)
cin>>A[i];

for(int i=0;i<T;i++)
{
x=A[i];
int c=5;
while(c<=x)
{trail+=x/c;
c*=5;
}
c=5;
cout<<trail<<"\n";
trail=0;
}






}
