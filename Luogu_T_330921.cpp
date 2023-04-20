#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;ui lst;unsigned long long int len=1,ans=0;
    cin>>n>>lst;
    for (size_t i=1;i<n;i++){
        ui now;
        cin>>now;
        if (now>=lst) ans+=len*(len+1)>>1,len=0;
        len++,lst=now;
    }
    ans+=len*(len+1)>>1;
    cout<<ans;
    return 0;
}