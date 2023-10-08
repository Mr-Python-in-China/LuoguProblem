#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
using graph=vector<vector<pair<size_t,ui>>>;
struct trie{
    struct node{
        size_t cnt;
        node* son[2];
        node(node&)=delete;
        node(void):cnt(),son{nullptr,nullptr}{};
    }root;
    trie(void):root(){}
    void insert(ui x){
        node* p=&root;
        for (size_t i=0;i<sizeof(ui)*8;++i,x<<=1){
            bool v=x>>(sizeof(ui)*8-1)&1;
            if (!p->son[v]) p->son[v]=new node;
            p=p->son[v];
        }
        ++p->cnt;
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    graph mp(n);
    for (size_t i=1;i<n;++i){
        size_t u,v;ui w;
        cin>>u>>v>>w;--u,--v;
        mp[u].push_back({v,w}),mp[v].push_back({u,w});
    }
    vector<ui> xor_dist(n,-1);
    queue<size_t> q({0});xor_dist[0]=0;
    while (!q.empty()){
        size_t p=q.front();q.pop();
        for (pair<size_t,ui>& i:mp[p]) if (!~xor_dist[i.first])
            q.push(i.first),xor_dist[i.first]=xor_dist[p]^i.second;
    }
    trie t;
    for (ui i:xor_dist) t.insert(i);
    ui ans=0;
    for (ui i:xor_dist){
        ui p=i,x=0;
        trie::node* it=&t.root;
        while (it->son[0]||it->son[1]){
            x<<=1;
            if (it->son[0]&&!it->son[1]) it=it->son[0],x|=0;
            else if (!it->son[0]&&it->son[1]) it=it->son[1],x|=1;
            else it=it->son[i>>(sizeof(ui)*8-1)&1^1],x|=i>>(sizeof(ui)*8-1)&1^1;
            i<<=1;
        }
        ans=max(ans,p^x);
    }
    cout<<ans;
    return 0;
}