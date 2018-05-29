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
    int t;cin>>t;
    while(t--)
    {
        ll x;char ch;
        cin>>x>>ch;
        ll ans=x;
        while(ch!='=')
        {
            cin>>x;
            switch(ch)
            {
                case '+':
                    ans=ans+x;
                    break;
                case '-':
                    ans=ans-x;
                    break;
                case '*':
                    ans=ans*x;
                    break;
                case '/':
                    ans=ans/x;
                    break;
            }
            cin>>ch;
        }
        cout<<ans<<'\n';
    }
}
