#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
using graph=vector<vector<size_t>>;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m,k;cin>>n>>m>>k;++k;
    vector<uli> val(n);
    for_each(next(val.begin()),val.end(),[](uli& x){cin>>x;});
    graph mp(n);
    for (size_t i=0;i<m;++i){
        size_t x,y;cin>>x>>y;--x,--y;
        mp[x].push_back(y),mp[y].push_back(x);
    }
    vector<vector<size_t>> dis(n,vector<size_t>(n,-1));
    for (size_t i=0;i<n;++i){
        queue<size_t> q({i});
        dis[i][i]=0;
        while (!q.empty()){
            size_t p=q.front();q.pop();
            for (size_t j:mp[p]) if (!~dis[i][j])
                dis[i][j]=dis[i][p]+1,q.push(j);
        }
    }
    vector<array<size_t,4>> best(n,{size_t(-1),size_t(-1),size_t(-1),size_t(-1)});
    for (size_t i=0;i<n;++i){
        queue<size_t> q({i});
        vector<bool> vis(n);
        vis[i]=true;
        while (!q.empty()&&dis[i][q.front()]<=k){
            size_t p=q.front();q.pop();
            if (dis[0][p]<=k&&(!~best[i][0]||val[p]>val[best[i][0]])) best[i][3]=best[i][2],best[i][2]=best[i][1],best[i][1]=best[i][0],best[i][0]=p;
            else if (dis[0][p]<=k&&(!~best[i][1]||val[p]>val[best[i][1]])) best[i][3]=best[i][2],best[i][2]=best[i][1],best[i][1]=p;
            else if (dis[0][p]<=k&&(!~best[i][2]||val[p]>val[best[i][2]])) best[i][3]=best[i][2],best[i][2]=p;
            else if (dis[0][p]<=k&&(!~best[i][3]||val[p]>val[best[i][3]])) best[i][3]=p;
            for (size_t j:mp[p]) if (!vis[j])
                vis[j]=true,q.push(j);
        }
    }
    uli ans=0;
    for (size_t b=0;b<n;++b) for (size_t c=0;c<n;++c) if (0<dis[b][c]&&dis[b][c]<=k)
        for (size_t a:best[b]) if (a!=-1&&a!=0&&a!=b&&a!=c) for (size_t d:best[c]) if (d!=-1&&d!=0&&d!=b&&d!=c&&d!=a)
            ans=max(ans,val[a]+val[b]+val[c]+val[d]);
    cout<<ans;
    return 0;
}