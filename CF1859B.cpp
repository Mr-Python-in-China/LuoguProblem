#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n;
        cin>>n;
        vector<pair<ui,ui>> minx(n,{-1,-1});
        for (pair<ui,ui>& i:minx){
            size_t m;
            cin>>m;
            while (m--){
                ui x;
                cin>>x;
                if (x<=i.first) i.second=i.first,i.first=x;
                else if (x<=i.second) i.second=x;
            }
        }
        sort(minx.begin(),minx.end(),[](pair<ui,ui> const& a,pair<ui,ui> const& b){return a.second<b.second;});
        ui ans=-1;
        for (pair<ui,ui> const& i:minx) ans=min(ans,i.first);
        for (size_t i=1;i<n;i++) ans+=minx[i].second;
        cout<<ans<<'\n';
    }
    return 0;
}