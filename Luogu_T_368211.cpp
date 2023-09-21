#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using uli=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,k;
        cin>>n>>k;
        map<size_t,uli> days;
        while (n--){
            size_t a,b;
            cin>>a>>b;
            days[a]+=b;
        }
        size_t lst=0;uli have=0;
        for (pair<size_t,uli> const& i:days){
            have+=(i.first-lst)*k;
            if (have<i.second){cout<<"No\n";goto fail;}
            have-=i.second;
            lst=i.first;
        }
        cout<<"Yes\n";
        fail:;
    }
    return 0;
}