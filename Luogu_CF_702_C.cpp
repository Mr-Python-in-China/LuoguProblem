#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n,m;
    cin>>n>>m;
    vector<li> a(n),b(m);
    for (li& i:a) cin>>i;
    for (li& i:b) cin>>i;
    sort(a.begin(),a.end()),sort(b.begin(),b.end());
    a.erase(unique(a.begin(),a.end()),a.end()),b.erase(unique(b.begin(),b.end()),b.end());
    li l=0,r=4e9;
    while (l<r){
        li mid=(l+r)>>1;bool flag=true;
        size_t pos=0;
        for (li const& i:b){
            if (a[pos]+mid<i){flag=false;break;}
            while (pos<n&&a[pos]-mid<=i) ++pos;
            if (pos>=n) break;
        }
        if (pos<n) flag=false;
        flag?r=mid:l=mid+1;
    }
    cout<<l;
    return 0;
}