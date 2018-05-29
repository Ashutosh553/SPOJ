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
    string s1,s2;cin>>s1>>s2;
    while(s1[0]!='*')
    {
        int ans=0,i=0,j=0;
        while(i<s1.length())
        {
            if(s1[i]!=s2[j])
            {
                ++ans;
                while(s1[i]!=s2[j])
                {
                    ++i;++j;
                }
            }
            ++i;++j;
        }
        cout<<ans<<'\n';
        cin>>s1>>s2;
    }
}
