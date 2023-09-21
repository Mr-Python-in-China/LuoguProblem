#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,m,q;
        cin>>n>>m>>q;
        vector<pair<size_t,ui>> colorh(n),colorl(m);
        for (size_t i=0;i<q;i++){
            char opt;size_t x;ui c;
            cin>>opt>>x>>c;
            ('1'-opt?colorh:colorl)[--x]={i,c};
        }
        for (size_t i=0;i<n;i++){
            for (size_t j=0;j<m;j++) cout<<max(colorh[i],colorl[j]).second<<' ';
            cout.put('\n');
        }
    }
    return 0;
}