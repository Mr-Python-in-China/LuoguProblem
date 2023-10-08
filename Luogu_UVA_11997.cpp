#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;
    while (cin>>n){
        vector<uli> a(n);
        for (uli& i:a) cin>>i;
        for (size_t i=1;i<n;++i){
            vector<uli> b(n);
            for (uli& j:b) cin>>j;
            sort(b.begin(),b.end());
            pbds::priority_queue<pair<uli,size_t>,greater<pair<uli,size_t>>> q;
            for (size_t j=0;j<n;++j) q.push({a[j]+b[0],0});
            for (uli& j:a){
                pair<uli,size_t> t=q.top();q.pop();
                j=t.first;
                if (t.second+1<n) q.push({t.first-b[t.second]+b[t.second+1],t.second+1});
            }
        }
        for (size_t i=0;i<n;++i) cout<<a[i]<<"\n "[i+1<n];
    }
    return 0;
}