#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        uli n,x,k;
        cin>>n>>k>>x;
        cout<<(x<=((n+(n-k+1))*k/2)&&x>=(1+k)*k/2?"YES\n":"NO\n");
    }
    return 0;
}