#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
template<typename T> class STtable{
    vector<vector<T>> table;
    static size_t lg2(size_t x){return log2(max<size_t>(--x,1))+1;}
    static T getcmp(T const& x,T const& y){return x&y;}
public:
    template<typename InputIterator,typename=_RequireInputIter<InputIterator>>
    STtable(InputIterator it,size_t n):table(lg2(n)){
        table.front().resize(n);
        std::copy_n(it,n,table.front().begin());
        for (size_t i=1;i<table.size();i++){
            size_t k=1<<i;
            table[i].resize(n-k+1);
            for (size_t r=k;r<=n;r++)
                table[i][r-k]=getcmp(table[i-1][r-k],table[i-1][r-(k>>1)]);
        }
    }
    T operator[](size_t p){return table.front()[p];}
    T get(size_t l,size_t r){
        size_t k=lg2(r-l)-1;
        return getcmp(table[k][l],table[k][r-(1<<k)]);
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,q;
        cin>>n;
        STtable<ui> stand(istream_iterator<ui>(cin),n);
        cin>>q;
        while (q--){
            size_t p,l,r=n;ui k;
            cin>>p>>k;l=--p;
            while (l<r){
                size_t mid=(l+r+1)>>1;
                stand.get(p,mid)>=k?l=mid:r=mid-1;
            }
            if (r<=p) cout<<"-1 ";
            else cout<<l<<' ';
        }
        cout<<'\n';
    }
    return 0;
}