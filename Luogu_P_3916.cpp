#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using graph=vector<set<ui>>;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ui n,m;
    cin>>n>>m;
    graph mp(n);
    while (m--){
        ui u,v;
        cin>>u>>v;
        mp[--u].insert(--v);
    }
    for (graph::const_reference i:mp) 
        cout<<*i.end()+1<<' ';
    return 0;
}