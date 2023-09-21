#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using uli=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    uli n,k;
    cin>>n>>k;
    for (uli T=1ul<<(n-1);T;T>>=1){
        if (k<T) cout.put('0');
        else cout.put('1'),k=(~k)&(T-1);
    #ifdef debug
        cout<<"";
    #endif
    }
    return 0;
}