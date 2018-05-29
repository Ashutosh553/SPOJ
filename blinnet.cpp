#include"iomanip"
#include"iostream"
#include"limits"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"queue"
#include"stack"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
#include"cstring"
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
ll pare[maxn];
ll find(ll x)
{
    return pare[x]==x?x:pare[x]=find(pare[x]);
}
void merge(ll x,ll y)
{
    pare[find(x)]=find(y);
}
struct edge
{
    ll cost,a,b;
    bool operator<(const edge & ob)const
    {
        return cost<ob.cost;
    }
};
vector<edge>ed;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;++i)
        {
            pare[i]=i;
        }
        ed.clear();
        for(int i=1;i<=n;++i)
        {
            string x;cin>>x;
            int q;cin>>q;
            while(q--)
            {
                ll b,c;cin>>b>>c;
                edge ob;
                ob.a=i;ob.b=b;ob.cost=c;
                ed.push_back(ob);
            }
        }
        sort(ed.begin(),ed.end());
        ll ans=0;
        for(int i=0;i<ed.size();++i)
        {
            ll c1=ed[i].a,c2=ed[i].b,co=ed[i].cost;
            if(find(c1)!=find(c2))
            {
                merge(c1,c2);ans+=co;
            }
        }
        cout<<ans<<'\n';
    }
}








