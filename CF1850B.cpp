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
        size_t winner;ui winb=0;
        for (size_t i=0;i<n;i++){
            ui a,b;cin>>a>>b;
            if (a<=10&&b>winb) winb=b,winner=i;
        }
        cout<<winner+1<<'\n';
    }
    return 0;
}