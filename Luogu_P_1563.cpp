#include<bits/stdc++.h>
using namespace std;
using ui = unsigned int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui n,m;
    cin>>n>>m;
    vector<pair<bool,string>> pr(n);
    for (vector<pair<bool,string>>::reference i:pr) cin>>i.first>>i.second;
    ui pos=0;
    while (m--){
        bool a;ui s;
        cin>>a>>s;
        if (!(a^pr[pos].first)) s=n-s;
        pos=(pos+s)%n;
    }
    cout<<pr[pos].second;
    return 0;
}