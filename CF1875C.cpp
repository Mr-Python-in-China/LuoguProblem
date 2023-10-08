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
        ui n,m;
        cin>>n>>m;
        ui ezn=n/__gcd(n,m),ezm=m/__gcd(n,m);
        if (ezm&(ezm-1)) cout<<"-1\n";
        else{
            uli ans=0;
            long double nq=ezn;
            for (uli part=0,pow=1;ezm>1;ezm>>=1,nq/=2,pow<<=1){
                if (int(nq)>>1<<1==nq) continue;
                else if (int(nq)&1) ++part;
                ans+=part*pow;
            }
            cout<<ans*__gcd(n,m)<<'\n';
        }
    }
    return 0;
}