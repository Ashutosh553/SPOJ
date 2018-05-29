#include"iostream"
#include"cmath"
#include"string"
#include"algorithm"
#include"vector"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;cin>>s;
        int len=s.length();
        vector< vector<int> >dp(len+1,vector<int>(len+1,-1));
        for(int i=len-1;i>=0;--i)
        {
            for(int j=i;j<len;++j)
            {
                if(i==j)
                    dp[i][j]=0;
                else if(s[i]==s[j])
                {
                    if(j-i==1)
                        dp[i][j]=0;
                    else
                        dp[i][j]=dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=min(1+dp[i+1][j],1+dp[i][j-1]);
                }
            }
        }
        cout<<dp[0][len-1]<<endl;
    }
}
