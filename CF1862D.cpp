#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using ld=long double;
uli func(uli x){
    ld d=ld(x)*8+1;
    return (sqrt(d)+1)/2;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        uli x;
        cin>>x;
        uli n=func(x);
        cout<<uli(n+(x-(n*n-n)/2))<<'\n';
    }
    return 0;
}