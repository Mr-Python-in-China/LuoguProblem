#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
class DSDS{
    vector<size_t> fa;
    size_t find(size_t x){return fa[x]==x?x:fa[x]=find(fa[x]);}
public:
    DSDS(size_t n):fa(n){iota(fa.begin(),fa.end(),size_t(0));}
    void merge(size_t x,size_t y){fa[find(x)]=find(y);}
    bool in_one_set(size_t x,size_t y){return find(x)==find(y);}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,m;
        cin>>n>>m;
        DSDS ds(n);
        size_t ans=0;
        while (m--){
            size_t x,y;
            cin>>x>>y;--x,--y;
            if (ds.in_one_set(x,y)) ++ans;
            else ds.merge(x,y);
        }
        cout<<ans<<'\n';
    }
    return 0;
}