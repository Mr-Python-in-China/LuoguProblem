#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    vector<pair<int,size_t>> a(n);
    for (size_t i=0;i<n;i++) cin>>a[i].first,a[i].second=i;
    sort(a.begin(),a.end());
    for (pair<int,size_t> const& i:a) cout<<i.second+1<<' ';
    return 0;
}