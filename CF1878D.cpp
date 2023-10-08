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
        size_t n,k,q;string s;
        cin>>n>>k>>s;
        vector<pair<ui,ui>> ins(k);
        for (pair<ui,ui>& i:ins) cin>>i.first,--i.first;
        for (pair<ui,ui>& i:ins) cin>>i.second,i.second;
        cin>>q;
        unordered_multiset<ui> qs;
        for (size_t i=0;i<q;++i){
            size_t x;
            cin>>x;
            qs.insert(--x);
        }
        for (pair<ui,ui> const& i:ins){
            bool rev=false;
            for (size_t j=i.first,k=i.second-1;j<k;++j,--k){
                if ((qs.count(j)&1)^(qs.count(k)&1)) rev^=1;
                if (rev) swap(s[j],s[k]);
            }
        }
        cout<<s<<'\n';
    }
    return 0;
}