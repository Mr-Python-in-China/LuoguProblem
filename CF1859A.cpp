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
        for (ui& i:a) cin>>i;
        sort(a.begin(),a.end());
        vector<ui>::const_iterator sper=lower_bound(a.begin(),a.end(),a.back());
        if (sper==a.begin()) cout<<"-1\n";
        else{
            cout<<sper-a.begin()<<' '<<a.end()-sper<<'\n';
            for (vector<ui>::const_iterator it=a.begin();it<sper;it++) cout<<*it<<' ';
            cout.put('\n');
            for (vector<ui>::const_iterator it=sper;it<a.end();it++) cout<<*it<<' ';
            cout.put('\n');
        }
    }
    return 0;
}