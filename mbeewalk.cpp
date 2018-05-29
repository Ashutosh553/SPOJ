#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
int dx[]={1,1,0,0,-1,-1};
int dy[]={0,1,1,-1,0,-1};
int solve(int i,int j,vector<vector<vector<int> > >&rec,int n)
{
    if(!(i>20&&i<80&&j>20&&j<80))
        return 0;
    else if(rec[i][j][n]>=0)
        return rec[i][j][n];
    else if(n==0)
    {
        if(i==50&&j==50)
        {
            rec[50][50][0]=1;
            return 1;
        }
        else
        {
            rec[i][j][0]=0;
            return 0;
        }
    }
    rec[i][j][n]=0;
    for(int count=0;count<6;++count)
    {
        rec[i][j][n]+=solve(i+dx[count],j+dy[count],rec,n-1);
    }
    return rec[i][j][n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<vector<vector<int> > >rec(100,vector<vector<int> >(100,vector<int>(15,-1)));
        cout<<solve(50,50,rec,n)<<"\n";
    }
}
