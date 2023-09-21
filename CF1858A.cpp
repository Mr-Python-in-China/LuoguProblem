#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        ui a,b,c;
        cin>>a>>b>>c;
        cout<<(((c+1)>>1)+a>(c>>1)+b?"First":"Second")<<'\n';
    }
    return 0;
}