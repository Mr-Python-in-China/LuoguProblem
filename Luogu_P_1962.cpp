#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
uli constexpr P=1e9+7;
template<typename T,size_t N,size_t M> struct matrix{
    array<array<T,M>,N> m{};
    template<size_t L> friend matrix<T,N,L> operator*(matrix<T,N,M> const& a,matrix<T,M,L> const& b){
        matrix<T,N,L> ans;
        for (size_t i=0;i<N;++i) for (size_t j=0;j<L;++j) for (size_t k=0;k<M;++k){
            (ans.m[i][j]+=a.m[i][k]*b.m[k][j])%=P;
            if (ans.m[i][j]<0) ans.m[i][j]+=P;
        }
        return ans;
    }
    matrix& operator*=(matrix<T,N,N> const& x){
        return *this=*this*x;
    }
};
template<typename T,size_t N> matrix<T,N,N> quick_pow(matrix<T,N,N> a,uli k){
    matrix<T,N,N> ans;
    for (size_t i=0;i<N;++i) ans.m[i][i]=1;
    while (k){
        if (k&1) ans*=a;
        a*=a;
        k>>=1;
    }
    return ans;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    uli n;
    cin>>n;
    if (n==1) cout<<'1';
    else{
        matrix<uli,1,2> a;a.m[0][0]=a.m[0][1]=1;
        matrix<uli,2,2> m;
        m.m[0][0]=0,m.m[1][0]=1,
        m.m[0][1]=1,m.m[1][1]=1;
        cout<<((a*quick_pow(m,n-2)).m[0][1]);
    }
    return 0;
}