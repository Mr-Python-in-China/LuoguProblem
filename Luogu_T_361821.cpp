#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
template<typename T> struct prefix_xor{
    vector<T> s;
    template<typename _ForwardIterator>
    prefix_xor(_ForwardIterator begin,_ForwardIterator end)
        :s(distance(begin,end)+1){
        for (typename vector<T>::iterator it=s.begin(),jt=next(it);begin!=end;++begin,++it,++jt)
            *jt=*it^*begin;
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<ui> a(n);
    for (ui& i:a) cin>>i;
    prefix_xor<ui> s(a.begin(),a.end());
    unordered_map<ui,size_t> bottle;
    size_t ans=0;
    for (ui const& i:s.s) ans+=bottle[i]++;
    cout<<ans;
    return 0;
}