#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
template<typename T,typename cmp=less<T>> class STtable{
    vector<vector<T>> table;
    static size_t lg2(size_t x){return log2(max<size_t>(--x,1))+1;}
    static T const& getcmp(T const& x,T const& y){return cmp()(x,y)?x:y;}
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
    T const& operator[](size_t p){return table.front()[p];}
    T const& get(size_t l,size_t r){
        size_t k=lg2(r-l)-1;
        return getcmp(table[k][l],table[k][r-(1<<k)]);
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n),b(m);
    for (int& i:a) cin>>i;
    for (int& i:b) cin>>i;
    STtable<int,less<int>> al(a.cbegin(),n),bl(b.cbegin(),m);
    STtable<int,less<int>> ag(a.cbegin(),n),bg(b.cbegin(),m);
    
    return 0;
}