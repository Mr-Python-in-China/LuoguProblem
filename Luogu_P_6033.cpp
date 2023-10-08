#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
#include<iostream>
#include<cstdio>

using namespace std;

template<typename type> inline void read(type &x){
    x=0;static bool flag(0);char ch=getchar();
    while(!isdigit(ch)) flag=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    flag?x=-x:0;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;uli ans=0;
    read(n);
    deque<uli> a,b;
    array<size_t,size_t(1e5+1)> bottle={};
    for (size_t i=0;i<n;++i){
        uli x;
        read(x);
        ++bottle[x];
    }
    for (uli i=0;i<bottle.size();++i) for (size_t j=0;j<bottle[i];++j) a.push_back(i);
    while (--n>0){
        uli mina,minb;
        if (b.empty()||(!a.empty()&&a.front()<b.front())) mina=a.front(),a.pop_front();
        else mina=b.front(),b.pop_front();
        if (b.empty()||(!a.empty()&&a.front()<b.front())) minb=a.front(),a.pop_front();
        else minb=b.front(),b.pop_front();
        ans+=mina+minb;
        b.push_back(mina+minb);
    }
    cout<<ans;
    return 0;
}