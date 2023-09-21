#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using graph=vector<vector<pair<size_t,ui>>>;
struct edge{
    size_t u,v;ui w;
    friend istream& operator>>(istream& in,edge& e){return in>>e.u>>e.v>>e.w;}
    friend bool operator<(edge const& a,edge const& b){return a.w<b.w;}
};
class dsds{
    vector<size_t> fa;
    size_t find(size_t x){return fa[x]==x?x:fa[x]=find(fa[x]);}
public:
    dsds(size_t n):fa(n){iota(fa.begin(),fa.end(),0);}
    void merge(size_t x,size_t y){fa[find(x)]=find(y);}
    bool check(size_t x,size_t y){return find(x)==find(y);}
};
bool find_road(graph const& mp,size_t s,size_t t,vector<ui>& stack,vector<bool> vis,ui lst=-1){
    if (lst!=-1) stack.push_back(lst);
    vis[s]=true;
    if (s==t) return true;
    for (pair<size_t,ui> const& i:mp[s]) if (!vis[i.first])
        if (find_road(mp,i.first,t,stack,vis,i.second)) return true;
    stack.pop_back();
    return false;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m,s,t;
    cin>>n>>m>>s>>t;--s,--t;
    vector<edge> e(m);
    for (edge& i:e) cin>>i,--i.u,--i.v;
    sort(e.begin(),e.end());
    dsds ds(n);
    size_t cnt=0;
    graph tree(n);
    for (edge const& i:e) if (!ds.check(i.u,i.v)){
        ds.merge(i.u,i.v);
        tree[i.u].push_back({i.v,i.w}),tree[i.v].push_back({i.u,i.w});
        cnt++;
        if (cnt>=n-1) break;
    }
    vector<ui> stk;
    vector<bool> vis(n);
    find_road(tree,s,t,stk,vis);
    size_t k=stk.size();
    ui ans=0;
    for (ui const& i:stk) ans+=i/(k--);
    cout<<ans;
    return 0;
}