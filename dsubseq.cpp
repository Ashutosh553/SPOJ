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
#include"cstring"
using namespace std;
typedef long long ll;
const ll mo=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        string x;cin>>x;
        int len=x.length();
        ll last[100];
        for(int i=0;i<100;++i)
            last[i]=-1;
        ll sum=1,dp;
        for(int i=0;i<len;++i)
        {
            dp=sum;
            if(last[x[i]]!=-1)
                sum=(sum+dp-last[x[i]]+mo)%mo;
            else sum=(sum+dp)%mo;
            last[x[i]]=dp;
        }
        cout<<sum<<'\n';
    }
}
