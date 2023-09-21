#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using uli=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,T;
    cin>>n>>T;
    size_t ansp=0;uli ansv=0;
    for (size_t i=0;i<n;i++){
        uli v,t;
        cin>>v>>t;
        if ((T>=t?T-t:0)*v>ansv) ansv=(T>=t?T-t:0)*v,ansp=i;
    }
    cout<<ansp+1;
    return 0;
}