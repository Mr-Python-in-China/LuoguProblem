#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
struct dsds{
    dsds(size_t n):fa(n){iota(fa.begin(),fa.end(),0);}
    size_t find(size_t x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    void merge(size_t x,size_t y){fa[find(x)]=find(y);}
private:
    vector<size_t> fa;
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;ui w;
    cin>>n>>m>>w;
    vector<pair<ui,ui>> cloud(n);
    for (pair<ui,ui>& i:cloud) cin>>i.first>>i.second;
    dsds ds(n);
    while (m--){
        size_t u,v;
        cin>>u>>v;
        ds.merge(--u,--v);
    }
    vector<pair<ui,ui>> items;
    {
        unordered_map<size_t,size_t> mapper;
        for (size_t i=0;i<n;i++){
            if (!mapper.count(ds.find(i))) mapper.insert({ds.find(i),items.size()}),items.push_back({0,0});
            items[mapper[ds.find(i)]].first+=cloud[i].first,
            items[mapper[ds.find(i)]].second+=cloud[i].second;
        }
    }
    vector<ui> dp(w+1);
    for (pair<ui,ui> const& i:items)
        for (size_t j=w;j>=i.first;j--)
            dp[j]=max(dp[j],dp[j-i.first]+i.second);
    cout<<dp[w];
    return 0;
}