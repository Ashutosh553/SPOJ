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
        string x;cin>>x;
        int len =x.length();
        bool a=true;
        for(int i=0;i<len;i++)
        {
            if(x[i]!=x[len-1-i])
            {
                a=false;break;
            }
        }
        if(a)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}
