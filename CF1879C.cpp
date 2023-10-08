#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
uli constexpr P=998244353;
array<uli,size_t(2e5+1)> frac;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    frac[0]=1;
    for (size_t i=1;i<frac.size();++i) frac[i]=(frac[i-1]*i)%P;
    size_t T;
    cin>>T;
    while (T--){
        string s;
        cin>>s;
        char lst=s.front();size_t len=1;uli ans1=0,ans2=1;
        for_each(next(s.begin()),s.end(),[&](char c)->void {
            if (c==lst) ++len;
            else ans1+=len-1,(ans2*=len)%=P,len=1,lst=c;
        });
        ans1+=len-1,(ans2*=len)%=P,len=1;
        cout<<ans1<<' '<<((ans2*=frac[ans1])%=P)<<'\n';
    }
    return 0;
}