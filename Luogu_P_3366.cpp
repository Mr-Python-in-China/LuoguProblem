#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
class dsds{
    vector<size_t> fa;
public:
    dsds(size_t s){
        fa.resize(s);
        for (size_t i=0;i<s;i++) fa[i]=i;
    }
    inline size_t find(const size_t x){return x==fa[x]?x:fa[x]=find(fa[x]);}
    inline void link(const size_t x,const size_t y){fa[find(y)]=find(x);}
    inline bool in_one_set(const size_t x,const size_t y){return find(x)==find(y);}
};
struct edge{
    size_t u,v;ui w;
    edge(void)=default;
    edge(size_t _u,size_t _v,ui _w):u(_u),v(_v),w(_w){}
    friend istream& operator>>(istream& in,edge& e){
        return in>>e.u>>e.v>>e.w;
    }
    friend inline bool operator>(const edge& a,const edge& b){return a.w>b.w;}
    friend inline bool operator<(const edge& a,const edge& b){return a.w<b.w;}
    friend inline bool operator==(const edge& a,const edge& b){return a.w==b.w;}
    friend inline bool operator!=(const edge& a,const edge& b){return a.w!=b.w;}
    friend inline bool operator>=(const edge& a,const edge& b){return a.w>=b.w;}
    friend inline bool operator<=(const edge& a,const edge& b){return a.w<=b.w;}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    vector<edge> mp(m);
    for (vector<edge>::reference i:mp) cin>>i;
    sort(mp.begin(),mp.end());
    dsds ds(n+1);
    ui cnt=0,ans=0;
    for (vector<edge>::reference i:mp){
        if (ds.in_one_set(i.u,i.v)) continue;
        cnt++;
        ans+=i.w;
        ds.link(i.u,i.v);
        if (cnt>=n-1) break;
    }
    cnt>=n-1?cout<<ans:cout<<"orz";
    return 0;
}