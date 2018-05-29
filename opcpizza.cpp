#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
int rec[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        for(int i=0;i<n;++i)
            cin>>rec[i];
        sort(rec,rec+n);
        ll ans=0;
        for(int i=0;i<n;++i)
        {
            int* pos=lower_bound(rec,rec+n,m-rec[i]);
            if(pos!=rec+n&&*pos==m-rec[i])
                ++ans;
        }
        cout<<(ans>>1)<<'\n';
    }
}
