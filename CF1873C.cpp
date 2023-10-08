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
        ui ans=0;
        for (size_t i=0;i<10;++i) for (size_t j=0;j<10;++j){
            char c;
            cin>>c;
            if (c=='X') ans+=(i==0||i==9||j==0||j==9?1:
                              i==1||i==8||j==1||j==8?2:
                              i==2||i==7||j==2||j==7?3:
                              i==3||i==6||j==3||j==6?4:
                              i==4||i==5||j==4||j==5?5:
                              -1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}