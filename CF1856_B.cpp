#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n;
        cin>>n;
        size_t cnt_1=0;
        for (size_t i=0;i<n;i++){
            ui x;
            cin>>x;
            if (x==1) cnt_1++;
        }
        if (n==1||n-cnt_1<cnt_1) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}