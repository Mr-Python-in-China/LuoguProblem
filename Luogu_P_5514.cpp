#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    ui ans=0;
    while (n--){
        ui x;
        cin>>x;
        ans^=x;
    }
    cout<<ans;
    return 0;
}