#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    ui maxx=0;
    vector<pair<ui,ui>> down;
    for (size_t i=0;i<n;i++){
        ui a,b;
        cin>>a>>b;
        if (a>b) down.push_back({a,b});
        maxx=max({maxx,a,b});
    }
    sort(down.begin(),down.end(),[](pair<ui,ui> const& a,pair<ui,ui> const& b){
        return a.second==b.second?a.first<b.first:a.second>b.second;
    });
    ui lowist=maxx;
    size_t ans=maxx;
    for (pair<ui,ui> const& i:down){
        if (i.second>lowist||lowist-i.second<=((i.first-i.second)<<1))
            lowist=min(lowist,i.second);
        else ans+=(i.first-i.second)<<1;
    }
    cout<<(ans+=maxx-lowist);
    return 0;
}