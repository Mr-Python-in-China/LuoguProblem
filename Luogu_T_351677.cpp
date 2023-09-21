#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using uli=unsigned long long int;
using ulli=__uint128_t;
const uli P=998'244'353;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t sid,T;
    cin>>sid>>T;
    while (T--){
        size_t n;
        cin>>n;
        vector<uli> v(n),c(n),x(n-1);
        for (uli& i:v) cin>>i;
        for (uli& i:c) cin>>i;
        for (uli& i:x) cin>>i;
        vector<ulli> a(n);
        for (size_t i=0;i<n;i++) a[i]=ulli(c[i])*v[i];
        for (size_t i=0;i<n-1;i++) if (v[i+1]>x[i]*v[i]){
            size_t k=c[i]/x[i];
            c[i]%=x[i];
            a[i+1]+=k;
        }
        ulli ans=0;
        for (size_t i=0;i<n;i++) (ans+=a[i])%=P;
        cout<<uli(ans)<<'\n';
    }
    return 0;
}