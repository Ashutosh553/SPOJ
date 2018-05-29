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
#include"assert.h"
using namespace std;
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
vector<list<int> >adj;
int col[2005],dep[2005];
void H(int c)
{
    cout<<"Scenario #"<<c<<":\n";
    cout<<"Suspicious bugs found!\n";
}
void S(int c)
{
    cout<<"Scenario #"<<c<<":\n";
    cout<<"No suspicious bugs found!\n";
}
bool dfs(int v,int p,int x)
{
    col[v]=1;
    dep[v]=x;
    bool a=true;
    for(int vert:adj[v])
    {
        if(vert==p)continue;
        if(col[vert]==1&&(x-dep[vert]+1)%2==1)
        {
            a=false;
        }
        if(col[vert]==0)
        {
            bool b=dfs(vert,v,x+1);
            if(a)
            {
                a=b;
            }
        }
    }
    col[v]=2;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    int cas=1;
    while(t--)
    {
        int n,m;cin>>n>>m;
        adj.clear();
        adj.resize(n);
        for(int i=0;i<m;++i)
        {
            int u,v;
            cin>>u>>v;
            --u;--v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        mset(col,0);
        mset(dep,-1);
        bool a=true;
        for(int i=0;i<n;++i)
        {
            if(!col[i])
            {
                a=dfs(i,0,-1);
                if(!a)
                {
                    H(cas++);
                    break;
                }
            }
        }
        if(a)
        {
            S(cas++);
        }
    }
}
