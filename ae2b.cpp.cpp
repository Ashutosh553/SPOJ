#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}
void yes()
{
    cout<<"TAK\n":
}
void no()
{
    cout<<"NIE\n";
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        ll n,k,x1,y1,x,y;cin>>n>>k>>x1>>y1>>x>>y;
        x-=x1;y-=y1;
        x=abs(x);y=abs(y);
        if(x<y)
            swap(x,y);
        if(n==0||k==0)
        {
            if(x%max(n,k)==0&&y%max(n,k)==0)
                yes();
            else no();
        }
        else if(n==k)
        {
            if(x!=y)
                no();
            else
            {
                if(x%n==0)
                    yes();
                else no();
            }
        }
        else
        {
            if((n+k)%2==0)
            {
                bool a=false;
                if((x+y)%2==0)
                    a=true;
                if(!a)
                    no();
                else
                {
                    ll gc=gcd(n,k);

                }
            }
        }
    }
}










