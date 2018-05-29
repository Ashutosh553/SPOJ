#include"iostream"
#include"cmath"
#include"algorithm"
using namespace std;
int main()
{
    int row[1234],row1[1234],col[5678],col1[5678];
    for(int i=0;i<1234;++i)
    {
        row[i]=i;row1[i]=i;
        col[i]=i;col1[i]=i;
    }
    for(int i=1234;i<5678;++i)
    {
        col[i]=i;col1[i]=i;
    }
    char ch;int x,y;
    while(!cin.eof())
    {
        ch=getchar();
        if(ch=='R')
        {
            cin>>x>>y;--x;--y;
            swap(row1[row[x]],row1[row[y]]);
            swap(row[x],row[y]);
        }
        else if(ch=='C')
        {
            cin>>x>>y;--x;--y;
            swap(col1[col[x]],col1[col[y]]);
            swap(col[x],col[y]);
        }
        else if(ch=='Q')
        {
            cin>>x>>y;x--;y--;
            int r=row[x],c=col[y];
            cout<<5678*r+c+1<<endl;
        }
        else if(ch=='W')
        {
            cin>>x;
            int r=(x-1)/5678;
            int c=(x-1)%5678;
            cout<<row1[r]+1<<" "<<col1[c]+1<<endl;
        }
        else if(ch!=' '&&ch!='\n')
            break;
    }
    return 0;
}
