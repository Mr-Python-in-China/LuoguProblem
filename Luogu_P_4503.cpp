#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
li constexpr P0=1e9+7,P1=1e9+9;
template<typename T0,typename T1> struct myhash{
    size_t operator()(pair<T0,T1> const& x) const{return T0(x.first)<<32|T1(x.second);}
};
template<typename T> constexpr bool is_prime(T n){
    if (n<2) return false;
    for (T i=2;i*i<=n;i++) if (n%i==0) return false;
    return true;
}
template<typename T,T P> class ModInt;
template<typename T=li,T P=1'000'000'007> constexpr T ksm(ModInt<T,P> a,T n){
    ModInt<T,P> ans=1;
    while (n){
        if (n&1) ans*=a;
        ans*=ans;
        n>>=1;
    }
    return ans;
}
template<typename T=li,T P=1'000'000'007> class ModInt{
    T x;
public:
    ModInt(void):x(){}
    ModInt(T _x):x(_x%P){if (x<0) x+=P;}
    operator T(void){return x;}
    ModInt& operator+=(T v){
        (x+=v)%=P;
        if (x<0) x+=P;
        return *this;
    }
    ModInt& operator-=(T v){
        (x-=v)%=P;
        if (x<0) x+=P;
        return *this;
    }
    ModInt& operator*=(T v){
        (x*=v)%=P;
        if (x<0) x+=P;
        return *this;
    }
    ModInt& operator/=(T v){
        static_assert(is_prime(P));
        (x*=ksm<T,P>(v,P-2))%=P;
        return *this;
    }
    ModInt& operator+=(ModInt v){return *this+=T(v);}
    ModInt& operator-=(ModInt v){return *this-=T(v);}
    ModInt& operator*=(ModInt v){return *this*=T(v);}
    ModInt& operator/=(ModInt v){return *this/=T(v);}
    ModInt operator+(T v) const{ModInt<T,P> tmp=*this;return tmp+=v;}
    ModInt operator-(T v) const{ModInt<T,P> tmp=*this;return tmp-=v;}
    ModInt operator*(T v) const{ModInt<T,P> tmp=*this;return tmp*=v;}
    ModInt operator/(T v) const{ModInt<T,P> tmp=*this;return tmp/=v;}
    ModInt operator+(ModInt v) const{ModInt<T,P> tmp=*this;return tmp+=v;}
    ModInt operator-(ModInt v) const{ModInt<T,P> tmp=*this;return tmp-=v;}
    ModInt operator*(ModInt v) const{ModInt<T,P> tmp=*this;return tmp*=v;}
    ModInt operator/(ModInt v) const{ModInt<T,P> tmp=*this;return tmp/=v;}
    friend istream& operator>>(istream& in,ModInt& x){
        in>>x.x;
        x.x%=P;
        return in;
    }
    friend bool operator==(ModInt a,ModInt b){return a.x==b.x;}
};
ModInt<li,P0> const N256_0=ksm<li,P0>(256,P0-2);
ModInt<li,P1> const N256_1=ksm<li,P1>(256,P1-2);
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,l,s_s;
    cin>>n>>l>>s_s;
    vector<vector<pair<ModInt<li,P0>,ModInt<li,P1>>>> hs(n,vector<pair<ModInt<li,P0>,ModInt<li,P1>>>(l+1));
    for (size_t i=0;i<n;++i){
        ModInt<li,P0> w0=1;ModInt<li,P1> w1=1;
        for (size_t j=1;j<=l;++j,w0*=256,w1*=256){
            char c;cin>>c;
            hs[i][j].first=hs[i][j-1].first+li(c)*w0,
            hs[i][j].second=hs[i][j-1].second+li(c)*w1;
        }
    }
    size_t ans=0;
    for (size_t i=0;i<l;++i){
        unordered_map<pair<ModInt<li,P0>,ModInt<li,P1>>,size_t,myhash<ModInt<li,P0>,ModInt<li,P1>>> cnt;
        for (vector<pair<ModInt<li,P0>,ModInt<li,P1>>> const& j:hs)
            ++cnt[{(j[l].first-j[i+1].first)*N256_0+j[i].first,
                (j[l].second-j[i+1].second)*N256_1+j[i].second}];
        for (auto const& i:cnt) ans+=(i.second-1)*i.second>>1;
    }
    cout<<ans;
    return 0;
}
