#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    vector<ui> a(n);
    for (ui& i:a) cin>>i;
    size_t ans=0;
    while (m--){
        size_t x;
        cin>>x;--x;
        if (x<n&&a[x]<200) ++ans;
    }
    cout<<ans;
    return 0;
}