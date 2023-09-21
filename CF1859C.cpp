#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned long long int;
ui getval(vector<ui> const& a){
    size_t const n=a.size();
    ui res=0,maxx=0;
    for (size_t i=0;i<n;i++) res+=a[i]*(i+1),maxx=max<ui>(maxx,a[i]*(i+1));
    return res-maxx;
}
ui output[251];
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    for (size_t n=1;n<=250;n++){
        vector<ui> a(n);
        iota(a.begin(),a.end(),1);
        ui ans=0;ui ti=0;
        for (size_t i=1;i<=n;i++){
            reverse(a.end()-i,a.end());
            ui tmpval=getval(a);
            ans=max(ans,tmpval);
            reverse(a.end()-i,a.end());
        }
        output[n]=ans;
    }
    size_t T;
    cin>>T;
    while (T--){
        size_t x;
        cin>>x;
        cout<<output[x]<<'\n';
    }
    return 0;
}