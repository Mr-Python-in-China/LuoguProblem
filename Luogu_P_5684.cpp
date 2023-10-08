#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
li constexpr P=1e9+7;
li frac(size_t x){
    static array<li,2001> arr({});
    if (!arr[0]){
        arr[0]=1;
        for (size_t i=1;i<arr.size();++i) (arr[i]=arr[i-1]*i)%=P;
    }
    return arr[x];
}
li quick_pow(li a,li n){
    li ans=1;
    while (n){
        if (n&1) (ans*=a)%=P;
        (a*=a)%=P;
        n>>=1;
    }
    return ans;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    array<size_t,256> cnt({});
    for (size_t i=0;i<n;++i){
        char c;
        cin>>c;
        ++cnt[c];
    }
    char even_pos=0;
    for (char i='a';i<='z';++i) if (cnt[i]&1)
        if (n&1^1||even_pos) cout<<frac(n),exit(0);
        else even_pos=i;
    li enble_count=frac(n>>1);
    for (char i='a';i<='z';++i)
        (enble_count*=quick_pow(frac(cnt[i]>>1),P-2))%=P;
    for (char i='a';i<='z';++i) (enble_count*=frac(cnt[i]))%=P;
    cout<<((frac(n)-enble_count)%P+P)%P;
    return 0;
}