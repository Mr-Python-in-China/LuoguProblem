#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
class dsds{
    vector<size_t> fa;
    size_t find(size_t x){return fa[x]==x?x:fa[x]=find(fa[x]);}
public:
    dsds(size_t n):fa(n){iota(fa.begin(),fa.end(),0);}
    void merge(size_t x,size_t y){fa[find(x)]=find(y);}
    bool in_one_set(size_t x,size_t y){return find(x)==find(y);}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    dsds ds(n);
    while (m--){
        char op;size_t x,y;
        cin>>op>>x>>y;--x,--y;
        if (op=='1') ds.merge(x,y);
        else cout<<(ds.in_one_set(x,y)?'Y':'N')<<'\n';
    }
    return 0;
}