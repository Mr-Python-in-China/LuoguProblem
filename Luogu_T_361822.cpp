#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using graph=vector<vector<size_t>>;
void dfs(graph const& mp,vector<size_t> const& fa,vector<size_t> const& dis,vector<bool>& vis,graph& ans,size_t p){
    vis[p]=true;
    for (size_t const& i:mp[p]) if (!vis[i])
        if (fa[i]==p) dfs(mp,fa,dis,vis,ans,i);
        else if (dis[p]<dis[i]){
            size_t me=p,it=i;
            while (fa[me]!=fa[it])
                if (dis[me]>=dis[it]) me=fa[me];
                else it=fa[it];
            dfs(mp,fa,dis,vis,ans,it);
        }
    if (fa[p]!=-1) ans[fa[p]].push_back(p);
}
struct myhash{
    size_t operator()(pair<size_t,size_t> const& x) const noexcept{return (x.first<<32)+x.second;}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    graph mp(n);
    unordered_multiset<pair<size_t,size_t>,myhash> unique_edge;
    while (m--){
        size_t u,v;cin>>u>>v;--u,--v;
        if (u>v) swap(u,v);
        mp[u].push_back(v),mp[v].push_back(u);
        unique_edge.insert({u,v});
    }
    for (vector<size_t>& i:mp){
        sort(i.begin(),i.end());
        i.erase(unique(i.begin(),i.end()),i.end());
    }
    vector<size_t> fa(n);
    graph tree(n);
    for (size_t i=0;i<n;++i){
        cin>>fa[i];
        if (--fa[i]!=-1) tree[fa[i]].push_back(i);
    }
    vector<size_t> dis(n,-1);
    {
        queue<size_t> q({0});
        dis[0]=0;
        while (!q.empty()){
            size_t p=q.front();q.pop();
            for (size_t const& i:tree[p]) 
                if (dis[i]==-1) dis[i]=dis[p]+1,q.push(i);
        }
    }
    vector<bool> vis(n);
    graph ans(n);
    dfs(mp,fa,dis,vis,ans,0);
    {
        vector<size_t> dis(n,-1);
        queue<size_t> q({0});
        dis[0]=0;
        while (!q.empty()){
            size_t p=q.front();q.pop();
            for (size_t const& i:ans[p]) 
                if (dis[i]==-1){
                    for (size_t j=unique_edge.erase({min(p,i),max(p,i)});j>0;j--)
                        cout<<p+1<<' '<<i+1<<'\n';
                    dis[i]=dis[p]+1,q.push(i);
                }
        }
    }
    for (pair<size_t,size_t> const& i:unique_edge) cout<<i.first+1<<' '<<i.second+1<<'\n';
    return 0;
}