#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using li=long long int;
struct pos{
    int x,y;
    pos():x(0),y(0){}
    pos(li _x,li _y):x(_x),y(_y){}
    friend istream& operator>>(istream& in,pos& p){return in>>p.x>>p.y;}
    double dis(pos const& p) const{return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));}
};
struct dsds{
    vector<size_t> fa;
    size_t find(size_t x){return fa[x]==x?x:fa[x]=find(fa[x]);}

    dsds(size_t n):fa(n){
        for (size_t i=0;i<n;i++) fa[i]=i;
    }
    void merge(size_t a,size_t b){fa[find(a)]=find(b);}
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t s,p;
    cin>>s>>p;
    vector<pos> a(p);
    for (pos& i:a) cin>>i;
    double l=0,r=20000;
    while (r-l>1e-3){
        double mid=(l+r)/2;
        dsds ds(p);
        for (size_t i=0;i<p;++i) for (size_t j=i+1;j<p;++j)
            if (a[i].dis(a[j])<=mid) ds.merge(i,j);
        unordered_set<size_t> cnt;
        for (size_t i=0;i<p;i++) cnt.insert(ds.find(i));
        (cnt.size()<=s?r:l)=mid;
    }
    cout<<fixed<<setprecision(2)<<l;
    return 0;
}