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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        int l=s.length();
        string maxn=s;int posn=0;
        for(int i=0;i<l;++i)
        {
            string temp=s.substr(i)+s.substr(0,i);
            if(temp<maxn)
            {
                posn=i;
                maxn=temp;
            }
        }
        cout<<posn+1<<'\n';
    }
}
