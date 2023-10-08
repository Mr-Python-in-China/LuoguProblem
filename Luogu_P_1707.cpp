#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
uli P;
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
    uli n,q,p,r,t,u,v,w,x,y,z;
    cin>>n>>P>>p>>q>>r>>t>>u>>v>>w>>x>>y>>z;
    array<__uint128_t,3> ans;
    if (n==1) ans={1,1,1};
    else{
        matrix<__uint128_t,1,11> a;a.m={3,3,3,1,1,1,1,1,w,z,1};
        matrix<__uint128_t,11,11> m;m.m={
            array<__uint128_t,11>{p,1,1,1,0,0,0,0,0,0,0},
            array<__uint128_t,11>{1,u,1,0,1,0,0,0,0,0,0},
            array<__uint128_t,11>{1,1,x,0,0,1,0,0,0,0,0},
            array<__uint128_t,11>{q,0,0,0,0,0,0,0,0,0,0},
            array<__uint128_t,11>{0,v,0,0,0,0,0,0,0,0,0},
            array<__uint128_t,11>{0,0,y,0,0,0,0,0,0,0,0},
            array<__uint128_t,11>{t,0,1,0,0,0,1,2,0,0,0},
            array<__uint128_t,11>{r,0,0,0,0,0,0,1,0,0,0},
            array<__uint128_t,11>{0,1,0,0,0,0,0,0,w,0,0},
            array<__uint128_t,11>{0,0,1,0,0,0,0,0,0,z,0},
            array<__uint128_t,11>{1,0,2,0,0,0,1,1,0,0,1}
        };
        copy_n((a*quick_pow(m,n-1)).m[0].begin()+3,3,ans.begin());
    }
    cout<<"nodgd "<<uli(ans[0])<<"\nCiocio "<<uli(ans[1])<<"\nNicole "<<uli(ans[2]);
    return 0;
}