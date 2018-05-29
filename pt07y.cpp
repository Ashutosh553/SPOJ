#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
#include"list"
using namespace std;
typedef long long ll;
int tim=0,coun=0;
struct vertex
{
    int n,c,s,e;
    list<int>adj;
    vertex()
    {
        c=0;
    }
};
bool dfs(int i,int curr,vector<vertex>&V)
{
    coun++;
    V[i].c=1;
    V[i].s=tim++;
    for(auto it=V[i].adj.begin();it!=V[i].adj.end();it++)
    {
        if(*it==curr)
            continue;
        bool a=true;
        if(V[*it].c==0)
        {
            a=dfs(*it,i,V);
            if(!a)
                return false;
        }
        else return false;
    }
    V[i].e=tim++;
    V[i].c=2;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    if(m!=n-1)
    {
        cout<<"NO\n";
        return 0;
    }
    vector<vertex>V(n);
    for(int i=0;i<n;++i)
    {
        vertex ob;
        ob.n=i;
        V[i]=ob;
    }
    for(int i=0;i<m;++i)
    {
        int a,b;cin>>a>>b;--a;--b;
        if(a==b)
        {
            cout<<"NO\n";return 0;
        }
        V[a].adj.push_back(b);
        V[b].adj.push_back(a);
    }
    bool ans=dfs(0,-1,V);
    if(ans&&coun==n)
    {
        cout<<"YES\n";
    }
    else cout<<"NO\n";
}
