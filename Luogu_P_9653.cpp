#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,m,k;
        cin>>n>>m>>k;
        ui lst;size_t len=1;
        cin>>lst;
        size_t ans=0,cnt_two=0;
        for (size_t i=1;i<n;++i){
            ui now;
            cin>>now;
            if (lst==now) ++len;
            else{
                if (len==1) ++ans;
                if (len>1){
                    size_t lesser=min(m,(len-1)>>1);
                    m-=lesser;
                    ans+=(lesser<<1)+1;
                    cnt_two+=len&1^1;
                }
                len=1,lst=now;
            }
        }
        if (len==1) ++ans;
        if (len>1){
            size_t lesser=min(m,(len-1)>>1);
            m-=lesser;
            ans+=(lesser<<1)+1;
            cnt_two+=len&1^1;
        }
        if (m!=0) ans+=min(m,cnt_two),m-=min(m,cnt_two);
        cout<<ans<<'\n';
    }
    return 0;
}