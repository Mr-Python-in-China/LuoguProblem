#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using graph=vector<vector<size_t>>;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    graph mp(n);
    while (m--){
        size_t x,y;
        cin>>x>>y;
        mp[--y].push_back(--x);
    }
    size_t ans=0,cnt=0;
    for (size_t i=0;i<n;i++) if (mp[i].empty()) ans=i,cnt++;
    if (cnt!=1) cout<<"-1";
    else cout<<ans+1;
    return 0;
}