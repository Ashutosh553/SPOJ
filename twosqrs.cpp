#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"map"
typedef long long ll;
using namespace std;
void y()
{
    cout<<"Yes\n";
}
void no()
{
    cout<<"No\n";
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        if(n==0||n==1||n==2)
        {
            y();continue;
        }
        if(n%2==1&&n%4!=1)
        {
            no();continue;
        }
        ll upper=floor(sqrt(n));bool a=true;
        for(ll i=0;i<=upper;++i)
        {
            ll res=n-i*i;
            ll sqres=sqrt(res);
            if(res==sqres*sqres)
            {
                y();a=false;
                break;
            }
        }
        if(a)
            no();
    }
}

