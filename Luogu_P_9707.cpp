#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
array<uli,size_t(2e6+1)> frac({1});
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    uli l,r,k;
    cin>>l>>r>>k;
    for (uli i=1;i<frac.size();++i) frac[i]=frac[i-1]*i%k;
    uli ans=0;
    for (uli i=l;i<=r;++i) ans=max(ans,frac[i]);
    cout<<ans;
    return 0;
}