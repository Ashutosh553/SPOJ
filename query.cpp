#include <iostream>
using namespace std;

int main() {
	
	int N,Q,sum=0;cin>>N;
	
	int A[N];
	for (int i=0;i<N;i++)
	cin>>A[i];
	cin>>Q;
	int query[2][Q];
	for(int i=0;i<Q;i++)
	{
		cin>>query[0][i];
		cin>>query[1][i];
	}
	for(int i=0;i<Q;i++)
	{
		
		for(int j=query[0][i]-1;j<query[1][i];j++)
		sum+=A[j];
		cout<<sum<<"\n";
		sum=0;
		
	}
	
	
	
	

	return 0;
}
