#include<bits/stdc++.h>
using namespace std;
const int NR=3e6;
const int MX=2e4;
int n,m,s,t;
vector<int>e[NR],g[NR];
void add(int u,int v,int w){
    e[u].push_back(v),g[u].push_back(w);
}
bool vis[NR];
int dis[NR],ans;
queue<int>q;
void spfa(int _s){
    memset(vis,false,sizeof(vis));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    ans=dis[0];
    q.push(_s),vis[_s]=true,dis[_s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        vis[u]=false;
        for(int i=0;i<e[u].size();++i){
            int v=e[u][i],w=g[u][i];
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v])q.push(v),vis[v]=true;
            }
        }
    }
}
int main(){
    cin>>n>>m>>s>>t;
    for(int i=1,u,v,w;i<=m;++i){
        cin>>u>>v>>w;
        for(int j=1;j<100;++j){
            add(u*100+j,v*100+j+1,w/j);
            add(v*100+j,u*100+j+1,w/j);
        }
    }
    spfa(t*100+1);
    for(int i=s*100+1;i<=s*100+100;++i)
        ans=min(ans,dis[i]);
    cout<<ans<<endl;
    return 0;
}