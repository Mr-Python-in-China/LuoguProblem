#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
using usi=unsigned short int;
vector<bool> vis;
void dfs(ui m){
    static vector<ui> ans(1);
    //cout<<m<<';';
    if (m){
        for (ui i=ans.back()+1;i<=vis.size();i++) if (!vis[i-1]) 
            vis[i-1]=true,ans.push_back(i),dfs(m-1),ans.pop_back(),vis[i-1]=false;
    }else{
        for (vector<ui>::iterator it=ans.begin()+1;it<ans.end();it++) cout<<setw(3)<<*it;
        cout<<'\n';
    }
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    usi n,m;
    cin>>n>>m;
    vis.resize(n);
    dfs(m);
    return 0;
}