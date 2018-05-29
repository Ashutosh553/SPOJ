#include"iostream"
#include"cmath"
#include"vector"
#include"algorithm"
#include"string"
using namespace std;
int main()
{
    int n;cin>>n;
    string row1;cin>>row1;
    string row2;char curr='A';
    for(int i=0;i<n;++i)
    {
        int j=2*i;
        vector<char>letters;
        char ch1=row1[j],ch2=row1[j+1];
        for(int i=0;i<4;++i)
        {
            char ch=65+i;
            if(ch!=ch1&&ch!=ch2)
                letters.push_back(ch);
        }
        if(letters[0]==curr)
        {
            letters[0]=letters[1];
            letters[1]=curr;
        }
        curr=letters[1];
        row2.push_back(letters[0]);
        row2.push_back(letters[1]);
    }
    cout<<row2<<endl;
}
