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
        size_t n,k;string s;
        cin>>n>>k>>s;
        size_t ans=0;
        for (size_t i=0;i<n;++i)
            if (s[i]=='B') i+=k-1,++ans;
        cout<<ans<<'\n';
    }
    return 0;
}