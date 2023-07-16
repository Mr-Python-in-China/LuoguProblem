#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long int;
struct pos{
    size_t x,y;
    pos& operator+=(pos const& p){x+=p.x,y+=p.y;return *this;}
    pos operator+(pos const& p) const{pos tmp(*this);tmp+=p;return tmp;}
    static pos const f[4];
    friend bool operator<(pos const& x,pos const& y){return x.x==y.x?x.y<y.y:x.x<y.x;}
};
pos const pos::f[4]={{1,0},{0,1},{size_t(-1),0},{0,size_t(-1)}};
void dijkstra(vector<vector<size_t>> const& mp,vector<vector<uli>>& dis,pos s,size_t const& n,size_t const& m){
    using node=pair<uli,pos>;
    dis[s.x][s.y]=mp[s.x][s.y];
    vector<vector<bool>> vis(n,vector<bool>(m));
    priority_queue<node,vector<node>,greater<node>> q;q.push({mp[s.x][s.y],s});
    while (!q.empty()){
        pos p=q.top().second;q.pop();
        if (!vis[p.x][p.y]){
            vis[p.x][p.y]=true;
            for (pos const& i:pos::f){
                pos np=p+i;
                if (np.x<n&&np.y<m&&dis[np.x][np.y]>dis[p.x][p.y]+mp[np.x][np.y])
                    q.push({dis[np.x][np.y]=dis[p.x][p.y]+mp[np.x][np.y],np});
            }
        }
    }
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;
    vector<vector<size_t>> arr(n,vector<size_t>(m));
    for (size_t i=0;i<n;i++) for (size_t j=0;j<m;j++) cin>>arr[i][j];
    vector<vector<uli>> disa(n,vector<uli>(m,0x7ffffffffffffff)),
                        disb(n,vector<uli>(m,0x7ffffffffffffff)),
                        disc(n,vector<uli>(m,0x7ffffffffffffff));
    dijkstra(arr,disa,{0,--a},n,m),
    dijkstra(arr,disb,{n-1,--b},n,m),
    dijkstra(arr,disc,{n-1,--c},n,m);
#ifdef debug
    for (vector<vector<uli>> const& a:{disa,disb,disc}) for (size_t i=0;i<n;i++){for (size_t j=0;j<m;j++) cout<<a[i][j]<<' ';cout<<'\n';}
#endif
    uli ans=-1;
    for (size_t i=0;i<n;i++) for (size_t j=0;j<m;j++)
        ans=min(ans,disa[i][j]+disb[i][j]+disc[i][j]-(arr[i][j]<<1));
    cout<<ans;
    return 0;
}