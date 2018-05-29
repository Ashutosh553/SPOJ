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
        int a,b;cin>>a>>b;
        vector<ll>f(a),g(b);
        for(int i=0;i<a;++i)
            cin>>f[i];
        for(int i=0;i<b;++i)
            cin>>g[i];
        sort(f.begin(),f.end());
        sort(g.begin(),g.end());
        int i=0,j=0;
        while(i<a&&j<b)
        {
            if(f[i]>=g[j])
                ++j;
            else ++i;
        }
        if(j==b)
            cout<<"Godzilla\n";
        else cout<<"MechaGodzilla\n";
    }
}
