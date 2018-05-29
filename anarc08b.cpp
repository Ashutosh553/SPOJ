#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
string a1[]={"063","010","093","079","106","103","119","011","127","107"};
vector<string>a(a1,a1+10);
int conv(string x)
{
    int len=x.length();
    int ans=0,po=1;
    for(int i=len-1;i>=0;)
    {
        string t=x.substr(i-2,3);i-=3;
        int pos=find(a.begin(),a.end(),t)-a.begin();
        ans+=po*pos;
        po*=10;
    }
    return ans;
}
string rconv(int x)
{
    string ans="";
    while(x!=0)
    {
        ans=a[x%10]+ans;
        x/=10;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        string x;cin>>x;
        if(x=="BYE")
            break;
        int fo=x.find("+");
        string x1=x.substr(0,fo),y1=x.substr(fo+1,x.length()-fo-2);
        int ans=conv(x1)+conv(y1);
        string rec=rconv(ans);
        cout<<x1<<'+'<<y1<<'='<<rec<<'\n';
        
    }
}
