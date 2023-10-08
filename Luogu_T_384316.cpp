#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
struct vir{
    size_t l,r;uli k;
};
template<typename T,typename cmp=less<T>> struct STtable{
    vector<vector<size_t>> table;
    vector<T> arr;
    static size_t lg2(size_t x){return log2(max<size_t>(--x,1))+1;}
    size_t getcmp(size_t x,size_t y){return cmp()(arr[x],arr[y])?x:y;}
    template<typename InputIterator,typename=_RequireInputIter<InputIterator>>
    STtable(InputIterator it,size_t n):arr(n),table(lg2(n)){
        std::copy_n(it,n,arr.begin());
        table.front().resize(n);
        iota(table.front().begin(),table.front().end(),size_t());
        for (size_t i=1;i<table.size();i++){
            size_t k=1<<i;
            table[i].resize(n-k+1);
            for (size_t r=k;r<=n;r++)
                table[i][r-k]=getcmp(table[i-1][r-k],table[i-1][r-(k>>1)]);
        }
    }
    T const& operator[](size_t p){return arr[p];}
    size_t getpos(size_t l,size_t r){
        if (l==r) return -1;
        size_t k=lg2(r-l)-1;
        return getcmp(table[k][l],table[k][r-(1<<k)]);
    }
    size_t getval(size_t l,size_t r){return arr[getpos(l,r)];}
};
template<typename T> struct Difference{
    vector<T> d;
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
    Difference(size_t n):d(n){}
    void add_interval(size_t l,size_t r,T val){
        d[l]+=val;
        if (r<d.size()) d[r]-=val;
    }
    template<typename OutputIterator> void get_arr(OutputIterator output){
        T sum=0;
        typename vector<T>::iterator it=d.begin();
        while (true){
            *output=(sum+=*it);
            if (++it>=d.end()) break;
            ++output;
        }
    }
};
int main(void){
    //freopen("virus.in","r",stdin),freopen("virus.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    Difference<li> d(m);
    vector<vir> a(n);
    for (vir& i:a)
        cin>>i.l>>i.r>>i.k,
        d.add_interval(--i.l,i.r,i.k);
    vector<uli> ov(m);
    d.get_arr(ov.begin());
    STtable<uli,greater<uli>> st(ov.begin(),m);
    for (vir const& i:a){
        size_t q0=st.getpos(0,i.l),q1=st.getpos(i.l,i.r),q2=st.getpos(i.r,m);
        cout<<max({~q0?ov[q0]:0,~q1?ov[q1]-i.k:0,~q2?ov[q2]:0})<<'\n';
    }
    return 0;
}