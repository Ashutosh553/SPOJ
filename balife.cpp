#include"iomanip"
#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
using namespace std;
typedef long long ll;
ll rec[9000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        int n;cin>>n;
        if(n==-1)break;
        ll sum=0,maxn=0;
        vector<int>posn;
        for(int i=0;i<n;++i)
        {
            cin>>rec[i];sum+=rec[i];
            if(rec[i]>maxn)
            {
                maxn=rec[i];
            }
        }
        for(int i=0;i<n;++i)
            if(rec[i]==maxn)
                posn.push_back(i);
        if(n==1)
        {
            cout<<"0\n";continue;
        }
        if(sum%n!=0)
        {
            cout<<"-1\n";continue;
        }
        ll conv=sum/n;
        ll ans=0;
        for(int k=0;k<posn.size();++k)
        {
            ll l=0,r=0;
            for(int i=0;i<posn[k];++i)
            {
                l+=conv-rec[i];
            }
            for(int i=posn[k]+1;i<n;++i)
            {
                r+=conv-rec[i];
            }
            ans=max(ans,max(l,r));
        }
        cout<<ans<<'\n';
    }
}
