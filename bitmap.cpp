#include"iomanip"
#include"iostream"
#include"limits"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"queue"
#include"stack"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
#include"cstring"
using namespace std;
typedef long long ll;
const int maxn=200;
int ans[maxn][maxn];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int n,m;
bool check(int x,int y)
{
    return (x>=0&&x<n&&y>=0&&y<m);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        memset(ans,-1,sizeof ans);
        cin>>n>>m;
        queue<pair<int,int> >qq;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                char ch;cin>>ch;
                if(ch=='1')
                {
                    qq.push(make_pair(i,j));
                    ans[i][j]=0;
                }
            }
        }
        int no=1;
        while(!qq.empty())
        {
            auto temp=qq.front();
            if(ans[temp.first][temp.second]==no)
                no++;
            qq.pop();
            for(int i=0;i<4;++i)
            {
                int x1=temp.first+dx[i],y1=temp.second+dy[i];
                if(check(x1,y1)&&ans[x1][y1]==-1)
                {
                    ans[x1][y1]=no;
                    qq.push(make_pair(x1,y1));
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            cout<<ans[i][0];
            for(int j=1;j<m;++j)
                cout<<' '<<ans[i][j];
            cout<<'\n';
        }
    }
}




