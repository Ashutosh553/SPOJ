#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
ll solve(ll n)
{
    if(n==3||n==4)
        return 3;
    else if(n%2==0)
        return 1+solve(n/2+1);
    else return 1+solve((n+3)/2);
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        cout<<solve(n)<<endl;
    }
}
