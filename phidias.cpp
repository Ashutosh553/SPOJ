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
int w,h,n;
int mw,mh;
vector<pair<int,int> >rec;
const int maxn=605;
int dp[maxn][maxn];
int solve(int w,int h)
{
    auto temp=make_pair(w,h);
    if(w<mw||h<mh)
        return dp[w][h]=(h>=0&&w>=0)?h*w:1e7;
    if(dp[w][h]>=0)
        return dp[w][h];
    /*
    if(temp<rec[0])
        return dp[w][h]=(h>=0&&w>=0)?h*w:1e7;
    int it=lower_bound(rec.begin(),rec.end(),temp)-rec.begin();
    if(it!=n&&rec[it]==temp)
        return dp[w][h]=0;*/
    int ans=1e8;
    for(int i=1;i<w;++i)
    {
        int a1=solve(w-i,h)+solve(i,h);//horizontal cut
        ans=min(ans,a1);
    }
    for(int i=1;i<h;++i)
    {
        int a2=solve(w,i)+solve(w,h-i);//vertical cut
        ans=min(ans,a2);
    }
    return dp[w][h]=ans;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        scanf("%d %d %d",&w,&h,&n);
        rec.clear();
        rec.resize(n);
        memset(dp,-1,sizeof dp);
        mw=1e8;mh=1e8;
        for(int i=0;i<n;++i)
        {
            scanf("%d %d",&rec[i].first,&rec[i].second);
            dp[rec[i].first][rec[i].second]=0;
            mw=min(mw,rec[i].first);
            mh=min(mh,rec[i].second);
        }
        //sort(rec.begin(),rec.end());
        printf("%d\n",solve(w,h));
    }
}
