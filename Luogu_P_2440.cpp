#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using uli=unsigned long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;ui k;
    cin>>n>>k;
    vector<ui> a(n);
    ui l=0,r=0;
    for (vector<ui>::reference i:a) cin>>i,r=max(r,i);
    while (l<=r){
        ui mid=(l+r+1)>>1;
        cout<<l<<' '<<mid<<' '<<r<<'\n';
        if (mid==0) return cout.put(0),0;
        ui cxk=0;
        for (vector<ui>::reference i:a) cxk+=i/mid;
        if (cxk>=k) l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}