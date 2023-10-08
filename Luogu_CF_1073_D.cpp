#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;uli t,ans=0;
    cin>>n>>t;
    list<ui> a(n);
    for (ui& i:a) cin>>i;
    while (!a.empty()){
        uli sum=0;
        for (ui const& i:a) sum+=i;
        ans+=t/sum*a.size(),t%=sum;
        for (list<ui>::iterator it=a.begin();it!=a.end();)
            if (*it<=t) t-=*(it++),++ans;
            else it=a.erase(it);
    }
    cout<<ans;
    return 0;
}