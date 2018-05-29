#pragma optimize("O1")
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
#include"bitset"
#include"cstring"
#include"assert.h"
using namespace std;
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N = 1e8+4;
bitset<N>lp;
void build()
{
    lp.set();
    for (int i=2; i<N; ++i) 
    {
        if(lp[i]==1)
        {
            for(ll j=1LL*i*i;j<N;j+=i)
            {
                lp[j]=0;
            }
        }
    }
}
int main()
{
    build();
    int cou=1;
    for(int i=2;i<1e8;++i)
    {
        if(lp[i]==1)
        {
            if(cou%100==1)
            {
                printf("%d\n",i);
            }
            cou++;
        }
    }
}
