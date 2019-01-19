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

const int maxn=1e6+5;
int cnt[maxn],answer=0;
int ans[maxn];
struct qqu
{
    int L,R,i;
    qqu(int a,int b,int c):
        L(a),R(b),i(c)
    {

    }
    inline bool operator<(const qqu & ob)const
    {
        return R<ob.R;
    }
};
vector<qqu>queries[maxn/10];
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>re(n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&re[i]);
    }
    int q;
    scanf("%d",&q);
    int sqm = n/sqrt(q)+2;
    for(int i=0;i<q;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        int wans=0;
        if(x/sqm==y/sqm)
        {
            list<int>in;
            for(int i=x;i<=y;++i)
            {
                if(cnt[re[i]]==0)
                {
                    wans++;
                    cnt[re[i]]++;
                    in.pb(re[i]);
                }
            }
            for(int x:in)cnt[x]--;
            ans[i]=wans;
            continue;
        }
        queries[x/sqm].pb(qqu(x,y,i));
    }
    for(int i=0;i<=n/sqm;++i)
    {
        if(queries[i].empty())continue;
        sort(all(queries[i]));
        int ind= (i+1)*sqm;
        mset(cnt,0);
        answer=0;
        for(auto &q:queries[i])
        {
            while(ind<=q.R)
            {
                if(cnt[re[ind]]==0)
                    answer++;
                cnt[re[ind]]++;
                ind++;
            }
            int answer1=0;
            list<int>in;
            for(int j=(i+1)*sqm-1;j>=q.L;--j)
            {
                if(cnt[re[j]]==0)
                {
                    cnt[re[j]]++;
                    answer1++;
                    in.pb(re[j]);
                }
            }
            for(int x:in)cnt[x]--;
            ans[q.i]=answer+answer1;
        }
    }
    for(int i=0;i<q;++i)
    {
        cout<<ans[i]<<'\n';
    }
}








