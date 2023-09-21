#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using uli=unsigned long long int;
const uli MOD=1e9+7;
using graph=vector<vector<size_t>>;
struct node{uli a,b,c;};
node dfs(graph const& mp,vector<unsigned char> const& color,vector<bool>& vis,size_t const p){
    vis[p]=true;
    node res={0,0,0};
    if (color[p]) (color[p]==1?res.a:color[p]==2?res.b:res.c)=1;
    else res={1,1,1};
    for (size_t const& i:mp[p]) if (!vis[i]){
        node tmp=dfs(mp,color,vis,i);
        (res.a*=(tmp.b+tmp.c)%MOD)%=MOD,
        (res.b*=(tmp.a+tmp.c)%MOD)%=MOD,
        (res.c*=(tmp.a+tmp.b)%MOD)%=MOD;
    }
    return res;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,k;
    cin>>n>>k;
    graph mp(n);
    vector<unsigned char> color(n);
    for (size_t i=1;i<n;i++){
        size_t x,y;
        cin>>x>>y;--x,--y;
        mp[x].push_back(y),mp[y].push_back(x);
    }
    while (k--){
        size_t x;
        cin>>x;--x;
        cin>>color[x],color[x]-='0';
    }
    vector<bool> vis(n);
    node ans=dfs(mp,color,vis,0);
    cout<<(ans.a+ans.b+ans.c)%MOD;
    return 0;
}