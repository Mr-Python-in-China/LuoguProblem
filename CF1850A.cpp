#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t a,b,c;
        cin>>a>>b>>c;
        cout<<(a+b>=10||b+c>=10||a+c>=10?"YES":"NO")<<'\n';
    }
    return 0;
}