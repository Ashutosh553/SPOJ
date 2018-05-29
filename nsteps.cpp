#include"iostream"
#include"cmath"
using namespace std;
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;++i)
    {
        int x,y;cin>>x>>y;
        if(x==y)
        {
            if(x>=0&&x%2==0)
                cout<<2*x<<endl;
            else if(x>=0&&x%2==1)
                cout<<2*x-1<<endl;
        }
        else if(x==y+2)
        {
            if(x>0&&x%2==0)
                cout<<x+y<<endl;
            else if(x>0&&x%2==1)
                cout<<x+y-1<<endl;
        }
        else cout<<"No Number\n";
    }
}
