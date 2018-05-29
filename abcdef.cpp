#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"map"
typedef long long ll;
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int>rec(n);
    for(int i=0;i<n;++i)
    {
        cin>>rec[i];
    }
    sort(rec.begin(),rec.end());
    ll count=0;
    map<int,int>left;
    for(int a=0;a<n;++a)
    {
        for(int b=a;b<n;++b)
        {
            for(int c=0;c<n;++c)
            {
                if(a==b)
                {
                    left[rec[a]*rec[b]+rec[c]]+=1;
                }
                else left[rec[a]*rec[b]+rec[c]]+=2;
            }
        }
    }
    map<int,int>right;
    for(int d=0;d<n;++d)
    {
        if(rec[d]==0)
            continue;
        for(int e=0;e<n;++e)
        {
            for(int f=e;f<n;++f)
            {
                if(e==f)
                    right[(rec[e]+rec[f])*rec[d]]+=1;
                else right[(rec[e]+rec[f])*rec[d]]+=2;
            }
        }
    }
    map<int,int>::iterator it=right.begin();
    //cout<<it->first<<endl;
    for(it=right.begin();it!=right.end();it++)
    {
        int ans=it->first;int numb=it->second;
        map<int,int>::iterator it1=left.find(ans);
        if(it1!=left.end())
        {
            count+=(it1->second)*numb;
        }
    }
    cout<<count<<endl;
}

