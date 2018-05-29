#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
struct inte
{
    int a,b;
    bool operator<(const inte & ob)const
    {
        return a<ob.a;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<inte>start(n);
        for(int i=0;i<n;++i)
        {
            inte ob;cin>>ob.a;cin>>ob.b;
            start[i]=ob;
        }
        sort(start.begin(),start.end());
        int maxn=0;
        for(int i=0;i<n;++i)
        {
            int tmax=0;
            for(int j=0;j<=i;++j)
            {
                if(start[j].b>start[i].a)
                    ++tmax;
            }
            maxn=max(maxn,tmax);
        }
        cout<<maxn<<'\n';
    }
}
