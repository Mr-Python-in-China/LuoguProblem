#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using uli=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n;uli x;
        cin>>n>>x;
        size_t sz=min<size_t>(__builtin_ctz(x)+2,n);
        cout<<(x<<(n-sz))<<'\n';
    }
    return 0;
}