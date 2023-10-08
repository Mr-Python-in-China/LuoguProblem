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
        char op;size_t n;ui x;
        cin>>op>>n>>x;
        if (op=='1')
            if (n>x+1) cout<<"-1";
            else{
                cout<<x-n+2<<' '<<x-n+2<<' ';
                for (size_t i=2;i<n;++i) cout<<1<<' ';
            }
        else{
            if (n>x+1) cout<<"-1";
            else{
                cout<<x-n+2<<' ';
                for (size_t i=1;i<n;++i) cout<<1<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}