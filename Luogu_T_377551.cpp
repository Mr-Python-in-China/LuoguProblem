#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        ui x,a;
        cin>>x>>a;
        for (ui nx=(x+a)/a;nx!=x;x=nx,nx=(x+a)/a) cout<<x<<' ';
        cout<<x<<'\n';
    }
    return 0;
}