#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;char c;
    cin>>n>>m>>c;
    if (c!='N') return cout<<"No solution",0;
    vector<size_t> ans(1);
    size_t cnt=0;
    for (size_t i=1;i<m;++i){
        cin>>c;
        if (c=='N'){
            ans.push_back(++cnt);
            if (cnt>=n) return cout<<"No solution",0;
        }else ans.push_back(0);
    }
    for (size_t const& i:ans) cout<<i+1<<' ';
    return 0;
}