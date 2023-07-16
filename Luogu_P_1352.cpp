#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using tree=vector<vector<size_t>>;
void dfs(vector<int> const& r,tree const& t,vector<pair<int,int>>& f,size_t const& p){
    f[p].first=r[p],f[p].second=0;
    for (size_t const& i:t[p]){
        dfs(r,t,f,i);
        f[p].first+=f[i].second,f[p].second+=max(f[i].first,f[i].second);
    }
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<int> r(n);
    for (int& i:r) cin>>i;
    tree t(n);
    size_t root=0;
    for (size_t i=0;i<n;i++) root^=i;
    for (size_t i=1;i<n;i++){
        size_t l,k;
        cin>>l>>k;
        t[--k].push_back(--l);
        root^=l;
    }
    vector<pair<int,int>> f(n);  // first: 来了    second: 没来
    dfs(r,t,f,root);
    cout<<max(f[root].first,f[root].second);
    #ifdef debug
    cout.put('\n');
    for (pair<int,int> const& i:f) cout<<i.first<<' '<<i.second<<'\n';
    #endif
    return 0;
}