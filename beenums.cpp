#include"iomanip"
#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
    while(n!=-1)
    {
        ll l=0,h=n,temp,m;
        while(l<=h)
        {
            m=(h-l)/2+l;
            temp=3*m*m+3*m+1;
            if(temp==n)
            {
                break;
            }
            else if(temp<n)
            {
                l=m+1;
            }
            else h=m-1;
        }
        if(temp==n)
        {
            cout<<"Y\n";
        }
        else cout<<"N\n";
        cin>>n;
    }
}






