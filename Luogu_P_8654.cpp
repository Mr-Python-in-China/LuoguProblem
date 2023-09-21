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
    size_t count(void){
        unordered_set<size_t> unique;
        for (size_t const& i:fa) unique.insert(find(i));
        return unique.size();
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t m,n,k;
    cin>>m>>n>>k;
    dsds ds(n*m);
    while (k--){
        size_t a,b;
        cin>>a>>b;
        ds.merge(a,b);
    }
    cout<<ds.count();
    return 0;
}