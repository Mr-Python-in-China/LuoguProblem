#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    cin>>n;
    vector<pair<ui,ui>> a(n);
    for (pair<ui,ui>& i:a) cin>>i.first>>i.second;
    sort(a.begin(),a.end());
    ui lsttypemax=0,thistypemax=a.front().second,ans=a.front().second+(thistypemax>>1);
    for (size_t i=1;i<n;i++){
        if (a[i-1].first!=a[i].first) lsttypemax=max(lsttypemax,thistypemax),thistypemax=0;
        thistypemax=max(thistypemax,a[i].second);
        ans=max({ans,a[i].second+lsttypemax,a[i].second+(thistypemax>>1)});
    }
    cout<<ans;
    return 0;
}