#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"stack"
#include"set"
#include"unordered_set"
#include"map"
#include"unordered_map"
#include"string"
#include"cstring"
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;cin>>t;
    int arr[100010];
    while(t--)
    {
        int a,b;cin>>a>>b;
        for(int i=0;i<a;++i)
            cin>>arr[i];
        int low=0,high=0,sum=0;
        int max1=0,num=0;
        while(low<=a)
        {
            while(high<a&&sum+arr[high]<=b)
            {
                sum+=arr[high++];
            }
            if(high-low>num||(high-low==num&&sum<max1))
            {
                max1=sum;num=high-low;
            }
            sum-=arr[low];
            ++low;
        }
        cout<<max1<<" "<<num<<'\n';
    }
}
