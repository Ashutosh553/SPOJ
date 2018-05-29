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
    while(1)
    {
        int n1,n2;
        cin>>n1;
        if(n1==0)break;
        vector<int>rec1(n1+1);
        for(int i=0;i<n1;++i)
        {
            cin>>rec1[i];
        }
        cin>>n2;
        vector<int>rec2(n2+1);
        for(int i=0;i<n2;++i)
        {
            cin>>rec2[i];
        }
        ll dp[10010][2];
        dp[n1][0]=0;
        dp[n2][1]=0;
        bool who=true;
        for(int i=max(n1,n2)-1,j=i;i>=0||j>=0;who=!who)
        {
            int pos1,pos2;
            pos1=lower_bound(rec1.begin(),rec1.end(),rec2[i])-rec1.begin();
            pos2=lower_bound(rec2.begin(),rec2.end(),rec1[j])-rec2.begin();
            if(i>=0&&i<n2&&who)
            {
                    if(pos1<n1&&rec1[pos1]==rec2[i])
                    {
                        if(j>pos1)
                            continue;
                        dp[i][1]=rec2[i]+max(dp[pos1+1][0],dp[i+1][1]);--i;
                    }
                    else
                    {
                        dp[i][1]=rec2[i]+dp[i+1][1];--i;
                    }
            }
            if(j>=0&&j<n1&&!who)
            {
                    if(pos2<n2&&rec2[pos2]==rec1[j])
                    {
                        if(i>pos2)
                            continue;
                        dp[j][0]=rec1[j]+max(dp[j+1][0],dp[pos2+1][1]);--j;
                    }
                    else
                    {
                        dp[j][0]=rec1[j]+dp[j+1][0];--j;
                    }
            }
            if(i>=n2)
                --i;
            if(j>=n1)
                --j;
        }
        int res=max(dp[0][0],dp[0][1]);
        printf("%d\n",res);
    }
}


