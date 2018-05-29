#include"iostream"
#include"cmath"
#include"string"
#include"vector"
#include"algorithm"
using namespace std;
typedef long long ll;
ll toll(string x)
{
    ll len=x.length(),ans=0,po=1;
    for(int i=len-1;i>=0;--i)
    {
        char ch=x[i];int x=ch;x-=48;
        ans+=po*x;
        po*=10;
    }
    return ans;
}
void print(ll x,ll y,ll z)
{
    cout<<x<<" + "<<y<<" = "<<z<<endl;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string x,y,z;
        cin>>x>>y>>y>>z>>z;
        if(x.find("machula")!=string::npos)
        {
            ll z1=toll(z),y1=toll(y);
            ll ans=z1-y1;
            print(ans,y1,z1);
        }
        else if(y.find("machula")!=string::npos)
        {
            ll x1=toll(x),z1=toll(z);
            ll ans=z1-x1;
            print(x1,ans,z1);
        }
        else
        {
            ll x1=toll(x),y1=toll(y);
            ll ans=x1+y1;
            print(x1,y1,ans);
        }

    }
}
