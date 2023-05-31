#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
const char F[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
size_t dfs(const vector<vector<ui>>& mp,vector<vector<bool>>& vis,size_t x,size_t y,const ui limit,const size_t& n){
    if (vis[x][y]) return 0;
    vis[x][y]=true;
    size_t res=1;
    for (unsigned char i=0;i<4;i++){
        size_t nx=x+F[i][0],ny=y+F[i][1];
        if (nx<n&&ny<n&&max(mp[x][y],mp[nx][ny])-min(mp[x][y],mp[nx][ny])<=limit)
            res+=dfs(mp,vis,nx,ny,limit,n);
    }
    return res;
}
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t n;ui l=-1,r=0;
    cin>>n;
    vector<vector<ui>> mp(n,vector<ui>(n));
    for (vector<ui>& i:mp) for (ui& j:i) cin>>j,l=min(j,l),r=max(j,r);
    while (l<r){
        ui mid=(l+r)>>1;
        size_t check=0;
        vector<vector<bool>> vis(n,vector<bool>(n));
        for (size_t i=0;i<n;i++) for (size_t j=0;j<n;j++)
            check=max(check,dfs(mp,vis,i,j,mid,n));
        (check>=((n*n+1)>>1)?r=mid:l=mid+1);
    }
    cout<<l;
    return 0;
}