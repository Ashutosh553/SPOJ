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
        int n;cin>>n;
        int x;cin>>x;bool a=true;
        for(int i=1;i<n;++i)
        {
            int y;cin>>y;
            if(y<x)
                a=false;
            x=y-x;
        }
        if(a&&x==0)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}
