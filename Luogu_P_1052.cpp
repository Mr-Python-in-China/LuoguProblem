#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui l,s,t;size_t m;
    cin>>l>>s>>t>>m;
    vector<ui> stone(m+1);
    for (size_t i=1;i<=m;i++) cin>>stone[i];
    vector<size_t> f(m+1,-1);f[0]=0;
    for (size_t i=0;i<=m;i++){
        size_t beg=lower_bound(stone.begin(),stone.end(),stone[i]+s)-stone.begin(),
               end=upper_bound(stone.begin(),stone.end(),stone[i]+t)-stone.begin();\
        for (size_t j=beg;j<end;j++) f[j]=min(f[j],f[i]+1);
    }
    size_t ans=-1;
    for (size_t i=0;i<=m;i++) if (stone[i]+t>=l) ans=min(ans,f[i]);
    cout<<ans-1;
    return 0;
}