#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,ans=1;ui lst;
        cin>>n>>lst;
        stringstream sout;
        sout<<lst<<' ';
        for (size_t i=1;i<n;++i){
            ui now;
            cin>>now;
            if (lst>now) sout<<"1 ",++ans;
            sout<<now<<' ',++ans;
            lst=now;
        }
        cout<<ans<<'\n'<<sout.str()<<'\n';
    }
    return 0;
}