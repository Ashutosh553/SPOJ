#include "iostream"
#include"vector"
#include"algorithm"
using namespace std;
int main() {
	int n=3000;
	    bool a[n];
    for(int i=0;i<n;i++)
    a[i]=true;
    int p=2;
    while(p<n)
    {
        if(a[p])
        {
            
	    for(int i=2;p*i<n;i++)
            {
                a[p*i]=false;
                
            }
        }
        p++;
    }
    vector<int> b;
    b.push_back(2);
    int i=3;
    while(i<n)
    {
    	if(a[i])
    	{
    		b.push_back(i);
    	}
    	i+=2;
    }
    int lucky[1001];
    i=1;
    int k=30;
    while(i<=1000)
    {
    	int fac=0,j=0;
    	while (b[j]<=k)
    	{
    		if(k%b[j]==0)
    			fac++;
    		j++;
    		if(fac==3)
    		{
    			lucky[i]=k;
    			i++;
    			break;
    		}	
    	}
    	k++;
    }
        int t;
        cin>>t;
        while(t--)
        {
        	int n;
        	cin>>n;
        	cout<<lucky[n];
        	if(t)
        	cout<<endl;
        }
	return 0;
}
