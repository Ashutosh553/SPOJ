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
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        vector<int>rec(n);
        for(int i=0;i<n;++i)
        {
            cin>>rec[i];
        }
        sort(rec.begin(),rec.end());
        int min1=1e9;
        for(int m=n-1;m-(k-1)>=0;m--)
        {
            min1=min(min1,rec[m]-rec[m-(k-1)]);
        }
        cout<<min1<<'\n';
    }
}
