#include"iomanip"
#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"set"
#include"map"
#include"string"
using namespace std;
typedef long long ll;
double pi=3.14159265358979;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double a,b,s,m,n;
    cin>>a>>b>>s>>m>>n;
    while(s!=0)
    {
        long double vx,vy,dx,dy,ang,vel;
        dy=n*b;dx=m*a;
        if(dx!=0)
        {
            ang=atan(dy/dx)*180/pi;
        }
        else ang=90;
        vel=sqrt(dx*dx+dy*dy)/s;
        ang*=100;ang=round(ang);ang/=100;
        vel*=100;vel=round(vel);vel/=100;
        cout<<fixed;
        cout<< setprecision(2) <<ang<<' ';
        cout<<setprecision(2)<<vel<<'\n';
        cin>>a>>b>>s>>m>>n;
    }
}
