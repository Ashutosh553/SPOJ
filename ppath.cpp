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
int prime(int x)
{
    if(x<2)
    {
        return false;
    }
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
            return false;
    }
    return true;

}
const int maxn=9999+1;
bool p[maxn];
bool touch[maxn];
int ch(int x,int y)
{
    int c=0;
    for(int i=0;i<4;++i)
    {
        int d1=x%10,d2=y%10;
        if(d1==d2)
            c++;
        x/=10;y/=10;
    }
    if(c==3)
    {
        return true;
    }
    else return false;
}
int lay[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<list<int> >adj(10000);
    vector<int>plist;
    for(int i=1000;i<=9999;++i)
    {
        if(prime(i))
        {
            p[i]=true;
            plist.pb(i);
        }
    }
    plist.resize(plist.size());
    int n=plist.size();
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int aa=plist[i],bb=plist[j];
            if(ch(aa,bb))
            {
                adj[aa].pb(bb);
                adj[bb].pb(aa);
            }
        }
    }
    int t;cin>>t;
    while(t--)
    {
        int x,y;cin>>x>>y;
        if(!p[x]||!p[y])
        {
            cout<<"Impossible\n";
            continue;
        }
        memset(touch,0,sizeof touch);
        queue<int>qq;
        qq.push(x);
        int no=1;
        touch[x]=1;
        lay[x]=0;
        while(!qq.empty())
        {
            int v=qq.front();
            if(lay[v]==no)
                no++;
            qq.pop();
            for(int vert:adj[v])
            {
                if(touch[vert])
                    continue;
                qq.push(vert);
                lay[vert]=no;
                touch[vert]=1;
            }
            if(touch[y])
            {
                break;
            }
        }
        if(touch[y])
        {
            cout<<lay[y]<<'\n';
        }
        else cout<<"Impossible\n";
    }
}
