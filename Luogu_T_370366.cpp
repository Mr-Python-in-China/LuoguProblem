#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
constexpr uli MOD=998244353;
constexpr uli ksm(uli a,uli n){
    uli ans=1;
    while (n){
        if (n&1) (ans*=a)%=MOD;
        (a*=a)%=MOD;
        n>>=1;
    }
    return ans;
}
constexpr uli PX=ksm(2,MOD-2);
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t a,b,k;
    cin>>a>>b>>k;
    uli x=1;
    for (size_t i=1;i<=k;i++){
        if (i%a==0) (x*=2)%=MOD;
        if (i%b==0) x==1?x=1:(x*=PX)%=MOD;
    }
    cout<<x;
    return 0;
}