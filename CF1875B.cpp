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
        size_t n,m,k;
        cin>>n>>m>>k;
        vector<ui> a(n),b(m);
        uli ans=0;ui maxa=0,maxb=0,mina=-1,minb=-1;
        for (ui& i:a) cin>>i;
        for (ui& i:b) cin>>i;
        sort(a.begin(),a.end()),sort(b.begin(),b.end());
        if (a.front()<b.back()) swap(a.front(),b.back());
        for (ui x:a) ans+=x,maxa=max(maxa,x),mina=min(mina,x);
        for (ui x:b) maxb=max(maxb,x),minb=min(minb,x);
        cout<<ans-(k&1?0:maxa-minb)<<'\n';
    }
    return 0;
}