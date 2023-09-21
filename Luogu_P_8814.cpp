#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
using lli=__int128_t;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        li n,d,e;
        cin>>n>>d>>e;
        li k=n-e*d+2;
        li a=-1,b=k,c=-n;
        li tetha=b*b-4*a*c;
        if (tetha<0) cout<<"NO\n";
        else{
            double sq=sqrt(tetha);
            double p=(-b+sq)/(2*a);
            double q=k-p;
            if (p>q) swap(p,q);
            if (lli(sq)*lli(sq)!=tetha||p<0) cout<<"NO\n";
            else{
                assert(!(li(round(p))*li(round(q))!=n||li(round(p))+li(round(q))!=k));
                cout<<li(round(p))<<' '<<li(round(q))<<'\n';
            }
        }
    }
    return 0;
}