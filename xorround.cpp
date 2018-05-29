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
int rec[510];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        for(int i=0;i<n;++i)
        {
            cin>>rec[i];
        }
        if(k%2==0)
        {
            k=2;
        }
        else k=1;
        for(int i=0;i<n;++i)
        {
            cout<<(rec[i]^(rec[(i-k+n)%n]^rec[(i+k)%n]))<<' ';
        }
        cout<<'\n';
    }
}
