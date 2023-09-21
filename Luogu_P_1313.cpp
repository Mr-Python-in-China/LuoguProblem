#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
size_t const N=1001;
uli const p=10007;
uli ksm(uli a,uli n){
    a%=p;
    uli ans=1;
    while (n){
        if (n&1) (ans*=a)%=p;
        (a*=a)%=p;
        n>>=1;
    }
    return ans;
}
array<array<uli,N>,N> c;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    {
        c[0][0]=1;
        for (size_t i=1;i<N;i++){
            c[i][0]=1;
            for (size_t j=1;j<=i;j++)
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%10007;
        }
    }
    size_t a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    assert(k==n+m);
    cout<<ksm(a,n)*ksm(b,m)%p*c[k][min(n,m)]%p;
    return 0;
}