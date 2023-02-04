#include<bits/stdc++.h>
using namespace std;
using ui=unsigned int;
ui dfs(ui i,ui j,const ui& n){
	static vector<vector<ui>> res(n+1,vector<ui>(n+1));
	if (res[i][j]) return res[i][j];
	if (i==0) return res[i][j]=1;
	res[i][j]=dfs(i-1,j+1,n);
	if (j>0) res[i][j]+=dfs(i,j-1,n);
	return res[i][j];
}
int main(void){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	ui n;
	cin>>n;
	cout<<dfs(n,0,n);
	return 0;
}