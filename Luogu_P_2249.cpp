#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui n,m;
    cin>>n>>m;
    vector<ui> a(n);
    for (vector<ui>::reference i:a) cin>>i;
    while (m--){
        ui x;
        cin>>x;
        vector<ui>::iterator it=lower_bound(a.begin(),a.end(),x);
        cout<<(*it==x?it-a.begin()+1:-1)<<' ';
    }
    return 0;
}