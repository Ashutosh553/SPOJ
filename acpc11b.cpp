#include"iostream"
#include"cmath"
#include"algorithm"
#include"vector"
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n1;cin>>n1;
        vector<int>row1(n1);
        for(int i=0;i<n1;++i)
        {
            cin>>row1[i];
        }
        sort(row1.begin(),row1.end());
        int n2;cin>>n2;
        int min1=1e9;
        for(int i=0;i<n2;++i)
        {
            int x;cin>>x;
            vector<int>::iterator it=lower_bound(row1.begin(),row1.end(),x);
            if(it==row1.end())
                min1=min(min1,x-row1[n1-1]);
            else if((*it)==x)
            {
                min1=0;
                continue;
            }
            else if(it==row1.begin())
            {
                min1=min(min1,row1[0]-x);
            }
            else
            {
                min1=min(min1,*it-x);
                min1=min(min1,x-*(it-1));
            }
        }
        cout<<min1<<endl;
    }
}
