#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;ui k;
    cin>>n>>k;n<<=1;
    vector<ui> a(n);
    vector<ui> xiangxian(k);
    for (size_t i=0;i<n;i++) cin>>a[i],xiangxian[(i+1)%k]+=a[i];
    for (size_t i=0;i<n;i++){
        if ((i+1)&1) a[i]=xiangxian[(i+1)%k]%(i+1);
        cout<<a[i]<<' ';
    }
    return 0;
}