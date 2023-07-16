#include<bits/extc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    long long int a,b,k,r,c;
    cin>>a>>b>>k>>r>>c;
    cout<<(b-a)*k*(r-c);
    return 0;
}