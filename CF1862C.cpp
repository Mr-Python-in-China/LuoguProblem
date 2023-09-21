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
        vector<ui> a(n);
        map<size_t,ui> mp;
        for (size_t i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]=i+1;
        }
        bool flag=true;
        for (size_t i=0;i<n;i++){
            map<size_t,ui>::const_iterator it=mp.lower_bound(i+1);
            if (it->second!=a[i]) flag=false;
        }
        cout<<(flag?"YES\n":"NO\n");
    }
    return 0;
}