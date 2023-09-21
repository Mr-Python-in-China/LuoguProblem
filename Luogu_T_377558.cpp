#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        string s,t;
        cin>>s>>t;
        size_t ans=0;
        if (s.size()<t.size()){cout<<"0\n";continue;}
        for (size_t i=1;i<t.size();++i)
            ans+=s.substr(s.size()-t.size()+i)+s.substr(0,i)==t;
    #ifdef debug
        for (size_t i=1;i<t.size();++i)
            cout<<i<<' '<<s.substr(s.size()-t.size()+i)<<' '<<s.substr(0,i)<<'\n';
    #endif
        cout<<ans<<'\n';
    }
    return 0;
}