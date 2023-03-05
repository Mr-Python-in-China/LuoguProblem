#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using usi=unsigned short int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    usi n;cin>>n;const usi MAXTRY=1<<n;
    vector<pair<ui,ui>> a(n);
    for (vector<pair<ui,ui>>::reference i:a) cin>>i.first>>i.second;
    ui ans=0x7fffffff;
    for (ui i=1;i<MAXTRY;i++){
        ui times=1,adds=0;
        for (ui p=0,choice=i;choice;p++,choice>>=1) 
            if (choice&1) times*=a[p].first,adds+=a[p].second;
        //cout<<times<<' '<<adds<<'\n';
        ans=min(ans,max(times,adds)-min(times,adds));
    }
    cout<<ans;
    return 0;
}