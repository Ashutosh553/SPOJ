#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ca=1;;cin>>n;
    while(n!=0)
    {
        vector<int>rec(n,0);
        int prans=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                int x;cin>>x;
                prans+=x;
                rec[i]+=x;
                rec[j]-=x;
            }
        ll ans=0;
        for(int i=0;i<n;++i)
            if(rec[i]>0)
                ans+=rec[i];
        cout<<ca++<<". "<<prans<<" "<<ans<<'\n';
        cin>>n;
    }
}
