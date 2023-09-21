#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
namespace std{template<> struct hash<pair<ui,ui>>{
    size_t operator()(pair<ui,ui> const& x) const{return uli(x.first)<<32|x.second;}
};}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui x;
    cin>>x;
    queue<pair<ui,ui>> q({{0,1}});
    unordered_set<pair<ui,ui>> mp;
    while (!q.empty()){
        pair<ui,ui> p=q.front();q.pop();
        if (p.first==x) break;
        q.push({p.first,p.second+1}),
        q.push({p.first+p.second,p.second});
    }
    return 0;
}