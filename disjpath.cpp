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
#include"map"
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


#define INF 2100000000
struct edge
{
    int a,b;ll cap,flow; int back;
    edge(int a,int b,int c,int d,int e):
        a(a),b(b),cap(c),flow(d),back(e)
    {

    }
};
struct max_flow
{
    vector<vector<edge> >g;
    vector<ll>ex;
    vector<int>h;
    vector<int>maxh;
    vector<int>count;
    vector<int>mark;
    vector<int>next;
    int size;
    ll flow=-1;
    max_flow(int n):
        g(n),ex(n),h(n),maxh(n),count(2*n),size(0),mark(n),next(n)
    {
    }
    void addEdge(int a,int b,int cap)
    {
        if(a!=b)
        {
            g[a].pb(edge(a,b,cap,0,g[b].size()));
            g[b].pb(edge(b,a,0,0,g[a].size()-1));
        }
    }
    ll maximum_flow(int s,int t)
    {
        h[s]=g.size();
        count[g.size()]++;
        count[0]=g.size()-1;
        for(int i=0;i<g[s].size();++i)
        {
            if(g[s][i].cap>g[s][i].flow)
            {
                g[s][i].flow+=g[s][i].cap;
                g[g[s][i].b][g[s][i].back].flow=-g[s][i].cap;
                ex[g[s][i].b]+=g[s][i].flow;
            }
        }
        for(;;)
        {
            if(!size)
            {
                for(int i=0;i<g.size();++i)
                {
                    if(i!=s&&i!=t&&ex[i]>0)
                    {
                        if(size&&h[i]>maxh[0])
                            size=0;
                        if(!size||h[i]==h[maxh[0]])
                            maxh[size++]=i;
                    }
                }
            }
            if(!size)
                break;
            for(;size>0;)
            {
                int v=maxh[size-1];
                int ok=0;
                for(int j=0;j<g[v].size()&&ex[v]>0;++j)
                {
                    if(h[v]==h[g[v][j].b]+1)
                    {
                        int tob=min(g[v][j].cap-g[v][j].flow,ex[v]);
                        if(tob>0)
                        {
                            g[v][j].flow+=tob;
                            g[g[v][j].b][g[v][j].back].flow=-g[v][j].flow;
                            ex[v]-=tob;
                            ex[g[v][j].b]+=tob;
                            ok=1;
                        }
                        if(ex[v]==0)
                        {
                            size--;
                        }
                    }
                }
                if(!ok)
                {
                    if(count[h[v]]==1)
                    {
                        int k=h[v];
                        for(int i=0;i<g.size();++i)
                        {
                            if(h[i]>=k)
                            {
                                count[h[i]]--;
                                h[i]=max(h[i],(int)g.size()+1);
                                count[h[i]]++;
                            }
                        }
                        size=0;
                    }
                    else
                    {
                        count[h[v]]--;
                        h[v]=INF;
                        for(int i=0;i<g[v].size();++i)
                        {
                            if(g[v][i].flow<g[v][i].cap)
                            {
                                h[v]=min(h[v],h[g[v][i].b]+1);
                            }
                        }
                        count[h[v]]++;
                        if(h[v]>h[maxh[0]])
                        {
                            size=0;
                            break;
                        }
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0;i<g[s].size();++i)
        {
            ans+=g[s][i].flow;
        }
        flow=ans;
        return ans;
    }
    int dfs(int s,int t)
    {
        mark[s]=1;
        if(s==t)
        {
            return 1;
        }
        for(int i=0;i<g[s].size();++i)
        {
            int v=g[s][i].b;
            if(mark[v]==0&&g[s][i].flow>0&&dfs(v,t))
            {
                next[s]=v;
                g[s][i].flow--;
                return 1;
            }
        }
        return false;
    }
};

int main()
{
    int k,n;
    int cas=1;
    while(1)
    {
        scanf("%d%d",&k,&n);
        if(k==0&&n==0)break;
        max_flow ob(2*n);
        for(int i=0;i<n;++i)
        {
            while(1)
            {
                int x;
                char ch;
                scanf("%d%c",&x,&ch);
                ob.addEdge(i+n,x-1,1);
                if(ch=='\n')break;
            }
            ob.addEdge(i,i+n,1);
        }
        if(ob.maximum_flow(0+n,1)<k)
        {
            printf("Case %d:\nImpossible\n\n",cas++);
            continue;
        }
        printf("Case %d:\n",cas++);
        while(k--)
        {
            ob.mark.assign(ob.g.size(),0);
            int cur=0+n;
            printf("%d ",cur-n+1);
            ob.dfs(cur,1);
            while(1)
            {
                cur=ob.next[cur];
                if(cur<n)
                    printf("%d ",cur+1);
                if(cur==1)break;
            }
            printf("\n");
            continue;
            vector<int>mark(2*n);
            mark[cur]=1;
            int len=0;
            while(cur!=1&&cur!=1+n)
            {
                len++;
                assert(len<2*n+200);
                for(int i=0;i<ob.g[cur].size();++i)
                {
                    int v=ob.g[cur][i].b;
                    if(mark[v]==0&&ob.g[cur][i].flow>0)
                    {
                        mark[v]=1;
                        ob.g[cur][i].flow--;
                        if(v<n)
                        {
                            printf("%d ",v+1);
                        }
                        cur=v;
                        break;
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}
