#include<bits/stdc++.h>
using namespace std;
using usi=unsigned short int;
using ui=unsigned int;
using uc=unsigned char;
array<char,10> choice;
vector<array<char,10>> ans;
inline void dfs(usi n,uc deepth=0){
    if (deepth>=10){
        if (!n) ans.push_back(choice);
        return;
    }
    if (!n) return;
    uc maxn=min<usi>(3,n);
    for (uc i=1;i<=maxn;i++) 
        //cout<<int(deepth)<<':'<<int(i)<<'\n',
        choice[deepth]=i,dfs(n-i,deepth+1);
    return;
}
int main(void){
    //ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    usi n;
    cin>>n;
    dfs(n);
    cout<<ans.size()<<'\n';
    for (vector<array<char,10>>::reference i:ans){
        for (array<char,10>::reference j:i) cout<<int(j)<<' ';
        cout.put('\n');
    }
    return 0;
}