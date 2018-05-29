#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
using namespace std;
int length(vector <string> grid);
int path(vector<vector<int> >&marked,vector<string>grid,int i,int j,int len,int len1,int asc);
int main()
{
    int h,w;cin>>h>>w;
    while(!(h==0&&w==0))
    {
        vector<string>grid;
        for(int i=0;i<h;++i)
            cin>>grid[i];
        cout<<length(grid)<<endl;
    }
}
    int length(vector <string> grid)
        {
        int len=grid.size(),len1=grid[0].length();
        vector<int>temp(len1,-1);
        vector<vector<int> >marked(len,temp);
        int m1=0;
        for(int i=0;i<len;i++)
            {
            for(int j=0;j<len1;j++)
                {
                char ch=grid[i][j];
                if(ch=='A')
                    {
                    	int path1=path(marked,grid,i,j,len,len1,65);
                    	m1=max(m1,path1);
                    }
                }
            }
        return m1;
        }
        int path(vector<vector<int> >&marked,vector<string>grid,int i,int j,int len,int len1,int asc)
        {
        if(!((i>=0&&i<len)&&(j>=0&&j<len1)))
            return 0;
        char ch=grid[i][j];
        if(asc==90)
            {
            if(ch=='Z')
                return 1;
            else
                return 0;
               }
        int as=ch;
        if(as!=asc)
            return 0;
        if(marked[i][j]!=-1)
            return marked[i][j];
        marked[i][j]=path(marked,grid,i+1,j,len,len1,asc+1);
        marked[i][j]=max(marked[i][j],path(marked,grid,i-1,j,len,len1,asc+1));
        marked[i][j]=max(marked[i][j],path(marked,grid,i,j-1,len,len1,asc+1));
        marked[i][j]=max(marked[i][j],path(marked,grid,i,j+1,len,len1,asc+1));
        marked[i][j]=max(marked[i][j],path(marked,grid,i+1,j+1,len,len1,asc+1));
        marked[i][j]=max(marked[i][j],path(marked,grid,i+1,j-1,len,len1,asc+1));
        marked[i][j]=max(marked[i][j],path(marked,grid,i-1,j+1,len,len1,asc+1));
        marked[i][j]=max(marked[i][j],path(marked,grid,i-1,j-1,len,len1,asc+1));
        marked[i][j]++;
        return marked[i][j];
        }
