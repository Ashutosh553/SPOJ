#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
#include"unordered_set"
using namespace std;
typedef long long ll;
int pile[100011],grundy[100011],rule[31],n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<m;++i)
            cin>>rule[i];
        sort(rule,rule+m);
        int max1=0;
        for(int i=0;i<n;++i)
        {
            cin>>pile[i];
            max1=max(max1,pile[i]);
        }
        grundy[0]=0;
        for(int i=1;i<=max1;++i)
        {
            int mask=0;
            for(int k=0;k<m&&rule[k]<=i;++k)
            {
                mask=mask|1<<grundy[i-rule[k]];
            }
            int f=0;
            while((1<<f&mask)!=0)
                ++f;
            grundy[i]=f;
        }
        int res=grundy[pile[0]];
        for(int i=1;i<n;++i)
        {
            res=res^grundy[pile[i]];
        }
        if(res==0)
        {
            cout<<"Vinit\n";
        }
        else cout<<"Ada\n";
    }
}
