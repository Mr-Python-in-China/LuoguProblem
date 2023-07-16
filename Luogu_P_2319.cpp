#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
bool dfs(vector<array<size_t,2>> const& mp,vector<size_t>& match,vector<bool>& vis,size_t const& p){
    for (size_t const& i:mp[p]) if (!vis[i]){
        vis[i]=true;
        if (!~match[i]||dfs(mp,match,vis,match[i])) return match[i]=p,true;
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    vector<array<size_t,2>> mp(m);
    for (array<size_t,2>& i:mp) cin>>i[0]>>i[1];
    #ifdef debug
    for (auto& i:mp) for (auto& j:i) cout<<j<<' ';
    cout<<endl;
    #endif
    vector<size_t> match(n,-1);
    size_t ans=0;
    for (size_t i=0;i<m;i++){
        vector<bool> vis(n);
        if (dfs(mp,match,vis,i)) ans++;
        else break;
    }
    cout<<ans<<'\n';
    vector<pair<ui,size_t>> res(n);
    for (size_t i=0;i<n;i++) res[i].first=match[i],res[i].second=i;
    sort(res.begin(),res.end());
    for (size_t i=0;i<ans;i++) cout<<res[i].second<<'\n';
    return 0;
}