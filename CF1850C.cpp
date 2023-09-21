#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        string ans;
        for (size_t i=0;i<8;i++) for (size_t j=0;j<8;j++){
            char c;
            cin>>c;
            if (c!='.') ans+=c;
        }
        cout<<ans<<'\n';
    }
    return 0;
}