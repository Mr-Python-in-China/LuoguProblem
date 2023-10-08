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
        size_t n;uli mina=-1,minb=-1,suma=0,sumb=0;
        cin>>n;
        for (size_t i=0;i<n;++i){
            uli a;cin>>a;suma+=a,mina=min(mina,a);
        }
        for (size_t i=0;i<n;++i){
            uli b;cin>>b;sumb+=b,minb=min(minb,b);
        }
        cout<<min(suma+minb*n,sumb+mina*n)<<'\n';
    }
    return 0;
}