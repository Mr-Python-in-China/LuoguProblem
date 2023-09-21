#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using uli=unsigned long long int;
template<typename T> class PrefixSum{
    vector<T> sum;
public:
    PrefixSum(vector<T> const& a):sum(a.size()+1){
        for (size_t i=1;i<=a.size();++i) sum[i]=sum[i-1]+a[i-1];
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
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t op,n,k;
    cin>>op>>n>>k;--k;
    vector<uli> a(n);
    for (uli& i:a) cin>>i;
    vector<uli> b(a);
    sort(b.rbegin(),b.rend());
    PrefixSum<uli> s(b);
    for (uli const& i:a)
        if (i==b[k]) cout<<"0\n";
        else if (i<b[k]) cout<<b[k]-i<<'\n';
        else{
            size_t p=b.crend()-lower_bound(b.crbegin(),b.crend(),i)-1;
            cout<<b[p]*(k+1-p)-s.get_sum(p,k+1)<<'\n';
        }
    return 0;
}