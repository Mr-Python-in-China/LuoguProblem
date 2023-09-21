#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
template<typename T> class PrefixSum{
    vector<T> sum;
public:
    template<typename InputIterator,typename=_RequireInputIter<InputIterator>>
    PrefixSum(InputIterator begin,size_t n):sum(n+1){
        typename vector<T>::iterator it=next(sum.begin());
        while (true){
            *it=*prev(it)+*begin;
            if (++it>=sum.end()) break;
            ++begin;
        }
    }
    T get_sum(size_t m,size_t n){
        return sum[n]-sum[m];
    }
    T get_val(size_t m){
        return get_sum(m,m+1);
    }
    T operator[](size_t m){
        return get_val(m);
    }
    size_t size(void){return sum.size();}
};
template<typename T> class Difference{
    vector<T> d;
public:
    template<typename InputIterator,typename=_RequireInputIter<InputIterator>>
    Difference(InputIterator begin,size_t n):d(n){
        InputIterator lst(begin++);
        typename vector<T>::iterator it=d.begin();
        *(it++)=*lst;
        while (true){
            *it=*begin-*lst;
            if (++it>=d.end()) break;
            lst=begin++;
        }
    }
    void add_interval(size_t l,size_t r,T val){
        d[l]+=val;
        if (r<d.size()) d[r]-=val;
    }
    template<typename OutputIterator> void get_arr(OutputIterator output){
        typename vector<T>::iterator it=d.begin();
        while (true){
            *output=*it;
            if (++it>=d.end()) break;
            ++output;
        }
    }
};
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
    size_t n;
    cin>>n;
    Difference<int> d(istream_iterator<int>(cin),n);
    d.get_arr(ostream_iterator<int>(cout," "));
    return 0;
}