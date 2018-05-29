#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
int rec[100005],t,n,c;
bool poss(int mid)
{
    int curr=1,last=rec[0],pos;
    for(pos=1;pos<n;++pos)
    {
        if(rec[pos]-last<mid)
        {
            ;
        }
        else
        {
            last=rec[pos];
            curr++;
        }
        if(curr>=c)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>c;
        for(int i=0;i<n;++i)
        {
            cin>>rec[i];
        }
        sort(rec,rec+n);
        int low=0,high=rec[n-1]-rec[0];
        int mid;
        if(c==2)
            low=high;
        else
        while(low<high-1)
        {
            mid=low+(high-low)/2;
            if(poss(mid))
            {
                low=mid;
            }
            else
            {
                high=mid;
            }            
        }
        cout<<low<<"\n";
    }
}


























