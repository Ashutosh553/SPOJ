#include<iostream>
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
using namespace std;
typedef long long ll;
int dp[7][1100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t;cin>>n>>t;
    list<int>p[7];//price
    list<int>q[7];//quality
    for(int i=1;i<=n;++i)
    {
        int x,y,z;cin>>x>>y>>z;
        p[x].push_back(y);
        q[x].push_back(z);
    }
    for(int i=6;i>=1;--i)
    {
        for(int j=1001;j>=0;j--)
        {
            if(i==6)
            {
                for(auto it=p[6].begin(),it1=q[6].begin();it!=p[6].end();it++,it1++)
                {
                    int temp=0;
                    if(*it<=j)
                    {
                        temp=*it1;
                    }
                    dp[6][j]=max(dp[6][j],temp);
                }
            }
            else
            {
                dp[i][j]=0;
                for(auto it=p[i].begin(),it1=q[i].begin();it!=p[i].end();it++,it1++)
                {
                    int temp=0;
                    if(*it<=j)
                    {
                        temp=min(*it1,dp[i+1][j-*it]);
                    }
                    dp[i][j]=max(dp[i][j],temp);
                }
            }
        }
    }
    cout<<dp[1][t]<<'\n';
}
