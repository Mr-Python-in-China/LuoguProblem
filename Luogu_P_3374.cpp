#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using li=long long int;
template<typename T> class FenwickTree{
    vector<T> tree;
    // To get sum in interval [0,p) (no p).
    T prefix_sum(size_t p){
        T res=0;
        for (--p;p<tree.size();--(p&=(p+1))) res+=tree[p];
        return res;
    }
public:
    template<typename InputIterator,typename=_RequireInputIter<InputIterator>>
    FenwickTree(InputIterator begin,size_t n):tree(n){
        size_t i=0;
        while (true){
            add(i,*begin);
            if (++i>=n) break;
            ++begin;
        }
    }
    void add(size_t p,T const& val){
        for (;p<tree.size();p|=p+1) tree[p]+=val;
    }
    int get_sum(size_t l,size_t r){
        return prefix_sum(r)-prefix_sum(l);
    }
};
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    FenwickTree<li> tree(istream_iterator<li>(cin),n);
    while (m--){
        char c;size_t x;
        cin>>c>>x;
        if (c=='1'){
            li k;
            cin>>k;
            tree.add(--x,k);
        }else{
            size_t y;
            cin>>y;
            cout<<tree.get_sum(--x,y)<<'\n';
        }
    }
    return 0;
}