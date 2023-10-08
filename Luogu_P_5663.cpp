#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
using graph=vector<vector<size_t>>;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m,t;
    cin>>n>>m>>t;
    graph mp(n);
    while (m--){
        size_t u,v;
        cin>>u>>v;--u,--v;
        mp[u].push_back(v),mp[v].push_back(u);
    }
    vector<size_t> dist[2];
    dist[0].resize(n),dist[1].resize(n);
    fill(dist[0].begin(),dist[0].end(),-1),fill(dist[1].begin(),dist[1].end(),-1);
    dist[0][0]=0;
    queue<pair<size_t,size_t>> q({{0,0}});
    while (!q.empty()){
        pair<size_t,size_t> p=q.front();q.pop();
        for (size_t const i:mp[p.first]) if (!~dist[p.second&1^1][i])
            dist[p.second&1^1][i]=p.second+1,q.emplace(i,p.second+1);
    }
    while (t--){
        size_t a,l;
        cin>>a>>l;
        cout<<(dist[l&1][--a]<=l?"Yes\n":"No\n");
    }
    return 0;
}