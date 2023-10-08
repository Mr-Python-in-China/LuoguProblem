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
        list<bitset<51>> s(n);
        bitset<51> all;
        for (bitset<51>& i:s){
            size_t k;
            cin>>k;
            while (k--){
                ui x;
                cin>>x;
                i.set(x);
            }
            all|=i;
        }
        size_t ans=0;
        for (ui i=1;i<=50;++i) if (all[i]){
            bitset<51> v;
            for (bitset<51>& j:s) if (!j[i]) v|=j;
            ans=max(ans,v.count());
        }
        cout<<ans<<'\n';
    }
    return 0;
}