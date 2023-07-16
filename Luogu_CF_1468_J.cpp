#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
struct edge{
    size_t u,v;ui w;
    friend bool operator<(edge const& a,edge const& b){return a.w<b.w;}
    friend istream& operator>>(istream& in,edge& e){return in>>e.u>>e.v>>e.w;}
};
class dsds{
    vector<size_t> fa;
    size_t find(size_t x){return x==fa[x]?x:fa[x]=find(fa[x]);}
public:
    dsds(size_t n):fa(n){for (size_t i=0;i<n;i++) fa[i]=i;}
    bool in_one_set(size_t x,size_t y){return find(x)==find(y);}
    void merge(size_t x,size_t y){fa[find(x)]=find(y);}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,m;ui k;
        cin>>n>>m>>k;
        vector<edge> e(m);
        for (edge& i:e) cin>>i,--i.u,--i.v;
        sort(e.begin(),e.end());
        vector<ui> ans;ans.reserve(n-1);
        dsds ds(n);
        for (edge const& i:e) if (!ds.in_one_set(i.u,i.v)){
            ds.merge(i.u,i.v);
            ans.push_back(i.w);
            if (ans.size()>=n-1) break;
        }
        if (ans.back()==k) cout<<'0';
        else if (ans.back()<k){
            ui x=-1;
            for (edge const& i:e) x=min(x,max(k,i.w)-min(k,i.w));
            cout<<x;
        }else{
            ui x=0;
            vector<ui>::const_reverse_iterator it=ans.crbegin();
            while (*it>k) x+=*(it--)-k;
            cout<<x;
        }
        cout.put('\n');
    }
    return 0;
}