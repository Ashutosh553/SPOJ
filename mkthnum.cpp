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
int ma[maxn];
int re[maxn];
int cnt[maxn];

struct pseg
{
    int sum;
    pseg *l,*r;
    pseg():l(NULL),r(NULL)
    {
        ;
    }
    pseg(int s):sum(s),l(NULL),r(NULL)
    {
        ;
    }
    void build(int tl,int tr)
    {
        if(tl==tr)
        {
            sum=cnt[tl];
            return ;
        }
        int tm=(tl+tr)/2;
        l=new pseg();
        r=new pseg();
        l->build(tl,tm);
        r->build(tm+1,tr);
        sum=l->sum+r->sum;
    }
    pseg* update(pseg lef,int tl,int tr,int pos)
    {
        if(tl==tr)
        {
            sum=cnt[tl];
            return this;
        }
        int tm=(tl+tr)/2;
        if(pos<=tm)
        {
            r=lef.r;
            assert(lef.l!=NULL);
            l=new pseg();
            l=l->update(*lef.l,tl,tm,pos);
            sum=(l->sum)+(r->sum);
            return this;
        }
        else
        {
            l=lef.l;
            r=new pseg();
            r=r->update(*lef.r,tm+1,tr,pos);
            sum=(l->sum)+(r->sum);
            return this;
        }
    }
};
pseg se[maxn];
int n;
int query(int i,int j,int k)
{
    int le=0,ri=n-1;
    pseg l=se[i-1],r=se[j];
    while(le<ri)
    {
        int tm=(le+ri)/2;
        assert(r.l!=NULL);
        int co=r.l->sum-l.l->sum;
        if(k<=co)
        {
            l=*l.l;
            r=*r.l;
            ri=tm;
        }
        else
        {
            l=*l.r;
            r=*r.r;
            le=tm+1;
            k-=co;
        }
    }
    return ma[le];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>n>>m;
    vector<pii> rec(n);
    for(int i=0;i<n;++i)cin>>rec[i].ff,rec[i].ss=i;
    sort(all(rec));
    for(int i=0;i<n;++i)
    {
        ma[i]=rec[i].ff;
        re[rec[i].ss]=i;
    }
    se[0].build(0,n-1);
    for(int i=0;i<n;++i)
    {
        cnt[re[i]]++;
        se[i+1].update(se[i],0,n-1,re[i]);
        assert(se[i].l!=NULL);
        //cout<<se[i+1].sum<<' '<<i+1<<" se[i].sum i\n";
    }
    while(m--)
    {
        int i,j,k;
        cin>>i>>j>>k;
        int ans=query(i,j,k);
        cout<<ans<<'\n';
    }
}
