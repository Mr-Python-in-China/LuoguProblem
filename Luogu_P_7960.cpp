#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
bool p(ui x){
    while (x){
        if (x%10==7) return false;
        x/=10;
    }
    return true;
}
bitset<10000100> ans;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    for (size_t i=1;i<ans.size();i++) if (!ans[i]&&!p(i))
        for (size_t j=i;j<ans.size();j+=i) ans[j]=true;
    vector<ui> val;
    for (size_t i=0;i<ans.size();i++) if (!ans[i]) val.push_back(i);
    size_t T;
    cin>>T;
    while (T--){
        ui x;
        cin>>x;
        vector<ui>::const_iterator resit=lower_bound(val.cbegin(),val.cend(),x);
        if (ans[x]) cout<<"-1\n";
        else cout<<*next(resit)<<'\n';
    }
    return 0;
}