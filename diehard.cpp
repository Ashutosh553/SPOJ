#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
#include"unordered_map"
using namespace std;
typedef long long ll;
static int dp[1500][1500];
int solve(int i,int h,int arm)//i 0-air 1-water 2-air
{
    if(h<=0||arm<=0)
        return 0;
    if(i!=0)
        return 1+solve(0,h+3,arm+2);
    else
    {
        if(dp[h][arm])
            return dp[h][arm];
        else
        {
            dp[h][arm]=1+max(solve(1,h-5,arm-10),solve(2,h-20,arm+5));
            return dp[h][arm];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int h,a;cin>>h>>a;
        cout<<max(solve(0,h,a),max(solve(1,h,a),solve(2,h,a)))-1<<'\n';
    }
}




