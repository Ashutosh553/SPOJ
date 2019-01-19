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
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e5+5;
int n;
int dep[maxn],head[maxn],heavy[maxn],pos[maxn],par[maxn];
int rpos[maxn];
list<pii>adj[maxn];
int e1[maxn],e2[maxn],e3[maxn];
int t[4*maxn];
int arr[maxn];
int ind=0;
int dfs(int v)
{
    int ma=-1;
    int tot=1;
    for(pii iter:adj[v])
    {
        int u=iter.ff;
        if(par[v]==u)continue;
        par[u]=v;
        dep[u]=dep[v]+1;
        int sz=dfs(u);
        tot+=sz;
        if(sz>ma)
        {
            ma=sz;
            heavy[v]=u;
        }
    }
    return tot;
}
int decompose(int v,int c)
{
    head[v]=c;
    pos[v]=ind++;
    rpos[ind-1]=v;
    if(heavy[v]!=-1)
    {
        decompose(heavy[v],c);
    }
    for(pii iter:adj[v])
    {
        int u=iter.ff;
        if(par[v]==u||heavy[v]==u)continue;
        decompose(u,u);
    }
}
void build(int v,int tl,int tr)
{
    if(tl==tr)
    {
//        t[v]=arr[tl];
        t[v]=-1;
        return;
    }
    int tm=(tl+tr)/2;
    build(v<<1,tl,tm);
    build(v*2+1,tm+1,tr);
    t[v]=max(t[v<<1],t[v*2+1]);
    //cout<<v<<' '<<t[v]<<' '<<tl<<' '<<tr<<" v tv tl tr\n";
}
int maqu(int v,int l,int r,int tl,int tr)
{
    /*
    if(v==1)
        cout<<l<<' '<<r<<' '<<tl<<' '<<tr<<" l r tl tr"<<endl;
        */
    if(tl==l&&tr==r)
    {  
        //cout<<v<<' '<<t[v]<<" v max "<<l<<' '<<r<<' '<<par[rpos[l]]+1<<' '<<rpos[r]+1<<" l r rpos[l] rpos[r]\n";
        return t[v];
    }
    int tm=(tl+tr)/2;
    if(r<=tm)return maqu(v<<1,l,r,tl,tm);
    if(l>=tm+1)return maqu(v*2+1,l,r,tm+1,tr);
    int x=maqu(v<<1,l,tm,tl,tm),y=maqu(v*2+1,tm+1,r,tm+1,tr);
    if(x==-1)return y;
    else return x;
}
void upd(int v,int tl,int tr,int pos)
{
    if(tl==tr)
    {
        t[v]=arr[pos];
        if(arr[pos]==1)
        {
            t[v]=rpos[pos];
        }
        else
        {
            t[v]=-1;
        }
        return;
    }
    int m=(tl+tr)/2;
    if(pos<=m)
    {
        upd(v<<1,tl,m,pos);
    }
    else
    {
        upd(v*2+1,m+1,tr,pos);
    }
    //t[v]=max(t[v<<1],t[v*2+1]);
    if(t[v<<1]==-1)
    {
        t[v]=t[2*v+1];
    }
    else
    {
        t[v]=t[v<<1];
    }
}
int query(int b)
{
    int a=0;
    int ans=-1;
    int flag=0;
    for(;head[a]!=head[b];b=par[head[b]])
    {
        if(dep[head[a]]>dep[head[b]])swap(a,b);
        int x=pos[head[b]],y=pos[b];
        /*
        for(int i=pos[b];i>=pos[head[b]];--i)
        {
            cout<<rpos[i]+1<<'\n';
        }
        */
        if(x==y)
        {
            //x--;
        }
        if(1)
        {
            int aa=maqu(1,x,y,0,n-1);
            if(aa!=-1)ans=aa;
        }
    }
    if(dep[a]>dep[b])swap(a,b);
    /*
    for(int i=pos[b];i>=pos[a];--i)
    {
        cout<<rpos[i]+1<<"  ext\n";
    }
    */
    int x=pos[a],y=pos[b];
    int aa=max(ans,maqu(1,x,y,0,n-1));
    if(aa!=-1)ans=aa;
    return ans;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t1;
    t1=1;
    while(t1--)
    {
        for(int i=0;i<maxn;++i)
            adj[i].clear();
        mset(e1,0);mset(e2,0);mset(e3,0);
        int q;
        cin>>n>>q;
        for(int i=0;i<n-1;++i)
        {
            int a,b,c;
            cin>>a>>b;
            c=1;
            a--;b--;
            e1[i]=a;
            e2[i]=b;
            e3[i]=c;
            adj[a].pb(mp(b,c));
            adj[b].pb(mp(a,c));
        }
        /*
           int n;
           int dep[maxn],head[maxn],heavy[maxn],pos[maxn],par[maxn];
           list<pii>adj[maxn];
           int e1[maxn],e2[maxn],e3[maxn];
           int t[4*maxn];
           int arr[maxn];
           int ind=0;
         */
        ind=0;
        mset(pos,-1);mset(head,-1);
        mset(dep,0);
        mset(par,-1);mset(heavy,-1);
        mset(arr,0);
        mset(t,0);
        dfs(0);
        decompose(0,0);
        for(int i=0;i<n;++i)
        {
            /*
            int a=e1[i],b=e2[i];
            if(par[b]!=a)swap(a,b);
            a=pos[a];b=pos[b];
            */
            arr[i]=0;
        }
        /*
           vector<pii>rr;
           for(int i=0;i<n;++i)
           rr.pb(mp(pos[i],i+1));
           sort(all(rr));
           for(auto xx:rr)
           {
           cout<<xx.ss<<' ';
           }
           cout<<'\n';
         */
        mset(t,-1);//build(1,0,n-1);
        for(int i=1;i<n;++i)
        {
            //        cout<<par[rpos[i]]+1<<' '<<rpos[i]+1<<' '<<arr[i]<<" a b c\n";
        }
        //       cout<<maqu(1,1,n-1,1,3)<<" maqu(1,3)\n";
        int a,b;
        while(q--)
        {
            cin>>a>>b;
            if(a==0)
            {
                b--;
                int y=pos[b];
                arr[y]=1-arr[y];
                upd(1,0,n-1,y);
            }
            else if(a==1)
            {
                b--;
                int ans=query(b);
                cout<<(ans==-1?-1:ans+1)<<endl;
            }
        }
    }
}
