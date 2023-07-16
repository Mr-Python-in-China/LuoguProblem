#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using graph=vector<vector<size_t>>;
bool dfs(graph const& mp,vector<size_t>& match,vector<bool>& vis,size_t p){
    for (size_t const& i:mp[p]) if (!vis[i]){
        vis[i]=true;
        if (!~match[i]||dfs(mp,match,vis,match[i]))
            return match[i]=p,true;
    }
    return false;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;n<<=1;
    graph mp(n);
    for (size_t i=0;i<n;i++){
        size_t x,y;
        cin>>x>>y;
        mp[i].push_back(--x),mp[i].push_back(--y);
        mp[i].push_back(n-x-1),mp[i].push_back(n-y-1);
    }
    #ifdef debug
    for (size_t i=0;i<n;i++){
        cout<<i<<':';
        for (size_t j=0;j<mp[i].size();j++) cout<<mp[i][j]<<' ';
        cout<<'\n';
    }
    #endif
    vector<size_t> match(n,-1);
    size_t ans=0;
    for (size_t i=0;i<n;i++){
        vector<bool> vis(n);
        ans+=dfs(mp,match,vis,i);
    }
    #ifdef debug
    for (size_t i=0;i<n;i++) cout<<match[i]<<' ';
    cout<<'\n';
    #endif
    cout<<ans;
    return 0;
}