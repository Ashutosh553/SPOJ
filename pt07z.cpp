#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
#include"list"
using namespace std;
typedef long long ll;
pair<int,int> dfs(int curr,int i,vector<list<int> >& tab)
{
    int ans=0,farth;
    pair<int,int>temp;
    for(auto it=tab[i].begin();it!=tab[i].end();++it)
    {
        if(*it==curr)
            continue;
        else
        {
            temp=dfs(i,*it,tab);
            if(temp.first>ans)
            {
                ans=temp.first;farth=temp.second;
            }
        }
    }
    if(ans==0)
    {
        temp=make_pair(1,i);
        return temp;
    }
    temp=make_pair(1+ans,farth);
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<list<int> >tab(n);
    for(int i=1;i<n;++i)
    {
        int a,b;cin>>a>>b;
        tab[a-1].push_back(b-1);
        tab[b-1].push_back(a-1);
    }
    int i=dfs(-1,0,tab).second;
    int ans=dfs(-1,i,tab).first;
    cout<<ans-1<<'\n';
}
