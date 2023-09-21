#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,m;uli d;
        cin>>n>>m>>d;
        vector<size_t> a(n);
        for (size_t i=0;i<n;i++) cin>>a[i],a[i]-=(i+1)*d;
        size_t end_minn_pos(n);// 到结尾的最小值
        end_minn_pos[n-1]=n-1;
    }
    return 0;
}