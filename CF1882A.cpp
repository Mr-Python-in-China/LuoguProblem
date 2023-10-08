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
        size_t n;
        cin>>n;
        ui p=0;
        for (size_t i=0;i<n;++i){
            ui x;
            cin>>x;
            if (++p==x) ++p;
        }
        cout<<p<<'\n';
    }
    return 0;
}