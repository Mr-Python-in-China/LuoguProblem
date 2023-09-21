#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t cnt1=0,cnt2=0,cnt3=0;
    for (unsigned char i=0;i<8;i++){
        char c;
        cin>>c;
        cnt1+=(bool)islower(c),
        cnt2+=(bool)isupper(c),
        cnt3+=(bool)isdigit(c);
    }
    cout<<cnt3<<' '<<cnt1<<' '<<cnt2;
    return 0;
}