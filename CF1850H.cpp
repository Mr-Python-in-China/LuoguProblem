#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
class dsds{
    struct node{size_t p;long long int dis;};
    vector<node> fa;
    node find(size_t x){
        if (x==fa[x].p) return {x,0};
        else{
            node res=find(fa[x].p);
            return fa[x]={res.p,res.dis+fa[x].dis};
        }
    }
public:
    dsds(size_t n):fa(n){for (size_t i=0;i<n;i++) fa[i].p=i;}
    bool merge(size_t x,size_t y,long long int dis){
        node fax=find(x),fay=find(y);
        if (fax.p!=fay.p){
            fa[fax.p]={fay.p,-fax.dis+fay.dis+dis};
            return true;
        }else return fax.dis==fay.dis+dis;
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,m;bool flag=true;
        cin>>n>>m;
        dsds ds(n);
        while (m--){
            size_t a,b;long long int d;
            cin>>a>>b>>d;
            if (!ds.merge(--a,--b,d)) flag=false;
        }
        cout<<(flag?"YES":"NO")<<'\n';
    }
    return 0;
}