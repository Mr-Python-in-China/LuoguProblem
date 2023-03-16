#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
class dsds{
    vector<ui> fa;
    size_t find(size_t x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    public:
    dsds(size_t n){
        fa.resize(n);
        for (size_t i=0;i<n;i++) fa[i]=i;
    }
    inline bool same(size_t x,size_t y){return find(x)==find(y);}
    inline void link(size_t x,size_t y){fa[find(x)]=find(y);}
    inline is_headder()
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m,k;
    cin>>n>>m>>k;
    vector<ui> people;
    {
        dsds d(n);
        while (k--){
            ui x,y;
            cin>>x>>y;
            d.link(--x,--y);
        }
    }
    return 0;
}