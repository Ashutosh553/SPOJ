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
ll rec[55];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        ll n,k;cin>>n>>k;
        ll curr=0;
        for(int i=0;i<k;++i)
        {
            ll x;cin>>x;
            rec[i]=x+2*curr;
            curr=rec[i];
        }
        int i=k-1;vector<int>ans;
        while(n>=0&&i>=0)
        {
            if(n>=rec[i])
            {
                n-=rec[i];
                ans.push_back(i+1);
            }
            --i;
        }
        if(n!=0)
        {
            cout<<"-1\n";
        }
        else
        {
            for(int j=ans.size()-1;j>=0;--j)
            {
                cout<<ans[j]<<' ';
            }
            cout<<'\n';
        }
        
    }
}
