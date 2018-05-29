#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        if(n>2&&m>2)
        {
            int x=min(n,m);
            x=(x-1)/2;
            n-=2*x;
            m-=2*x;
        }
        if(n==1)
            cout<<"R\n";
        else if(m==1)
            cout<<"D\n";
        else if(n==2)
        {
            cout<<"L\n";
        }
        else if(m==2)
        {
            cout<<"U\n";
        }
    }
}
