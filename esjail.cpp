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
typedef long double ld;
ll n,m,k;
const int maxn=1e5+10;
map<int,int>dokey,keydo;
vector<list<int> >adj;
bool codo[maxn],cokey[maxn],touch[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while(true)
    {
        cin>>n>>k>>m;
        if(n==-1)break;
        dokey.clear();
        keydo.clear();
        memset(codo,0,sizeof codo);
        memset(cokey,0,sizeof cokey);
        memset(touch,0,sizeof touch);
        for(int i=0;i<k;++i)
        {
            int door,key;cin>>key>>door;
            codo[door-1]=1;
            cokey[key-1]=1;
            dokey[door-1]=key-1;
            keydo[key-1]=door-1;
        }
        if(codo[0])
        {
            cout<<"N\n";
            break;
        }
        adj.clear();
        adj.resize(n);
        for(int i=0;i<m;++i)
        {
            int x,y;cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        set<int>lo;
        set<int>key;
        if(cokey[0])
        {
            key.insert(0);
        }
        queue<int>qq;
        qq.push(0);
        touch[0]=1;
        bool a=false;
        while(!qq.empty())
        {
            int vert=qq.front();
            qq.pop();
            for(int v:adj[vert])
            {
                if(codo[v]&&!touch[v])
                {
                    int kk=dokey[v];
                    if(key.find(kk)!=key.end())
                    {
                        qq.push(v);touch[v]=1;
                        codo[v]=0;
                    }
                    else
                    {
                        lo.insert(v);
                    }
                }
                else if(cokey[v]&&!touch[v])
                {
                    key.insert(v);
                    qq.push(v);
                    touch[v]=1;
                    int dd=keydo[v];
                    if(lo.find(dd)!=lo.end())
                    {
                        lo.erase(dd);
                        qq.push(dd);
                        touch[dd]=1;
                        codo[dd]=0;
                    }
                }
                else if(!touch[v])
                {
                    qq.push(v);touch[v]=1;
                }
            }
            if(touch[n-1])
            {
                //cout<<"Y\n";
                a=true;
                break;
            }
        }
        if(!a)
            cout<<"N\n";
        else cout<<"Y\n";
    }
}





































