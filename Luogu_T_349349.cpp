#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n;bool flag=true;
        cin>>n;
        bitset<size_t(1e4+1)> s;
        for (size_t _i=0;_i<n;_i++){
            int x;
            cin>>x;
            size_t i=2;
            if (n!=2||flag) while (x>=i){
                if (x%i==0)
                    if (s[i]){flag=false;break;}
                    else x%=i,s.set(i);
                i++;
            }
        }
        label:;
        cout<<(n==2||flag?"Yes":"No")<<'\n';
    }
    return 0;
}