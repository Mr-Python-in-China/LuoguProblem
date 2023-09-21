#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int a,b;
    cin>>a>>b;
    if (a*b>0) cout<<max(abs(a),abs(b));
    else cout<<min(abs(a),abs(b))*2+max(abs(a),abs(b));
    return 0;
}