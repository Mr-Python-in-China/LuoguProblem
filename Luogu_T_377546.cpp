#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    li a,b,c;
    cin>>a>>b>>c;
    if (a+b==c) cout<<"plus";
    else if (a-b==c) cout<<"minus";
    else cout<<"illegal";
    return 0;
}